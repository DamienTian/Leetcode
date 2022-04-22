#include "dummyHead.h"

void removeStringsFast(std::vector<std::string> &items, std::function<bool(const std::string &)> predicate)
{
    int i = 0, j = items.size() - 1;
    while (i <= j)
    {
        if (predicate(items[i]))
            ++i;
        else
        {
            std::swap(items[i], items[j--]);
        }
    }
    items.resize(j + 1);
}
void removeStringsSlow(std::vector<std::string> &items, std::function<bool(const std::string &)> predicate)
{
    size_t index = 0;
    while (index < items.size())
    { // O(n)
        if (!predicate(items[index]))
            items.erase(items.begin() + index); // worst case O(n)
        else
            index++;
    }
}

    int main()
    {
        std::function<bool(const std::string &)> predicate = [](string s)
        {
            return s[0] == 'a' || s.back() == 's';
        };
        vector<string> testcases;

        ifstream in("_testcase.txt");
        string str;
        while (getline(in, str))
        {
            if (str.length() > 0)
                testcases.push_back(str);
        }
        //printVector(testcases);
        removeStringsFast(testcases, predicate);
        //removeStringsSlow(testcases, predicate);
        //printVector(testcases);

        cout << pow(3 - 2, 2) << endl;
        cout << pow(4 - 7, 2) << endl;
        cout << sqrt(pow(3 - 2, 2) + pow(4 - 7, 2)) << endl;

        return 0;
    }
