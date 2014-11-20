//
//  main.cpp
//  maze
//
//  Created by Breezewish on 11/14/14.
//  Copyright (c) 2014 BW. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int maze_width = 0;
int maze_height = 0;

class position {
public:
    int row;
    int col;
    position() {
        row = -1;
        col = -1;
    }
    position(int r, int c) {
        row = r;
        col = c;
    }
};

vector<string> map;
position pStart, pEnd;
vector<position> route;

bool find(int row, int col) {
    // visited
    if (map[row][col] != '0') {
        return false;
    }
    
    // bound overflow
    if (row < 0 || col < 0 || col >= maze_width || row >= maze_height) {
        return false;
    }
    
    // marked as visited
    map[row][col] = '*';
    
    // push to route
    route.push_back(position(row, col));
    
    // reach the end!
    if (row == pEnd.row && col == pEnd.col) {
        return true;
    }
    
    // find relations
    if (find(row-1, col)) return true;
    if (find(row+1, col)) return true;
    if (find(row, col-1)) return true;
    if (find(row, col+1)) return true;
    
    // pop route
    route.pop_back();
    
    // restore status
    map[row][col] = '0';
    
    return false;
}

int main(int argc, const char * argv[]) {

    // read file
    ifstream fin;
    fin.open("maze.txt");
    
    while (fin.good()) {
        string line;
        getline(fin, line);
        
        if (maze_width == 0) {
            maze_width = (int)line.size();
        } else {
            if (maze_width != (int)line.size()) {
                cout << "All rows of the maze should be the same size." << endl;
                return 1;
            }
        }
        
        map.push_back(line);
        maze_height++;
    }
    
    // the begin position is marked as "B"
    // the end position is marked as "E"
    // walls are marked as "#"
    // routes are marked as "0"
    
    // let's get the begin position and end position
    for (int i = 0; i < map.size(); ++i) {
        for (int j = 0; j < maze_width; ++j) {
            if (map[i][j] == 'B') {
                pStart.row = i;
                pStart.col = j;
                map[i][j] = '0';
            } else if (map[i][j] == 'E') {
                pEnd.row = i;
                pEnd.col = j;
                map[i][j] = '0';
            }
        }
    }
    
    // let's find a route from the begin position
    // using DFS algotirhm
    bool found = find(pStart.row, pStart.col);
    if (found) {
        // output the map
        // output header
        cout << "Map:" << endl;
        cout << "\t";
        for (int j = 0; j < maze_width; ++j) {
            cout << "C" << j << "\t";
        }
        cout << endl;
        // output body
        for (int i = 0; i < map.size(); ++i) {
            cout << "R" << i << "\t";
            for (int j = 0; j < maze_width; ++j) {
                cout << map[i].at(j) << "\t";
            }
            cout << endl;
        }
        
        // output route
        cout << endl << "Route:" << endl;
        for (int i = 0; i < route.size(); ++i) {
            cout << "(R" << route[i].row << ",C" << route[i].col << ")  ";
        }
        cout << endl;
    } else {
        cout << "Sorry, route not found." << endl;
    }

    return 0;
}
