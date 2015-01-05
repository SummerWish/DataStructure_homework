//
//  main.cpp
//  SortDemo
//
//  Created by Breezewish on 12/26/14.
//  Copyright (c) 2014 Wish. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include "util.h"
#include "bubbleSort.h"
#include "selectionSort.h"
#include "insertionSort.h"
#include "shellSort.h"
#include "quickSort.h"
#include "heapSort.h"
#include "mergeSort.h"
#include "radixSort.h"

using namespace std;

vector<int> data;

int main(int argc, const char * argv[]) {

    cout << "Sort Algorithm Comparison" << endl;
    cout << endl;
    cout << "Data size: ";
    
    int size;
    cin >> size;
    
    cout << endl;
    
    // generate random data
    srand((int)time(NULL));
    
    data.reserve(size);
    
    for (int i = 0; i < size; ++i) {
        data.push_back(rand() % 1000);
    }
    
    _output(data);
    
    for (int op = 1; op <= 8; ++op) {
        
        Timer t;
        _clearSwapCounter();
        _clearCompareCounter();
        
        switch(op) {
            case 1:
                cout << "Bubble Sort: " << endl;
                bubbleSort(data);
                break;
            case 2:
                cout << "Selection Sort: " << endl;
                selectionSort(data);
                break;
            case 3:
                cout << "Insertion Sort: " << endl;
                insertionSort(data);
                break;
            case 4:
                cout << "Shell Sort: " << endl;
                shellSort(data);
                break;
            case 5:
                cout << "Quick Sort: " << endl;
                quickSort(data);
                break;
            case 6:
                cout << "Heap Sort: " << endl;
                heapSort(data);
                break;
            case 7:
                cout << "Merge Sort: " << endl;
                mergeSort(data);
                break;
            case 8:
                cout << "Radix Sort: " << endl;
                radixSort(data);
                break;
        }
        
        cout << "Time elapsed: " << t.elapsed() << "ms" << endl;
        cout << "Swap times: " << _getSwapTimes() << endl;
        cout << "Compare times: " << _getCompareTimes() << endl;
        cout << endl;
    }
    
    return 0;
}
