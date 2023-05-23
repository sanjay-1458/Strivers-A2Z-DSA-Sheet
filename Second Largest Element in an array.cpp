#include <bits/stdc++.h>

using namespace std;

// TC: O(nlog(n)) + O(n)
// SC: O(1)
void smax1(vector<int> arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int maxi = arr[n - 1], i = n - 1;
    while (maxi == arr[i])
    {
        i--;
    }
    cout << arr[i] << endl;
}

// TC: O(n) + O(n)
// SC: O(1)
void smax2(vector<int> arr)
{
    int n = arr.size();
    int maxi = arr[0];
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] > maxi)
        {
            maxi = arr[i];
        }
    }
    int smax = INT_MIN;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] < maxi && arr[i] > smax)
        {
            smax = arr[i];
        }
    }
    cout << smax << endl;
}

// TC: O(n)
// SC: O(1)
void smax3(vector<int> &arr)
{
    int n = arr.size();
    int maxi = arr[0];
    int smax = INT_MIN;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] > maxi)
        {
            smax = maxi;
            maxi = arr[i];
        }
        else if (arr[i] > smax && arr[i] != maxi)
        {
            smax = arr[i];
        }
        else
        {
            continue;
        }
    }
    cout << smax << endl;
}

int main()
{
    vector<int> vec = {1, 3, 2, 1, 8, 5, 8, 0, 1};
    smax(vec);
    return 0;
}
