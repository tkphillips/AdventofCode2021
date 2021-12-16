#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int pointValue(char x){
    switch(x) {
        case ')':
            return 3;
        case ']':
            return 57;
        case '}':
            return 1197;
        case '>':
            return 25137;
    }
    //this should never happen
    return 0;
}

int main() {
    vector<string> input;
    ifstream myfile;
    string line;
    //read in board
    myfile.open("input10.txt");
    if (myfile.is_open()){
        while (getline(myfile,line)){
            input.push_back(line);
        }
        myfile.close();
    }
    int badSum = 0;
    vector<long long> sumList;
    for(int i = 0; i < input.size(); i++){
        stack<int> openers;
        bool broken = false;
        for(int j = 0; j < input.at(i).size(); j++){
            //if opener
            if(input.at(i)[j] == '(' || input.at(i)[j] == '{' || input.at(i)[j] == '[' || input.at(i)[j] == '<'){
                openers.push(input.at(i)[j]);
            }else{
                if(openers.top() == '(' && input.at(i)[j] != ')'){
                    badSum += pointValue(input.at(i)[j]);
                    cout << "Expected ), but found " << input.at(i)[j] << " instead." << endl;
                    broken = true;
                    break;
                }else if(openers.top() == '<' && input.at(i)[j] != '>'){
                    badSum += pointValue(input.at(i)[j]);
                    cout << "Expected >, but found " << input.at(i)[j] << " instead." << endl;
                    broken = true;
                    break;
                }else if(openers.top() == '{' && input.at(i)[j] != '}'){
                    badSum += pointValue(input.at(i)[j]);
                    cout << "Expected }, but found " << input.at(i)[j] << " instead." << endl;
                    broken = true;
                    break;
                }else if(openers.top() == '[' && input.at(i)[j] != ']'){
                    badSum += pointValue(input.at(i)[j]);
                    cout << "Expected ], but found " << input.at(i)[j] << " instead." << endl;
                    broken = true;
                    break;
                }else{
                    openers.pop();
                }
            }
        }
        //part 2
        //if incomplete
        if(!broken){
            //1:) 2:] 3:} 4:>
            long long sum = 0;
            while(!openers.empty()){
                sum *= 5;
                if(openers.top() == '('){
                    sum += 1;
                    openers.pop();
                }else if(openers.top() == '['){
                    sum += 2;
                    openers.pop();
                }else if(openers.top() == '{'){
                    sum += 3;
                    openers.pop();
                }else if(openers.top() == '<'){
                    sum += 4;
                    openers.pop();
                }else{
                    cout << "ERROR" << endl;
                }
            }
            sumList.push_back(sum);
        }
        broken = false;
    }
    cout << badSum << endl;
    sort(sumList.begin(), sumList.end());
    int middle = (sumList.size()/2);
    cout << sumList.at(middle) << endl;
    return 0;
}