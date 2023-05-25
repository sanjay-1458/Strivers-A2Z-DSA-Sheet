#include <bits/stdc++.h>

using namespace std;

// TC: O(n*k)
// SC: O(1)
void leftrotateD1(vector<int> arr, int k)
{
    int n = arr.size();
    k = k % n;
    for (int i = 0; i < k; ++i)
    {
        int val = arr[0];
        for (int j = 0; j < n - 1; ++j)
        {
            arr[j] = arr[j + 1];
        }
        arr[n - 1] = val;
    }
    for (auto e : arr)
    {
        cout << e << " ";
    }
    cout << endl;
}

// TC: O(k) + O(n-k) + O(n)
// SC: O(1)
void leftrotateD2(vector<int> arr, int k)
{
    int n = arr.size();
    k = k % n;
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
    reverse(arr.begin(), arr.end());
    for (auto e : arr)
    {
        cout << e << " ";
    }
    cout << endl;
}


int main()
{
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7};
    leftrotateD(vec, 2);
    return 0;
}
