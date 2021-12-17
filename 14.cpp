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
    for(int i = 0; i < 10; i++){
        //iterate through string
        string temp = chain;
        int insertCount = 1;
        for(int j = 0; j < chain.length() - 1; j++){
            string pair = chain.substr(j,2);
            for(int k = 0; k < input.size(); k++){
                //this isnt working
                if(pair == input.at(k).find){
                    temp.insert(j + insertCount, input.at(k).insert);
                    insertCount++;
                    break;
                }
            }
        }
        chain = temp;
    }
    //create frequency array;
    long letterCount[26];
    for(int i = 0; i < 26; i++){
        letterCount[i] = 0;
    }
    for(int i = 0; i < chain.size(); i++){
        letterCount[chain[i] - 65]++;
    }
    //find max and min values
    long max = 0;
    long min = LONG_MAX;
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