#include <bits/stdc++.h>

using namespace std;

// TC: O(n)
// SC: O(n)
void duplicates1(vector<int> arr)
{
    int n = arr.size();
    vector<int> temp;
    for (int i = 0; i < n; ++i)
    {
        if (temp.empty() || temp.back() != arr[i])
        {
            temp.push_back(arr[i]);
        }
    }
    for (auto e : temp)
    {
        cout << e << " ";
    }
    cout << endl;
}

// TC: O(n)
// SC: O(1)
void duplicates2(vector<int> arr)
{
    int n = arr.size(), i = 0;
    for (int j = i + 1; j < n; ++j)
    {
        if (arr[i] != arr[j])
        {
            i++;
            arr[i] = arr[j];
        }
    }
    for (int j = 0; j <= i; ++j)
    {
        cout << arr[j] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> vec = {1, 3, 3, 5, 6, 6, 7, 7, 7, 7, 7, 8, 9};
    duplicates(vec);
    return 0;
}
