//
//  bubbleSort.h
//  SortDemo
//
//  Created by Breezewish on 1/4/15.
//  Copyright (c) 2015 Wish. All rights reserved.
//

#ifndef SortDemo_bubbleSort_h
#define SortDemo_bubbleSort_h

#include <vector>
#include "util.h"

using namespace std;

void bubbleSort(vector<int> data)
{
    int size = (int)data.size();
    
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - 1 - i; ++j) {
            if (_compare(), data[j] > data[j + 1]) {
                _swap(data[j], data[j + 1]);
            }
        }
    }
    
    _output(data);
}

#endif
