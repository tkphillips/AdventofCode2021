#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int main() {
    vector<int> measure;
    ifstream myfile;
    string line;
    myfile.open("input1.txt");
    if (myfile.is_open()){
        while (getline(myfile,line, '\n')){
            measure.push_back(stoi(line));
        }
        myfile.close();
    }
    int total = 0;
    for(int i = 1; i < measure.size(); i++){
        if(measure.at(i) > measure.at(i-1)){
            total++;
        }
    }
    cout << total << endl;
    queue<int> three;
    three.push_back(measure.at(0))
    three.push_back(measure.at(1))
    three.push_back(measure.at(2))
    int sum = measure.at(0) + measure.at(1) + measure.at(2)
    //Part 2 sliding window
    //make que of 3
    return 0;
}