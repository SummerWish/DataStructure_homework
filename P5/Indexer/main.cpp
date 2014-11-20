//
//  main.cpp
//  Indexer
//
//  Created by Breezewish on 11/20/14.
//  Copyright (c) 2014 BW. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    
    // part1. write file
    string fname;
    cout << "File name: ";
    getline(cin, fname);
    
    cout << "Please input the content, input -- to stop and save: " << endl;
    string line;
    string content;
    while (true) {
        getline(cin, line);
        if (line == "--") {
            break;
        } else {
            content += line + "\n";
        }
    }
    ofstream fout;
    fout.open(fname);
    fout << content << endl;
    fout.close();
    
    cout << "Successfully saved to: " << fname << endl;
    cout << endl;
    
    // part2. query
    string keyword;
    cout << "Input keyword: ";
    cin >> keyword;
    transform(keyword.begin(), keyword.end(), keyword.begin(), ::tolower);
    cout << "Showing content of " << fname << ":" << endl;
    cout << endl;
    cout << content << endl;
    cout << endl;
    
    int count = 0;
    
    string token = "";
    for (int i = 0; i < content.length(); ++i) {
        char ch = content[i];
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            token += ch;
        } else {
            transform(token.begin(), token.end(), token.begin(), ::tolower);
            if (token == keyword) {
                count++;
            }
            token = "";
        }
    }
    
    cout << "Found " << count << " occurrence." << endl;
    
    return 0;
}
