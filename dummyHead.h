// This is a dummy head for Leetcode C++
#ifndef DUMMYHEAD_H_ 
#define DUMMYHEAD_H_ 

// C++
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <limits>
#include <functional>

// C
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <ctype.h>      /* tolower */

using namespace std;

// print vector<int>
void printVectorInt(vector<int> v){
    cout << "[";
    for(int i : v){
        cout << i << " ";
    }
    cout << "]" << endl;
}

// print matrix
void printMatrix2DInt(vector<vector<int>> m){
    cout << "[";
    for(int i = 0; i < m.size(); ++i){
        cout << "[";
        for(int j = 0; j < m[i].size(); ++j){
            if(j == m[i].size() - 1)
                cout << m[i][j];
            else
                cout << m[i][j] << ", ";
        }
        if(i == m.size() - 1)
            cout << "]";
        else
            cout << "]" << endl;
    }
    cout << "]" << endl;
}

#endif