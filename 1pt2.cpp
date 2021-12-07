#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main () {
    vector<int> input;
    string line;
    ifstream myfile ("input1.txt");
    if (myfile.is_open()){
        while(getline(myfile,line)){
            input.push_back(stoi(line));
        }
        myfile.close();
    }
    int sum = input.at(0) + input.at(1) + input.at(2);
    int numIncrease = 0;
    int temp;
    for(int i = 3; i < input.size(); i++){
        temp = input.at(i) + input.at(i-1) + input.at(i-2);
        if(temp > sum){
            numIncrease++;
        }
        sum = temp;
    }
    cout << numIncrease << endl;
    return 0;
}