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
    myfile.open("input9.txt");
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
    int riskSum = 0;
    //solve for low points and calculate risk factor (h+1)
    //check corners
    if(field[0][1] > field[0][0] && field[1][0] > field[0][0]){
        riskSum += field[0][0] + 1;
    }
    if(field[0][98] > field[0][99] && field[1][99] > field[0][99]){
        riskSum += field[0][99] + 1;
    }
    if(field[98][0] > field[99][0] && field[99][1] > field[99][0]){
        riskSum += field[99][0] + 1;
    }
    if(field[99][98] > field[99][99] && field[98][99] > field[99][99]){
        riskSum += field[99][99] + 1;
    }
    //check edges
    for(int i = 1; i < 99; i++){
        //top
        if(field[i-1][0] > field[i][0] && field[i+1][0] > field[i][0] && field[i][1] > field[i][0]){
            riskSum += field[i][0] + 1;
        }
        //left
        if(field[0][i-1] > field[0][i] && field[0][i+1] > field[0][i] && field[1][i] > field[0][i]){
            riskSum += field[0][i] + 1;
        }
        //right
        if(field[99][i-1] > field[99][i] && field[99][i+1] > field[99][i] && field[98][i] > field[99][i]){
            riskSum += field[99][i] + 1;
        }
        //bottom
        if(field[i-1][99] > field[i][99] && field[i+1][99] > field[i][99] && field[i][98] > field[i][99]){
            riskSum += field[i][99] + 1;
        }
    }
    //middle
    for(int i = 1; i < 99; i++){
        for(int j = 1; j < 99; j++){
            if(field[i-1][j-1] > field[i][j] && field[i+1][j+1] > field[i][j] && field[i+1][j-1] > field[i][j] && field[i-1][j+1] > field[i][j]){
                riskSum += field[i][j] + 1;
            }
        }
    }
    cout << riskSum << endl;
    return 0;
}