//
//  mergeSort.h
//  SortDemo
//
//  Created by Breezewish on 1/4/15.
//  Copyright (c) 2015 Wish. All rights reserved.
//

#ifndef SortDemo_mergeSort_h
#define SortDemo_mergeSort_h

#include <vector>
#include "util.h"

using namespace std;

void _merge(vector<int>& d, int begin, int end)
{
    if (begin == end) {
        return;
    }
    
    int middle = (begin + end) >> 1;
    _merge(d, begin, middle);
    _merge(d, middle + 1, end);
    
    vector<int> tmp;
    tmp.reserve(end - begin + 1);
    
    middle++;
    
    int i = begin, j = middle;
    while (i < middle && j <= end) {
        if (_compare(), d[i] < d[j]) {
            tmp.push_back(d[i++]);
        } else {
            tmp.push_back(d[j++]);
        }
    }
    
    while (i < middle) tmp.push_back(d[i++]);
    while (j <= end) tmp.push_back(d[j++]);
    
    for (int i = 0; i < tmp.size(); ++i) {
        d[begin + i] = tmp[i];
    }
}

void mergeSort(vector<int> data)
{
    _merge(data, 0, (int)data.size() - 1);
    _output(data);
}

#endif
