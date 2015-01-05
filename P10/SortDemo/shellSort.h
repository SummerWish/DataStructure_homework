//
//  shellSort.h
//  SortDemo
//
//  Created by Breezewish on 1/4/15.
//  Copyright (c) 2015 Wish. All rights reserved.
//

#ifndef SortDemo_shellSort_h
#define SortDemo_shellSort_h

#include <vector>
#include "util.h"

using namespace std;

void shellSort(vector<int> data)
{
    int size = (int)data.size();
    int j;
    
    for (int gap = size >> 1; gap >= 1; gap >>= 1) {
        for (int i = gap; i < size; ++i) {
            int v = data[i];
            for (j = i - gap; j >= 0 && (_compare(), data[j] > v); j -= gap) {
                _swapTimes++, data[j + gap] = data[j];
            }
            _swapTimes++, data[j + gap] = v;
        }
    }
    
    _output(data);
}

#endif
