#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string>
using namespace std;

int main () {
    vector<string> input;
    string line;
    ifstream myfile ("input2.txt");
    if (myfile.is_open()){
        while(getline(myfile,line)){
            input.push_back(line);
        }
        myfile.close();
    }
    int depth = 0;
    int x = 0;
    int aim = 0;
    for(int i = 0; i < input.size(); i++){
        cout << input.at(i)[0] << (int)input.at(i)[input.at(i).size()-1] - 48 << endl;
        switch(input.at(i)[0]) {
            case 'u':
                aim -= input.at(i)[input.at(i).size()-1] - 48;
                break;
            case 'd':
                aim += input.at(i)[input.at(i).size()-1] - 48;
                break;
            case 'f':
                x += input.at(i)[input.at(i).size()-1] - 48;
                depth += (input.at(i)[input.at(i).size()-1] - 48) * aim;
                break;
        }
    }
    cout << depth << endl;
    cout << x << endl;
    cout << x * depth << endl;
    return 0;
}