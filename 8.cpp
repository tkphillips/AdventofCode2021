#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main() {
    ifstream myfile;
    string input[200][15];
    string line;
    string word;
    myfile.open("input8.txt");
    if(myfile.is_open()){
        int i = 0;
        while(getline(myfile,line)){
            int j = 0;
            stringstream s(line);
            while(s >> word){
                input[i][j] = word;
                j++;
            }
            i++;
        }
        myfile.close();
    }
    int count = 0;
    for(int i = 0; i < 200; i++){
        for(int j = 11; j < 15; j++){
            if(input[i][j].length() == 2 || input[i][j].length() == 3 || input[i][j].length() == 4 || input[i][j].length() == 7){
                count++;
            }
        }
    }
    cout << count << endl;
    //part 2
    int sum = 0;
    for(int i = 0; i < 200; i++){
        string decoded[10] = {""};
        vector<string> toDecode;
        for(int j = 0; j < 10; j++){
            toDecode.push_back(input[i][j]);
        }
        //find unique length digits => 1,4,7,8
        for(int n = 0; n < toDecode.size(); n++){
            if(toDecode[n].length() == 2){
                decoded[1] = toDecode[n];
                toDecode.erase(toDecode.begin() + n);
                n--;
            }
            if(toDecode[n].length() == 3){
                decoded[7] = toDecode[n];
                toDecode.erase(toDecode.begin() + n);
                n--;
            }
            if(toDecode[n].length() == 4){
                decoded[4] = toDecode[n];
                toDecode.erase(toDecode.begin() + n);
                n--;
            }
            if(toDecode[n].length() == 7){
                decoded[8] = toDecode[n];
                toDecode.erase(toDecode.begin() + n);
                n--;
            }
        }
        //find one with six digits that includes all the four digits => 9
        for(int n = 0; n < toDecode.size(); n++){
            bool found = true;
            if(toDecode[n].length() == 6){
                for(int j = 0; j < 4; j++){
                    if (toDecode[n].find(decoded[4][j]) == std::string::npos){
                        found = false;
                    }
                }
                if(found){
                    decoded[9] = toDecode[n];
                    toDecode.erase(toDecode.begin() + n);
                    break;
                } 
            }
        }
        //find one with six digits that includes all the one digits => 0
        for(int n = 0; n < toDecode.size(); n++){
            bool found = true;
            if(toDecode[n].length() == 6){
                for(int j = 0; j < 2; j++){
                    if (toDecode[n].find(decoded[1][j]) == std::string::npos){
                        found = false;
                    }
                }
                if(found){
                    decoded[0] = toDecode[n];
                    toDecode.erase(toDecode.begin() + n);
                    break;
                } 
            }
        }
        //last size 6
        for(int n = 0; n < toDecode.size(); n++){
            if(toDecode[n].length() == 6){
                decoded[6] = toDecode[n];
                toDecode.erase(toDecode.begin() + n);
                break;
            }
        }

        //find one with five digits and all of 1 => 3
        for(int n = 0; n < toDecode.size(); n++){
            bool found = true;
            if(toDecode[n].length() == 5){
                for(int j = 0; j < 2; j++){
                    if (toDecode[n].find(decoded[1][j]) == std::string::npos){
                        found = false;
                    }
                }
                if(found){
                    decoded[3] = toDecode[n];
                    toDecode.erase(toDecode.begin() + n);
                    break;
                } 
            }
        }
        //find one with five digits with only one segment differnent from 6 => 5
        for(int n = 0; n < toDecode.size(); n++){
            int notFoundCount = 0;
            if(toDecode[n].length() == 5){
                for(int j = 0; j < 6; j++){
                    if (toDecode[n].find(decoded[6][j]) == std::string::npos){
                        notFoundCount++;
                    }
                }
                if(notFoundCount == 1){
                    decoded[5] = toDecode[n];
                    toDecode.erase(toDecode.begin() + n);
                    break;
                } 
            }
        }
        //process of elimination => 2
        decoded[2] = toDecode.at(0);
        //cout << toDecode.size() << endl;
        toDecode.erase(toDecode.begin());

        for(int g = 0; g < 10; g++){
            cout << g << ": " << decoded[g] << endl;
        }
        //decode last 4
        int num[4] = {0};
        for(int n = 11; n < 15; n++){
            int numSum = 0;
            for(int v = 0; v < input[i][n].length(); v++){
                numSum += input[i][n][v];
            }
            for(int f = 0; f < 10; f++){
                int decodedSum = 0;
                for(int v = 0; v < decoded[f].length(); v++){
                    decodedSum += decoded[f][v];
                }
                if(numSum == decodedSum){
                    num[n-11] = f;
                    break;
                }
            }
        }
        int number;
        number = num[3] + (10 * num[2]) + (100 * num[1]) + (1000 * num[0]);
        cout << i + 1 << ": " << number << endl;
        sum += number;
    }
    cout << sum << endl;
    return 0;
}