#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <stack>
using namespace std;

struct instruct{
    bool on;
    pair<int, int> x;
    pair<int, int> y;
    pair<int, int> z;
};


void move(bool on, int x1, int x2, int y1, int y2, int z1, int z2){
    //turn on or off points

}

int main() {
    vector<instruct> input;
    ifstream myfile;
    string line;
    //read in board
    myfile.open("input22.txt");
    if (myfile.is_open()){
        while (getline(myfile,line)){
            char * cline = new char [line.length()+1];
            strcpy (cline, line.c_str());
            instruct temp;
            char onoff[3] = "";
            sscanf(cline, "%s x=%d..%d,y=%d..%d,z=%d..%d", onoff, &temp.x.first, &temp.x.second, &temp.y.first, &temp.y.second, &temp.z.first, &temp.z.second);
            if(onoff == "on"){
                temp.on = true;
            }else{
                temp.on = false;
            }
            input.push_back(temp);
        }
        myfile.close();
    }

    for(int i = 0; i < input.size(); i++){
        move(input.at(i).on, input.at(i).x.first, input.at(i).x.second, input.at(i).y.first, input.at(i).y.second, input.at(i).z.first, input.at(i).z.second);
    }
    return 0;
}