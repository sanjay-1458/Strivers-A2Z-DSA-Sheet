#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define sz(v) (int)v.size()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

// TC: O(nlog(n))
// SC: O(1)
void Sort1(vector<int> arr, int target)
{
    sort(arr.begin(), arr.end());
    for (auto x : arr)
    {
        cout << x << " ";
    }
    cout << endl;
}

// TC: O(2n)
// SC: O(1)
void Sort2(vector<int> arr, int target)
{
    int n = arr.size();
    int zeros = 0, ones = 0, twos = 0;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] == 0)
        {
            zeros++;
        }
        else if (arr[i] == 1)
        {
            ones++;
        }
        else
        {
            twos++;
        }
    }
    int i = 0;
    while (zeros > 0)
    {
        arr[i] = 0;
        i++;
        zeros--;
    }
    while (ones > 0)
    {
        arr[i] = 1;
        i++;
        ones--;
    }
    while (twos > 0)
    {
        arr[i] = 2;
        i++;
        twos--;
    }
    for (auto x : arr)
    {
        cout << x << " ";
    }
    cout << endl;
}

// TC: O(n))
// SC: O(1)
void Sort3(vector<int> arr, int target)
{
    int n = arr.size();
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
    for (auto x : arr)
    {
        cout << x << " ";
    }
    cout << endl;
}

int32_t main()
{
    vector<int> arr = {1, 0, 2, 0, 1, 1, 1, 2, 2, 2, 0, 0, 1, 0, 2};
    Sort(arr);
}
