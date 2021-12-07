#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string>
#include<sstream>
using namespace std;
//bingo number struct
struct bingoNum{
   int num = 0;
   bool called = false;
   
};
//bingo card struct
struct bingoCard{
    bingoNum card[5][5];
    int winNumber = 0;
};

int main () {
    string line;
    vector<int> calledNumbers;
    //create two arrays of bingo cards
    struct bingoCard Cards[100];
    struct bingoCard Cards2[100];
    ifstream myfile ("input4.txt");
    if (myfile.is_open()){
        //grab first line
        getline(myfile,line);
        stringstream s_stream(line);
        while(s_stream.good()) {
            string substr;
            getline(s_stream, substr, ',');
            calledNumbers.push_back(stoi(substr));
        }
        getline(myfile,line);
        //grab bingoo tables
        int k = 0;
        while(!myfile.eof()){
            for(int i = 0; i < 5; i++){
                getline(myfile,line);
                stringstream stream(line);
                for(int j = 0; j < 5; j++){
                    string substr;
                    getline(stream, substr, ' ');
                    //skip double spaces
                    if(substr != ""){
                        Cards[k].card[i][j].num = stoi(substr);
                    }else{
                        j--;
                    }     
                }
            }
            getline(myfile,line);
            k++;       
        }
        myfile.close();
    }
    //printout all cards for debugging
    for(int j = 0; j < 100; j++){
        for(int k = 0; k < 5; k++){
            for(int l = 0; l < 5; l++){
                cout << Cards[j].card[k][l].num << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    //make a copy of the card array
    for(int i = 0; i < 100; i++){
        Cards2[i] = Cards[i];
    }
    //play bingo
    //winning card
    int w;
    //last number played
    int lastNum;
    //for each number called
    for(int i = 0; i < calledNumbers.size(); i++){
        //for each card
        for(int j = 0; j < 100; j++){
            //search card for that number
            for(int k = 0; k < 5; k++){
                for(int l = 0; l < 5; l++){
                    if(Cards[j].card[k][l].num == calledNumbers.at(i)){
                        Cards[j].card[k][l].called = true;
                        //check if its a winner
                        bool win = true;
                        //check left and right
                        for(int m = 0; m < 5; m++){
                            if(!Cards[j].card[m][l].called){
                                win = false;
                            }
                        }
                        //if it is jump out of loop and remeber the number called and what card you are
                        if(win){
                            lastNum = calledNumbers.at(i);
                            w = j;
                            goto winnerFound;
                        }
                        //reset win for up and down
                        win = true;
                        //check up and down
                        for(int n = 0; n < 5; n++){
                            if(!Cards[j].card[k][n].called){
                                win = false;
                            }
                        }
                        //if it is jump out of loop and remeber the number called and what card you are
                        if(win){
                            lastNum = calledNumbers.at(i);
                            w = j;
                            goto winnerFound;
                        }
                    }
                }
            }
        }
    }

winnerFound:
    int sum;
    //sum all not called numbers
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(!Cards[w].card[i][j].called){
                sum += Cards[w].card[i][j].num;
            }
        }
    }
    //print answer
    cout << sum * lastNum << endl;
    //second game
    int winCount = 0;
    for(int i = 0; i < calledNumbers.size(); i++){
        //for each card
        for(int j = 0; j < 100; j++){
            //search card for that number
            for(int k = 0; k < 5; k++){
                for(int l = 0; l < 5; l++){
                    if(Cards[j].card[k][l].num == calledNumbers.at(i) && Cards[j].winNumber == 0){
                        Cards[j].card[k][l].called = true;
                        //check if its a winner
                        bool win = true;
                        for(int m = 0; m < 5; m++){
                            if(!Cards[j].card[m][l].called){
                                win = false;
                            }
                        }
                        //if its a winner mark it as such and remeber when it won
                        if(win){
                            lastNum = calledNumbers.at(i);
                            winCount++;
                            Cards[j].winNumber = winCount;
                        }
                        //reset win check
                        win = true;
                        for(int n = 0; n < 5; n++){
                            if(!Cards[j].card[k][n].called){
                                win = false;
                            }
                        }
                        //only do this if you didnt win on the left and right check
                        if(win && Cards[j].winNumber == 0){
                            lastNum = calledNumbers.at(i);
                            winCount++;
                            Cards[j].winNumber = winCount;
                        }
                    }
                }
            }
        }
    }
    //find the last card to win
    int last;
    for(int i = 0; i < 100; i++){
        if(Cards[i].winNumber == 100){
            last = i;
        }
    }
    //sum all the numbers not called
    sum = 0;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(!Cards[last].card[i][j].called){
                sum += Cards[last].card[i][j].num;
            }
        }
    }
    //print answer
    cout << sum * lastNum << endl;
    return 0;
}