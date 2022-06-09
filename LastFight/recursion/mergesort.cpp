#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;

void merge(vector<int> &arr, int st, int en, int mid)
{
    int i = st;
    int j = mid + 1;
    int k = st;
    vector<int> temp(100, 0);
    while (i <= mid && j <= en)
    {
        if (arr[i] < arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
            temp[k++] = arr[j++];
    }
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= en)
    {
        temp[k++] = arr[j++];
    }

    for (int i = st; i <= en; i++)
    {
        arr[i] = temp[i];
    }
}

void mergeSort(vector<int> &arr, int st, int en)
{
    if (st >= en)
        return;

    int mid = (st + en) / 2;
    mergeSort(arr, st, mid);
    mergeSort(arr, mid + 1, en);

    merge(arr, st, en, mid);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    vector<int> arr{ 5,4,3,2,1 };

    mergeSort(arr, 0, 5);
    return 0;
}