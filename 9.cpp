#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct lowP{
    int x;
    int y;
};

int field[100][100] = {0};
bool counted[100][100];

bool inBounds(int x, int y){
    if(x > 99 || x < 0 || y > 99 || y < 0){
        return false;
    }
    return true;
}

int sizeBasin(int x, int y){
    int size = 0;
    if(field[x][y] == 9){
        counted[x][y] = true;
        return size;
    }
    size++;
    counted[x][y] = true;
    if(inBounds(x-1,y) && !counted[x-1][y]){
        size += sizeBasin(x-1, y);
    }
    if(inBounds(x+1,y) && !counted[x+1][y]){
        size += sizeBasin(x+1, y);
    }
    if(inBounds(x,y+1) && !counted[x][y+1]){
        size += sizeBasin(x, y+1);
    }
    if(inBounds(x,y-1) && !counted[x][y-1]){
        size += sizeBasin(x, y-1);
    }
    return size;
}

int main() {
    vector<lowP> lowPoints;
    ifstream myfile;
    string line;
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            counted[i][j] = false;
        }
    }
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
        struct lowP newItem;
        newItem.x = 0;
        newItem.y = 0;
        lowPoints.push_back(newItem);
        riskSum += field[0][0] + 1;
    }
    if(field[0][98] > field[0][99] && field[1][99] > field[0][99]){
        struct lowP newItem;
        newItem.x = 0;
        newItem.y = 99;
        lowPoints.push_back(newItem);
        riskSum += field[0][99] + 1;
    }
    if(field[98][0] > field[99][0] && field[99][1] > field[99][0]){
        struct lowP newItem;
        newItem.x = 99;
        newItem.y = 0;
        lowPoints.push_back(newItem);
        riskSum += field[99][0] + 1;
    }
    if(field[99][98] > field[99][99] && field[98][99] > field[99][99]){
        struct lowP newItem;
        newItem.x = 99;
        newItem.y = 99;
        lowPoints.push_back(newItem);
        riskSum += field[99][99] + 1;
    }
    //check edges
    for(int i = 1; i < 99; i++){
        //top
        if(field[i-1][0] > field[i][0] && field[i+1][0] > field[i][0] && field[i][1] > field[i][0]){
            struct lowP newItem;
            newItem.x = i;
            newItem.y = 0;
            lowPoints.push_back(newItem);
            riskSum += field[i][0] + 1;
        }
        //left
        if(field[0][i-1] > field[0][i] && field[0][i+1] > field[0][i] && field[1][i] > field[0][i]){
            struct lowP newItem;
            newItem.x = 0;
            newItem.y = i;
            lowPoints.push_back(newItem);
            riskSum += field[0][i] + 1;
        }
        //right
        if(field[99][i-1] > field[99][i] && field[99][i+1] > field[99][i] && field[98][i] > field[99][i]){
            struct lowP newItem;
            newItem.x = 99;
            newItem.y = i;
            lowPoints.push_back(newItem);
            riskSum += field[99][i] + 1;
        }
        //bottom
        if(field[i-1][99] > field[i][99] && field[i+1][99] > field[i][99] && field[i][98] > field[i][99]){
            struct lowP newItem;
            newItem.x = i;
            newItem.y = 99;
            lowPoints.push_back(newItem);
            riskSum += field[i][99] + 1;
        }
    }
    //middle
    for(int i = 1; i < 99; i++){
        for(int j = 1; j < 99; j++){
            if(field[i][j-1] > field[i][j] && field[i][j+1] > field[i][j] && field[i+1][j] > field[i][j] && field[i-1][j] > field[i][j]){
                struct lowP newItem;
                newItem.x = i;
                newItem.y = j;
                lowPoints.push_back(newItem);
                riskSum += field[i][j] + 1;
            }
        }
    }
    cout << riskSum << endl;
    vector<int> basinSize;
    //find 3 largest basins
    //basins are areas bounded by 9's and edges
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            if(!counted[i][j]){
                int temp = sizeBasin(i,j);
                basinSize.push_back(temp);
            }
        }
    }
    long largest[3] = {0};
    int temp = 0;
    int tempi = 0;
    for(int i = 0; i < basinSize.size(); i++){
        if(basinSize.at(i) > temp){
            temp = basinSize.at(i);
            tempi = i;
        }
    }
    largest[0] = temp;
    basinSize.erase(basinSize.begin() + tempi);
    temp = 0;
    tempi = 0;
    for(int i = 0; i < basinSize.size(); i++){
        if(basinSize.at(i) > temp){
            temp = basinSize.at(i);
            tempi = i;
        }
    }
    largest[1] = temp;
    basinSize.erase(basinSize.begin() + tempi);
    temp = 0;
    tempi = 0;
    for(int i = 0; i < basinSize.size(); i++){
        if(basinSize.at(i) > temp){
            temp = basinSize.at(i);
            tempi = i;
        }
    }
    largest[2] = temp;
    basinSize.erase(basinSize.begin() + tempi);
    cout << largest[0] * largest[1] * largest[2] << endl;
    return 0;
}