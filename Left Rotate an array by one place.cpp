#include <bits/stdc++.h>

using namespace std;
// TC: O(n)
// SC: O(n)
void leftrotate1(vector<int> arr)
{
    int n = arr.size();
    vector<int> temp(n);
    int val = arr[0];
    for (int i = 1; i < n; ++i)
    {
        temp[i - 1] = arr[i];
    }
    temp[n - 1] = val;
    for (auto e : temp)
    {
        cout << e << " ";
    }
    cout << endl;
}


// TC: O(n)
// SC: O(1)
void leftrotate2(vector<int> arr)
{
    int n = arr.size();
    int val = arr[0];
    for (int i = 0; i < n - 1; ++i)
    {
        arr[i] = arr[i + 1];
    }
    arr[n - 1] = val;
    for (auto e : arr)
    {
        cout << e << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> vec = {1, 3, 3, 5, 6, 6, 7, 7, 7, 7, 7, 8, 9};
    leftrotate(vec);
    return 0;
}
