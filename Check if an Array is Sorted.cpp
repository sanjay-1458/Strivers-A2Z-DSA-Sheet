#include <bits/stdc++.h>

using namespace std;

// TC: O(n2)
// SC: O(n)
void sorted1(vector<int> arr)
{
    int n = arr.size(), flag = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[i] > arr[j])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            break;
        }
    }
    if (flag == 1)
    {
        cout << "False" << endl;
    }
    else
    {
        cout << "True" << endl;
    }
}

// TC: O(n) + O(nlog(n)) + O(n)
// SC: O(n)
bool sorted2(vector<int> arr)
{
    vector<int> temp(arr.begin(), arr.end());
    sort(temp.begin(), temp.end());
    int n = arr.size(), flag = 0;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] != temp[i])
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        cout << "False" << endl;
    }
    else
    {
        cout << "True" << endl;
    }
}

// TC: O(n)
// SC: O(1)
void sorted3(vector<int> arr)
{
    int n = arr.size();
    int flag = 0;
    for (int i = 1; i < n; ++i)
    {
        if (arr[i] < arr[i - 1])
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        cout << "False" << endl;
    }
    else
    {
        cout << "True" << endl;
    }
}

int main()
{
    vector<int> vec = {1, 3, 3, 5, 6, 6, 7, 7, 7, 7, 7, 8, 9,};
    sorted1(vec);
    return 0;
}
