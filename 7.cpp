#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string>
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
    int max = 0;
    for(int i = 0; i < input.size(); i++){
        if(input.at(i) > max){
            max = input.at(i);
        };
    }
    int min = 999999999;
    for(int x = 0; x < 1914; x++){
        int fuel = 0;
        for(int i = 0; i < input.size(); i++){
            fuel += abs(x - input.at(i));
        }
        if(fuel < min){
            min = fuel;
        }
    }
    cout << min << endl;
    return 0;
}