#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> in;
    ifstream myfile;
    string line;
    myfile.open("input2.txt");
    if (myfile.is_open()){
        while (getline(myfile,line, '\n')){
            in.push_back(line);
        }
        myfile.close();
    }
    int x = 0;
    int depth = 0;
    for(int i = 0; i < in.size(); i++){
        cout << in.at(i)[0] << (int)in.at(i)[in.at(i).length()-2]-48 << endl;
        switch(in.at(i)[0]) {
            case 'u':
                depth -= (in.at(i)[in.at(i).length()-2] - 48);
                break;
            case 'd':
                depth += in.at(i)[in.at(i).length()-2] - 48;
                break;
            case 'f':
                x += in.at(i)[in.at(i).length()-2] - 48;
                break;
        }
        cout << depth << endl;
        cout << x << endl;
    }
    cout << depth <<  endl;
    cout << x << endl;
    cout << depth * x << endl;
    return 0;
}