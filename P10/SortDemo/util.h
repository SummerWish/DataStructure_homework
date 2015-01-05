//
//  util.h
//  SortDemo
//
//  Created by Breezewish on 1/4/15.
//  Copyright (c) 2015 Wish. All rights reserved.
//

#ifndef SortDemo_util_h
#define SortDemo_util_h

#include <iostream>
#include <vector>

#ifdef WIN32
#include <windows.h>
#else
#include <sys/time.h>
#include <ctime>
#endif

using namespace std;

class Timer
{
private:
    int64_t getTimestampMS()
    {
#ifdef WIN32
        /* Windows */
        FILETIME ft;
        LARGE_INTEGER li;
        
        /* Get the amount of 100 nano seconds intervals elapsed since January 1, 1601 (UTC) and copy it
         * to a LARGE_INTEGER structure. */
        GetSystemTimeAsFileTime(&ft);
        li.LowPart = ft.dwLowDateTime;
        li.HighPart = ft.dwHighDateTime;
        
        uint64_t ret = li.QuadPart;
        ret -= 116444736000000000LL; /* Convert from file time to UNIX epoch time. */
        ret /= 10000; /* From 100 nano seconds (10^-7) to 1 millisecond (10^-3) intervals */
        
        return ret;
#else
        /* Linux */
        struct timeval tv;
        
        gettimeofday(&tv, NULL);
        
        int64_t ret = tv.tv_usec;
        /* Convert from micro seconds (10^-6) to milliseconds (10^-3) */
        ret /= 1000;
        
        /* Adds the seconds (10^0) after converting them to milliseconds (10^-3) */
        ret += (tv.tv_sec * 1000);
        
        return ret;
#endif
    }
    
    int64_t start;
    
public:
    Timer()
    {
        start = getTimestampMS();
    }
    
    long elapsed()
    {
        return getTimestampMS() - start;
    }
};

inline void _output(vector<int> data)
{
    return;
    
    for (int i = 0; i < data.size(); ++i) {
        cout << data[i] << " ";
    }
    cout << endl;
}

int _swapTimes;
int _compareTimes;

void _clearSwapCounter() {
    _swapTimes = 0;
}

void _clearCompareCounter() {
    _compareTimes = 0;
}

inline void _swap(int & a, int & b)
{
    int t = a;
    a = b;
    b = t;
    _swapTimes++;
}

inline void _compare() {
    _compareTimes++;
}

int _getSwapTimes() {
    return _swapTimes;
}

int _getCompareTimes() {
    return _compareTimes;
}

#endif
