//
//  selectionSort.h
//  SortDemo
//
//  Created by Breezewish on 1/4/15.
//  Copyright (c) 2015 Wish. All rights reserved.
//

#ifndef SortDemo_selectionSort_h
#define SortDemo_selectionSort_h

#include <vector>
#include "util.h"

using namespace std;

void selectionSort(vector<int> data)
{
    int size = (int)data.size();
    
    for (int i = 0; i < size - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < size; ++j) {
            if (_compare(), data[j] < data[min]) {
                min = j;
            }
        }
        _swap(data[i], data[min]);
    }
    
    _output(data);
}

#endif
