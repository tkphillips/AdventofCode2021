#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int field[100][100];
    ifstream myfile;
    string line;
    //read in board
    myfile.open("input10.txt");
    if (myfile.is_open()){
        int x = 0;
        while (getline(myfile,line)){
            for(int j = 0; j < 100; j++){
                field[j][x] = (int)line[j] - (int)'0';
            }
            x++;
        }
        myfile.close();
    }
    
    return 0;
}