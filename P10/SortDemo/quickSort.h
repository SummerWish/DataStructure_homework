//
//  quickSort.h
//  SortDemo
//
//  Created by Breezewish on 1/4/15.
//  Copyright (c) 2015 Wish. All rights reserved.
//

#ifndef SortDemo_quickSort_h
#define SortDemo_quickSort_h

#include <vector>
#include "util.h"

using namespace std;

void _qs(vector<int>& d, int l, int r)
{
    int i = l, j = r, x = d[(i + r) >> 1];
    do {
        while (_compare(), d[i] < x) i++;
        while (_compare(), d[j] > x) j--;
        if (i <= j) {
            _swap(d[i], d[j]);
            i++; j--;
        }
    } while (i <= j);
    if (i < r) _qs(d, i, r);
    if (l < j) _qs(d, l, j);
}

void quickSort(vector<int> data)
{
    _qs(data, 0, (int)data.size() - 1);
    _output(data);
}

#endif
