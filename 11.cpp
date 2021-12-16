#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct octo{
    int energy;
    bool flashed = false;
};

bool inBounds(int x, int y){
    if(x > 9 || x < 0 || y > 9 || y < 0){
        return false;
    }
    return true;
}

int main() {
    ifstream myfile;
    string line;
    octo field[10][10];
    //read in board
    myfile.open("input11.txt");
    if (myfile.is_open()){
        int x = 0;
        while (getline(myfile,line)){
            for(int j = 0; j < 10; j++){
                field[j][x].energy = (int)line[j] - (int)'0';
            }
            x++;
        }
        myfile.close();
    }
    //play game 
    int flashes = 0;
    int i = 0;
    while(true){
        //step 1 (increase all by 1)
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 10; k++){
                field[j][k].energy++;
            }
        }
        //step 2 (flash and increase all surrounding by 1) and repeat till no more flashes
        bool active = true;
        while(active){
            active = false;
            for(int j = 0; j < 10; j++){
                for(int k = 0; k < 10; k++){
                    int flashedCurr = 0;
                    if(field[j][k].energy > 9 && !field[j][k].flashed){
                        //flash
                        field[j][k].flashed = true;
                        active = true;
                        //increase surounding
                        if(inBounds(j-1,k)){
                            field[j-1][k].energy++;
                        }
                        if(inBounds(j-1,k-1)){
                            field[j-1][k-1].energy++;
                        }
                        if(inBounds(j,k-1)){
                            field[j][k-1].energy++;
                        }
                        if(inBounds(j+1,k-1)){
                            field[j+1][k-1].energy++;
                        }
                        if(inBounds(j-1,k+1)){
                            field[j-1][k+1].energy++;
                        }
                        if(inBounds(j+1,k+1)){
                            field[j+1][k+1].energy++;
                        }
                        if(inBounds(j+1,k)){
                            field[j+1][k].energy++;
                        }
                        if(inBounds(j,k+1)){
                            field[j][k+1].energy++;
                        }
                    }
                }
            }
        }
        //step 3 set all flashed to zero
        int zeroCount = 0;
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 10; k++){
                if(field[j][k].flashed){
                    if(i < 100){
                        flashes++;
                    }
                    field[j][k].flashed = false;
                    field[j][k].energy = 0;
                    zeroCount++;
                }
            }
        }
        if(zeroCount == 100){
            break;
        }
        i++;
    }
    cout << "Part 1: " << flashes << endl;
    cout << "Part 2: " << i + 1 << endl;
    return 0;
}