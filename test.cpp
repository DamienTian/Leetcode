#include "dummyHead.h"
#include "256.paint-house.cpp"

int main()
{
    Solution s;
    vector<vector<int>> sub;
    sub.resize(10, vector<int>(10, 0));
   
    char code = 'a';


    // Solution* ss = new Solution[10];

    int r = 0;
    int arr[5] = {2,4,6};
    int* p = arr;

    //r = p[2];
    // r = *(arr + *p);
    // r = *(arr + 2);
    // cout << r <<endl;

    for(int i = 1, j = 1; i < 2, j <= 4; ++i, ++j){
        cout << "i = " << i << "    j = " << j << endl; 
    }

    return 0;
}
