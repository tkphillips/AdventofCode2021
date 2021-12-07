#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int main () {
    vector<string> input;
    string line;
    ifstream myfile ("input3.txt");
    if (myfile.is_open()){
        while(getline(myfile,line)){
            input.push_back(line);
        }
        myfile.close();
    }
    vector<string> temp = input;
    int bitNum = 0;
    while(temp.size() != 1){
        int test = 0;
        for(int i = 0; i < temp.size(); i++){
            if(temp.at(i)[bitNum] == '1'){
                test++;
            }else{
                test--;
            }
        }
        if(test >= 0){
            for(int i = 0; i < temp.size();){
                if(temp.at(i)[bitNum] == '0'){
                    temp.erase(temp.begin()+i);
                    if(temp.size() == 1){
                        break;
                    }
                }else{
                    i++;
                }
            }
        }else{
            for(int i = 0; i < temp.size();){
                if(temp.at(i)[bitNum] == '1'){
                    temp.erase(temp.begin()+i);
                    if(temp.size() == 1){
                        break;
                    }
                }else{
                    i++;
                }
            }
        }
        if(bitNum == 11){
            bitNum = 0;
        }else{
            bitNum++;
        }
    }
    string bit1 = temp.at(0);
    cout << temp.at(0) << endl;
    temp = input;
    bitNum = 0;
    while(temp.size() != 1){
        int test = 0;
        for(int i = 0; i < temp.size(); i++){
            if(temp.at(i)[bitNum] == '1'){
                test++;
            }else{
                test--;
            }
        }
        if(test >= 0){
            for(int i = 0; i < temp.size();){
                if(temp.at(i)[bitNum] == '1'){
                    temp.erase(temp.begin()+i);
                    if(temp.size() == 1){
                        break;
                    }
                }else{
                    i++;
                }
            }
        }else{
            for(int i = 0; i < temp.size();){
                if(temp.at(i)[bitNum] == '0'){
                    temp.erase(temp.begin()+i);
                    if(temp.size() == 1){
                        break;
                    }
                }else{
                    i++;
                }
            }
        }
        if(bitNum == 11){
            bitNum = 0;
        }else{
            bitNum++;
        }
    }
    string bit2 = temp.at(0);
    cout << temp.at(0) << endl;
    int num1 = 0;
    int num2 = 0;
    for(int i = 0; i < 12; i++){
        num1 += (bit1[11 - i] - 48) * pow(2, i);
        num2 += (bit2[11 - i] - 48) * pow(2, i);
    }
    cout << num1 << endl;
    cout << num2 << endl;
    cout << num1 * num2 << endl;
    return 0;
}