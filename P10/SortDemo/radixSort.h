//
//  radixSort.h
//  SortDemo
//
//  Created by Breezewish on 1/4/15.
//  Copyright (c) 2015 Wish. All rights reserved.
//

#ifndef SortDemo_radixSort_h
#define SortDemo_radixSort_h

#include <vector>
#include "util.h"

using namespace std;

const int RADIX = 10;

void radixSort(vector<int> data)
{
    int base = 1;
    while (true) {
        bool allZero = true;
        vector<int> bucket[RADIX];
        
        for (int i = 0; i < data.size(); ++i) {
            int v = (data[i] / base) % RADIX;
            if (v > 0) allZero = false;
            bucket[v].push_back(data[i]);
        }
        
        int c = 0;
        for (int i = 0; i < RADIX; ++i) {
            for (int j = 0; j < bucket[i].size(); ++j) {
                data[c++] = bucket[i][j];
            }
        }
        
        if (allZero) {
            break;
        } else {
            base *= RADIX;
        }
    }
    
    _output(data);
}

#endif
