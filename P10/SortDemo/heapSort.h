//
//  heapSort.h
//  SortDemo
//
//  Created by Breezewish on 1/4/15.
//  Copyright (c) 2015 Wish. All rights reserved.
//

#ifndef SortDemo_heapSort_h
#define SortDemo_heapSort_h

#include <vector>
#include "util.h"

using namespace std;

void _heapify(vector<int>& d, int node, int size)
{
    int leftChild = (node << 1) + 1;
    int rightChild = leftChild + 1;
    
    int largest = node;
    if (leftChild < size && (_compare(), d[leftChild] > d[largest])) {
        largest = leftChild;
    }
    if (rightChild < size && (_compare(), d[rightChild] > d[largest])) {
        largest = rightChild;
    }
    if (largest != node) {
        _swap(d[largest], d[node]);
        _heapify(d, largest, size);
    }
}

void _buildHeap(vector<int>& d)
{
    for (int i = (int)(d.size() >> 1) - 1; i >= 0; --i) {
        _heapify(d, i, (int)d.size());
    }
}

void heapSort(vector<int> data)
{
    _buildHeap(data);
    for (int i = (int)data.size() - 1; i >= 0; --i) {
        _swap(data[0], data[i]);
        _heapify(data, 0, i);
    }
    
    _output(data);
}

#endif
