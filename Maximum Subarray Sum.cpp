#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define sz(v) (int)v.size()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

// TC: O(n2)
// SC: O(1)
int subarraysum1(vector<int> arr)
{
    int val = INT_MIN;
    int n = arr.size();
    for (int i = 0; i < n; ++i)
    {
        int sum = 0;
        for (int j = i; j < n; ++j)
        {
            sum += arr[j];
            val = max(val, sum);
        }
    }
    return val;
}

// TC: O(n)
// SC: O(1)
int subarraysum2(vector<int> arr)
{
    int val = INT_MIN, sum = 0, n = arr.size();
    for (int i = 0; i < n; ++i)
    {
        sum += arr[i];
        val = max(val, sum);
        if (sum < 0)
            sum = 0;
    }
    return val;
}

// TC: O(n)
// SC: O(1)
int printsubarraysum(vector<int> arr)
{
    int val = INT_MIN, sum = 0, n = arr.size();
    int start = -1, end = -1;
    for (int i = 0; i < n; ++i)
    {
        sum += arr[i];
        if (val < sum)
        {
            val = sum;
            end = i;
        }
        if (sum < 0)
        {
            start = i + 1;
            sum = 0;
        }
    }
    for (int i = start; i <= end; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int32_t main()
{
    vector<int> arr = {1, 1, 4, 6, -1, -5, 8, -99, 1, 3, 1, 3, 1, -7, 4, 0, 2};
    subarraysum(arr);
}
