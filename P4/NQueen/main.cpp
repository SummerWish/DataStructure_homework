//
//  main.cpp
//  NQueen
//
//  Created by Breezewish on 10/27/14.
//  Copyright (c) 2014 BW. All rights reserved.
//

#include <iostream>

using namespace std;

int n;
int result = 0;

int placeOrder[32];
int FULL_ROW;

// calculate the number of leading zero in x
inline int nlz(unsigned int x)
{
    if (x == 0) return 32;
    
    int n = 1;
    if ((x >> 16) == 0) {n = n +16; x = x <<16;}
    if ((x >> 24) == 0) {n = n + 8; x = x << 8;}
    if ((x >> 28) == 0) {n = n + 4; x = x << 4;}
    if ((x >> 30) == 0) {n = n + 2; x = x << 2;}
    n = n - (x >> 31);
    
    return n;
}

// rowBit: the column occupy status of the current row, 1 for occupied
// d1:     the occupy status of the current row in the main diagonal, 1 for occupied
// d2:     the occupy status of the current row in the counter diagonal, 1 for occupied
void solve(int rowBit, int d1, int d2, int row) {
    if (rowBit == FULL_ROW) {
        // all columns are occupied:
        // we found a solution!
        result++;
        
        // output solution
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j != placeOrder[i]) {
                    cout << "0 ";
                } else {
                    cout << "X ";
                }
            }
            cout << endl;
        }
        cout << endl;
    } else {
        // find an available position
        // !(rowBit | d1 | d2) = all available position are marked as 1
        // FULL_ROW & !(rowBit | d1 | d2) = all available position in length N are marked as 1
        int available_pos = FULL_ROW & ~(rowBit | d1 | d2);
        while (available_pos != 0) {
            // we get a set of available positions
            
            // get the least significent bit of 1, marked other bits as 0
            // for example:
            // 0011000 pos
            // 1101000 ~pos+1
            // ======= & ======
            // 0001000 pos_mask
            int pos_mask = available_pos & (~available_pos + 1);
            
            // we should record where to place the queen
            int pos = 31 - nlz(pos_mask);
            placeOrder[pos] = row;
            
            // occupy this position
            available_pos -= pos_mask;
            
            solve(rowBit | pos_mask,        // occupy this position in rowBit
                  (d1 | pos_mask) << 1,     // for diagonal positions, shift is required.
                  (d2 | pos_mask) >> 1,
                  row + 1);
        }
    }
}

int main(int argc, const char * argv[]) {

    cout << "Please input queen number N: ";
    cin >> n;
    
    // FULL_ROW = 11111 (n=5)
    FULL_ROW = (1 << n) - 1;
    
    solve(0, 0, 0, 0);
    
    cout << "Got " << result << " solutions." << endl;
}
