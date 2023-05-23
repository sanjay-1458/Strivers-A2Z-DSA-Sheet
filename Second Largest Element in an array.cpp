#include <bits/stdc++.h>

using namespace std;

// TC: O(nlog(n)) + O(n)
// SC: O(1)
void secondlargest1(vector<int> arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int largest = arr[n - 1], i = n - 1;
    while (largest == arr[i])
    {
        i--;
    }
    cout << arr[i] << endl;
}

// TC: O(n) + O(n)
// SC: O(1)
void secondlargest2(vector<int> arr)
{
    int n = arr.size();
    int largest = arr[0];
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    int secondlargest = INT_MIN;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] < largest && arr[i] > secondlargest)
        {
            secondlargest = arr[i];
        }
    }
    cout << secondlargest << endl;
}

// TC: O(n)
// SC: O(1)
void secondlargest3(vector<int> &arr)
{
    int n = arr.size();
    int largest = arr[0];
    int secondlargest = INT_MIN;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] > largest)
        {
            secondlargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > secondlargest && arr[i] != largest)
        {
            secondlargest = arr[i];
        }
        else
        {
            continue;
        }
    }
    cout << secondlargest << endl;
}

int main()
{
    vector<int> vec = {1, 3, 2, 1, 8, 5, 8, 0, 1};
    secondlargest(vec);
    return 0;
}
