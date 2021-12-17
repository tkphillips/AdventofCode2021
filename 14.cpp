#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>
#include <string>
#include <cstring>
using namespace std;

struct step{
    string insert;
    string find;
};

int main() {
    ifstream myfile;
    vector<step> input;
    string chain;
    string line;
    string delim = " -> ";
    //read in board
    myfile.open("input14.txt");
    if (myfile.is_open()){
        getline(myfile,line);
        chain = line;
        getline(myfile,line);
        while (getline(myfile,line)){
            size_t pos = 0;
            string token;
            struct step temp;
            while ((pos = line.find(delim)) != string::npos) {
                token = line.substr(0, pos);
                temp.find = token;
                line.erase(0, pos + 4);
            }
            temp.insert = line;
            input.push_back(temp);
        }
        myfile.close();
    }
    //scan string and see what to insert where
    //scan original, insert in temp, original - temp;
    //do it 10 times
    for(int i = 0; i < 1; i++){
        //iterate through string
        string temp = chain;
        for(int j = 0; j < chain.length() - 1; j++){
            int insertCount = 1;
            string pair = chain.substr(j,2);
            for(int k = 0; k < input.size(); k++){
                //this isnt working
                if(pair == input.at(k).find){
                    cout << temp << " -> ";
                    temp.insert(j + insertCount, input.at(k).insert);
                    cout << temp << endl;
                    insertCount+=2;
                    break;
                }
            }
        }
        chain = temp;
    }
    //create frequency array;
    int letterCount[26];
    for(int i = 0; i < 26; i++){
        letterCount[i] = 0;
    }
    for(int i = 0; i < chain.size(); i++){
        letterCount[chain[i] - 65]++;
    }
    //find max and min values
    int max = 0;
    int min = INT_MAX;
    for(int i = 0; i < 26; i++){
        if(letterCount[i] > max){
            max = letterCount[i];
        }
        if(letterCount[i] < min && letterCount[i] != 0){
            min = letterCount[i];
        }
    }
    cout << max - min << endl;
    return 0;
}