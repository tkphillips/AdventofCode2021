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

    return 0;
}