#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main () {
    vector<int> input;
    string line;
    ifstream myfile ("input7.txt");
    if (myfile.is_open()){
        while(getline(myfile,line,',')){
            input.push_back(stoi(line));
        }
        myfile.close();
    }
    int min = INT_MAX;
    for(int x = 0; x < 1914; x++){
        int fuel = 0;
        for(int i = 0; i < input.size(); i++){
            for(int k = 0; k <= abs(x - input.at(i)); k++){
                fuel += k;
            }
            
        }
        if(fuel < min){
            min = fuel;
        }
    }
    cout << min << endl;
    return 0;
}