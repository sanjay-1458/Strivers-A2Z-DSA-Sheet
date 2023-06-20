#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define sz(v) (int)v.size()

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

// TC: O(n2)
// SC: O(1)
void twosum1(vector<int> arr, int target)
{
    int n = arr.size();
    vector<int> temp(2);
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[i] + arr[j] == target)
            {
                temp[0] = i;
                temp[1] = j;
                break;
            }
        }
    }
    cout << temp[0] << " " << temp[1] << endl;
}

// TC: O(nlog(n))
// SC: O(n)
void twosum2(vector<int> arr, int target)
{
    int n = arr.size();
    map<int, int> mp;
    for (int i = 0; i < n; ++i)
    {
        mp[target - arr[i]] = i;
    }
    vector<int> temp(2);
    for (int i = 0; i < n; ++i)
    {
        if (mp.find(arr[i]) != mp.end())
        {
            if (i != mp[arr[i]])
            {
                temp[0] = i;
                temp[1] = mp[arr[i]];
                break;
            }
            else
            {
                continue;
            }
        }
    }
    cout << temp[0] << " " << temp[1] << endl;
}

// TC: O(nlog(n))
// SC: O(1)
void twosum3(vector<int> arr, int target)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int low = 0, high = n - 1;
    bool flag = false;
    while (low < high)
    {
        int sum = arr[low] + arr[high];
        if (sum == target)
        {
            flag = true;
            break;
        }
        else if (sum > target)
        {
            high--;
        }
        else
        {
            low++;
        }
    }
    cout << flag << endl;
}

int32_t main()
{
    vector<int> arr = {1, 2, 6, 5, 8, 11};
    twosum(arr, 14);
    return 0;
}
