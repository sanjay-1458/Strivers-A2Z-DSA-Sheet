#include <bits/stdc++.h>

using namespace std;

// TC: O(n2)
// SC: O(1)
void max1(vector<int> &arr)
{
    int n = arr.size();
    int maxi = -1;
    for (int i = 0; i < n; ++i)
    {
        int currmax = arr[i];
        bool flag = true;
        for (int j = 0; j < n; ++j)
        {
            if (currmax < arr[j])
            {
                flag = false;
            }
        }
        if (flag == true)
        {
            maxi = currmax;
            break;
        }
    }
    cout << maxi << endl;
}

// TC: O(nlog(n))
// SC: O(1)
void max2(vector<int> arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    cout << arr[n - 1] << endl;
}

// TC: O(n)
// SC: O(1)
void max3(vector<int> &arr)
{
    int n = arr.size();
    int maxi = arr[0];
    for (int i = 0; i < n; ++i)
    {
        if (maxi < arr[i])
        {
            maxi = arr[i];
        }
    }
    cout << maxi << endl;
}

int main()
{
    vector<int> vec = {1, 3, 2, 1, 8, 5, 8, 0, 1};
    max(vec);
    return 0;
}
