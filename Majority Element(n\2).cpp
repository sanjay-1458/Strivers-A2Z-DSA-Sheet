#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define sz(v) (int)v.size()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

// TC: O(n2)
// SC: O(1)
int majority1(vector<int> arr)
{
    int val = -1;
    for (int i = 0; i < arr.size(); ++i)
    {
        int c = 0;
        for (int j = 0; j < arr.size(); ++j)
        {
            if (arr[i] == arr[j])
            {
                c++;
            }
        }
        if (c > (arr.size() / 2))
        {
            val = arr[i];
        }
    }
    return val;
}

// TC: O(nlog(n))
// SC: O(n)
int majority2(vector<int> arr)
{
    map<int, int> mp;
    for (int i = 0; i < arr.size(); ++i)
    {
        mp[arr[i]]++;
    }
    int val = -1;
    for (auto x : mp)
    {
        if (x.second > (arr.size() / 2))
        {
            val = x.first;
        }
    }
    return val;
}

// TC: O(nlog(n))
// SC: O(1)
int majority3(vector<int> arr)
{
    sort(arr.begin(), arr.end());
    int c = 1, c1 = 1, val = arr[0];
    for (int i = 1; i < arr.size(); ++i)
    {
        if (arr[i] == arr[i - 1])
        {
            c++;
        }
        else
        {
            c = 1;
        }
        if (c1 < c)
        {
            val = arr[i];
            c1 = c;
        }
    }
    if (c1 > (arr.size() / 2))
    {
        return val;
    }
    else
    {
        return -1;
    }
}

// TC: O(n)
// SC: O(1)
int majority4(vector<int> arr)
{
    int val, cnt = 0;
    for (int i = 0; i < arr.size(); ++i)
    {
        if (cnt == 0)
        {
            cnt = 1;
            val = arr[i];
        }
        else if (arr[i] == val)
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
    }
    int c = 0;
    for (int i = 0; i < arr.size(); ++i)
    {
        if (arr[i] == val)
        {
            c++;
        }
    }
    if (c > (arr.size() / 2))
    {
        return val;
    }
    else
    {
        return -1;
    }
}

int32_t main()
{
    vector<int> arr = {1, 0, 2, 0, 1, 1, 1, 2, 2, 2, 0, 0, 1, 0, 2};
    majority(arr);
}
