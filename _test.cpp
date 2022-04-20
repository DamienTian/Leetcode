#include "dummyHead.h"

int main()
{
    vector<int> n1 {0,1,2,3};
    n1.insert(n1.begin()+2, 4);
    printVectorInt(n1);

    return 0;
}
