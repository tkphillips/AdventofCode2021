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
    return 0;
}