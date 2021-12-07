#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string>
using namespace std;

int main () {
    vector<int> input;
    string line;
    ifstream myfile ("input6.txt");
    if (myfile.is_open()){
        while(getline(myfile,line, ',')){
            input.push_back(stoi(line));
        }
        myfile.close();
    }
    int day = 0;
    cpp_int fish[9] = {0};
    //fill out fish array
    for(int i = 0; i < input.size(); i++){
        fish[input.at(i)]++;
    }
    
    while(day < 256){
        cpp_int temp = fish[8];
        cpp_int temp2;
        for(int i = 7; i >= 0; i--){
            temp2 = fish[i];
            fish[i] = temp;
            temp  = temp2;
        }
        fish[6] += temp;
        fish[8] = temp;
        day++;
        if(day == 80){
            cpp_int sum;
            for(int i = 0; i < 9; i++){
                sum += fish[i];
            }
            cout << sum << endl;
        }
    }
    cpp_int sum;
    for(int i = 0; i < 9; i++){
        sum += fish[i];
    }
    cout << sum << endl;

    //brute force 
    /*
    while(day < 256){
        int size = input.size();
        for(int i = 0; i < size; i++){
            if(input.at(i) == 0){
                input.at(i) = 6;
                input.push_back(8);
            }else{
                input.at(i)--;  
            }
        }
        day++;
        if(day == 80){
            cout << input.size() << endl;
        }
    }*/

    //cout << input.size() << endl;
    return 0;
}