#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct line{
    int x1;
    int y1;
    int x2;
    int y2;
};

int main() {
    struct line Lines[500];
    ifstream myfile;
    string line;
    string delim1 = " -> ";
    string delim2 = ",";
    int count = 0;
    myfile.open("input5.txt");
    if (myfile.is_open()){
        while (getline(myfile,line)){
            size_t pos = 0;
            string token;
            //parse
            while ((pos = line.find(delim1)) != string::npos) {
                token = line.substr(0, pos);
                size_t pos1 = 0;
                string token1;
                //do it again
                while ((pos1 = token.find(delim2)) != string::npos) {
                    token1 = token.substr(0, pos1);
                    Lines[count].x1 = stoi(token1);
                    token.erase(0, pos1 + delim2.length());
                }
                Lines[count].y1 = stoi(token);
                line.erase(0, pos + delim1.length());
            }
            token = line.substr(0, pos);
            size_t pos1 = 0;
            string token1;
            while ((pos1 = token.find(delim2)) != string::npos) {
                    token1 = token.substr(0, pos1);
                    Lines[count].x2 = stoi(token1);
                    token.erase(0, pos1 + delim2.length());
                }
            Lines[count].y2 = stoi(token);
            count++;
        }
        myfile.close();
    }
    /*for(int i = 0; i < 500; i++){
        cout << Lines[i].x1 << "," << Lines[i].y1 << " -> " << Lines[i].x2 << "," << Lines[i].y2 << endl;
    }*/
    int playField[1000][1000] = {0};
    for(int i = 0; i < 500; i++){
        //vertical
        if(Lines[i].x1 == Lines[i].x2){
            if(Lines[i].y1 > Lines[i].y2){
                int y = Lines[i].y2;
                while(y <= Lines[i].y1){
                    playField[Lines[i].x1][y]++;
                    y++;
                }
            }else{
                int y = Lines[i].y1;
                while(y <= Lines[i].y2){
                    playField[Lines[i].x1][y]++;
                    y++;
                }
            }
        //horizontal
        }else if(Lines[i].y1 == Lines[i].y2){
             if(Lines[i].x1 > Lines[i].x2){
                int x = Lines[i].x2;
                while(x <= Lines[i].x1){
                    playField[x][Lines[i].y1]++;
                    x++;
                }
            }else{
                int x = Lines[i].x1;
                while(x <= Lines[i].x2){
                    playField[x][Lines[i].y2]++;
                    x++;
                }
            }
        //diagonal
        }
    }
    int sum = 0;
    for(int i = 0; i < 1000; i++){
        for(int k = 0; k < 1000; k++){
            if(playField[i][k] >= 2){
                sum++;
            }
        }
    }
    cout << sum << endl;
    return 0;
}