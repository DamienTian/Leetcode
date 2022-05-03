#include "dummyHead.h"
#include "256.paint-house.cpp"

int main()
{
    Solution s;
    vector<vector<int>> sub {{17,2,17},
                            {16,16,5},
                            {14,3,19}};
    cout << s.minCost(sub) << endl;

    return 0;
}
