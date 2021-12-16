#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>
#include <string>
#include <cstring>
using namespace std;

int arrayDecoder(string x){
    if(x == "fw"){
        return 0;
    }
    if(x == "ll"){
        return 1;
    }
    if(x == "end"){
        return 2;
    }
    if(x == "dy"){
        return 3;
    }
    if(x == "tx"){
        return 4;
    }
    if(x == "tr"){
        return 5;
    }
    if(x == "jb"){
        return 6;
    }
    if(x == "ZD"){
        return 7;
    }
    if(x == "BL"){
        return 8;
    }
    if(x == "KX"){
        return 9;
    }
    if(x == "start"){
        return 10;
    }
    if(x == "yi"){
        return 11;
    }
    if(x == "nr"){
        return 12;
    }
    //this should never happen
    cout << "forgot one" << endl;
    return 0;
}

int main() {
    ifstream myfile;
    vector<string> input;
    string line;
    string delim = "-";
    string from[25];
    string to[25];
    //read in board
    myfile.open("input12.txt");
    if (myfile.is_open()){
        while (getline(myfile,line)){
            size_t pos = 0;
            string token;
            while ((pos = line.find(delim)) != string::npos) {
                token = line.substr(0, pos);
                input.push_back(token);
                line.erase(0, pos + 1);
            }
            input.push_back(line);
        }
        myfile.close();
    }
    //create from and to arrays
    for(int i = 0; i < input.size(); i += 2){
        from[i/2] = input.at(i);
        to[i/2] = input.at(i+1);
    }
    //create graph there are 13 nodes
    //Adjacency List
    bool adjList[13][13];
    for(int i = 0; i < 13; i++){
        for(int j = 0; j < 13; j++){
            adjList[i][j] = false;
        }
    }
    for(int i = 0; i < 25; i++){
        adjList[arrayDecoder(from[i])][arrayDecoder(to[i])] = true;
        adjList[arrayDecoder(to[i])][arrayDecoder(from[i])] = true;
    }
    for(int i = 0; i < 13; i++){
        for(int j = 0; j < 13; j++){
            cout << adjList[i][j] << " ";
        }
        cout << endl;
    }
    //find # of paths start->finish, can only visit lower case caves
    return 0;
}