//
//  main.cpp
//  LiveOrDie
//
//  Created by Breezewish on 11/20/14.
//  Copyright (c) 2014 BW. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int n;
    cout << "Number of players (N): ";
    cin >> n;
    
    int s;
    cout << "Start position (S): ";
    cin >> s;
    
    int m;
    cout << "Dead number (M): ";
    cin >> m;
    
    int k;
    cout << "Target remain (K): ";
    cin >> k;
    
    cout << endl;
    
    vector<int> next;
    next.reserve(n + 1);
    
    // initialize pointers
    for (int i = 1; i <= n; ++i) {
        next[i] = i + 1;
    }
    next[n] = 1;
    
    int remain = n;
    int deadcount = 0;
    int ct = 1;
    int last = s - 1;
    if (last == 0) {
        last = n;
    }
    
    int head = 1;
    
    while (remain > k) {
        // start looping
        if (ct == m) {
            ct = 0;
            // going to delete head: update head pointer
            if (next[last] == head) {
                head = next[s];
            }
            next[last] = next[s];
            remain--;
            deadcount++;
            cout << "Dead #" << deadcount << ": position = " << s << endl;
        }
        ct++;
        last = s;
        s = next[s];
    }
    
    cout << endl;
    cout << "Remaining: " << remain << endl;
    
    // start from head pointer
    s = head;
    do {
        cout << s << "\t";
        s = next[s];
    } while (s != head);
    cout << endl;
    
    return 0;
}
