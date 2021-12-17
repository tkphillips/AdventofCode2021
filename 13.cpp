#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>
#include <string>
#include <cstring>
using namespace std;

bool inBounds(int x, int y){
    if(x < 0 || y < 0){
        return false;
    }
    return true;
}

struct cord{
    int x;
    int y;
};

struct fold{
    string xy;
    int number;
};

int main() {
    ifstream myfile;
    vector<cord> input;
    vector<fold> folds;
    string line;
    const string delim = ",";
    const string delim2 = "=";
    //read in board
    myfile.open("input13.txt");
    if (myfile.is_open()){
        while (getline(myfile,line) && line != ""){
            size_t pos = 0;
            string token;
            struct cord temp;
            while ((pos = line.find(delim)) != string::npos) {
                token = line.substr(0, pos);
                temp.x = stoi(token);
                line.erase(0, pos + 1);
            }
            temp.y = stoi(line);
            input.push_back(temp);
        }
        while (getline(myfile,line)){
            size_t pos = 0;
            string token;
            struct fold temp;
            line.erase(0, 11);
            while ((pos = line.find(delim2)) != string::npos) {
                token = line.substr(0, pos);
                temp.xy = token;
                line.erase(0, pos + 1);
            }
            temp.number = stoi(line);
            folds.push_back(temp);
        }
        myfile.close();
    }

    //make matrix
    char field[2000][2000];
    for(int i = 0; i < 2000; i++){
        for(int j = 0; j < 2000; j++){
            field[i][j] = '.';
        }
    }
    for(int i = 0; i < input.size(); i++){
        field[input.at(i).x][input.at(i).y] = '#';
    }
    //Do fold 1
    int xLimit = 2000;
    int yLimit = 2000;
    if(folds.at(0).xy == "x"){
        int count = 0;
        for(int i = folds.at(0).number + 1; i < xLimit; i++){
            count++;
            for(int j = 0; j < yLimit; j++){
                if(field[i][j] == '#' && folds.at(0).number -(i-folds.at(0).number) >= 0){
                    field[folds.at(0).number -(i-folds.at(0).number)][j] = '#';
                }
            } 
        }
        xLimit = folds.at(0).number;
        folds.erase(folds.begin());
    }else{
        for(int i = folds.at(0).number + 1; i < yLimit; i++){
            for(int j = 0; j < xLimit; j++){
                if(field[j][i] == '#' && (folds.at(0).number - (i-folds.at(0).number)) >= 0){
                    field[j][folds.at(0).number - (i-folds.at(0).number)] = '#';
                }
            } 
        }
        yLimit = folds.at(0).number;
        folds.erase(folds.begin());
    }
    //count #'s
    int poundCount = 0;
    for(int i = 0; i < xLimit; i++){
        for(int j = 0; j < yLimit; j++){
            if(field[i][j] == '#'){
                poundCount++;
            }
        }
    }
    cout << poundCount << endl;
    while(!folds.empty()){
        if(folds.at(0).xy == "x"){
            for(int i = folds.at(0).number + 1; i < xLimit; i++){
                for(int j = 0; j < yLimit; j++){
                    if(field[i][j] == '#' && folds.at(0).number - (i - folds.at(0).number) >= 0){
                        field[folds.at(0).number -(i-folds.at(0).number)][j] = '#';
                    }
                } 
            }
            xLimit = folds.at(0).number;
            folds.erase(folds.begin());
        }else{
            for(int i = folds.at(0).number + 1; i < yLimit; i++){
                for(int j = 0; j < xLimit; j++){
                    if(field[j][i] == '#' && folds.at(0).number - (i - folds.at(0).number) >= 0){
                        field[j][folds.at(0).number - (i-folds.at(0).number)] = '#';
                    }
                } 
            }
            yLimit = folds.at(0).number;
            folds.erase(folds.begin());
        }
    }
    for(int i = 0; i < yLimit; i++){
        for(int j = 0; j < xLimit; j++){
            cout << field[j][i];
        }
        cout << endl;
    }
    return 0;
}