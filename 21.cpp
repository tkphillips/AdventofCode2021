#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string>
using namespace std;

int main () {
    int pos1 = 2;
    int pos2 = 5;
    int score1 = 0;
    int score2 = 0;
    int dice = 1;
    int rounds = 0;
    while(true){
        rounds += 3;
        pos1 += (3 * dice) + 3;
        if(pos1 >= 10){
            pos1 %= 10;
        }
        if(pos1 == 0){
            pos1 = 10;
        }
        score1 += pos1;
        dice += 3;
        if(score1 >= 1000){
            break;
        }
        rounds += 3;
        pos2 += (3 * dice) + 3;
        if(pos2 >= 10){
            pos2 %= 10;
        }
        if(pos2 == 0){
            pos2 = 10;
        }
        score2 += pos2;
        dice += 3;
        if(score2 >= 1000){
            break;
        }
    }
    cout << "Score 1: " << score1 << endl << "Score 2: " << score2 << endl << "Rolls: " << rounds << endl;
    if(score1 < score2){
        cout << score1 * rounds << endl;
    }else{
        cout << score2 * rounds << endl;
    }
    return 0;
}