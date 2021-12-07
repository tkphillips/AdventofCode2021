#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h> 
using namespace std;

int main() {
    vector<string> in;
    ifstream myfile;
    string line;
    myfile.open("input3.txt");
    if (myfile.is_open()){
        while (getline(myfile,line, '\n')){
            in.push_back(line);
        }
        myfile.close();
    }
    int bits[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
    for(int i = 0; i < in.size(); i++){
        for(int j = 0; j < 12; j++){
            if(in.at(i)[j] - 48 == 0){
                bits[j]--;
            }else{
                bits[j]++;
            }
        }
    }
    for(int j = 0; j < 12; j++){
        if(bits[j] > 0){
            bits[j] = 1;
        }else{
            bits[j] = 0;
        }
    }
    int invbits[12];
    for(int j = 0; j < 12; j++){
        if(bits[j] == 0){
            invbits[j] = 1;
        }else{
            invbits[j] = 0;
        }
    }
    for(int j = 0; j < 12; j++){
        cout << bits[j];
    }
    cout << endl;
    for(int j = 0; j < 12; j++){
        cout << invbits[j];
    }
    cout << endl;
    //convert to decimal and multiply
    long num1 = 0;
    long num2 = 0;
    for(int j = 0; j < 12; j++){
        num1 += bits[11-j] * pow(2,j);
        num2 += invbits[11-j] * pow(2,j);
    }
    cout << num1 << endl;
    cout << num2 << endl;
    cout << num1 * num2 << endl;
    return 0;
}