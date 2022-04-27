#include "dummyHead.h"
    int main()
    {
        map<int, int> m {{1,2}, {3,4}, {5,6}};
        auto it = m.lower_bound(2);
        cout << it->first << it->second << endl;
        return 0;
    }
