#include "dummyHead.h"

void e1()
{
    int a, b;
    cout << "Enter int a: ";
    cin >> a;
    cout << "Enter int b: ";
    cin >> b;
    int *ptrA = &a, *ptrB = &b;
    cout << "a = " << *ptrA << "    b = " << *ptrB << endl;
}

int *e2()
{
    int n;
    int i;
    int max = 0;
    cout << "Enter number of values:";
    cin >> n;

    cout << "Enter values in array:\n";
    // int arr[n];
    // int *ret = arr;
    int *arr = new int[n];
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int u = 0; u <= n; u++)
    {
        if (arr[u] > max)
            max = arr[u];
    }

    int *pointer = &max;

    cout << "Largest integer value in the array is " << *pointer << endl;
    return arr;
}

int main()
{
    char str[] = "A string.";
    char *pc = str;

    cout << str[0] << ' ' << *pc << ' ' << pc[3] << "\n";
    pc += 2;
    cout << *pc << ' ' << pc[2] << ' ' << pc[5];

    return 0;
}