//
//  insertionSort.h
//  SortDemo
//
//  Created by Breezewish on 1/4/15.
//  Copyright (c) 2015 Wish. All rights reserved.
//

#ifndef SortDemo_insertionSort_h
#define SortDemo_insertionSort_h

#include <vector>
#include "util.h"

using namespace std;

void insertionSort(vector<int> data)
{
    int size = (int)data.size();
    int j;
    
    for (int i = 1; i < size; ++i) {
        int v = data[i];
        for (j = i - 1; j >= 0 && (_compare(), data[j] > v); --j) {
            _swapTimes++, data[j + 1] = data[j];
        }
        _swapTimes++, data[j + 1] = v;
    }
    
    _output(data);
}

#endif
