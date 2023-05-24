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

// TC: O(k) + O(k) + O(n-2k) + O(n-k)
// SC: O(1)
void leftrotateD2(vector<int> arr, int k)
{
    int n = arr.size();
    k = k % n;
    for (int i = 0; i < k; ++i)
    {
        swap(arr[i], arr[n - k + i]);
    }
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.begin() + n - k);
    reverse(arr.begin(), arr.begin() + n - k);
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
