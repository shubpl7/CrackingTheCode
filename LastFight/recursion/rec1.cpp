//rec function to check if array is sorted

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;
bool isSorted(int *arr, int st, int en)
{
    if (st == en)
        return true;
    if (arr[st] < arr[st + 1] && isSorted(arr, st + 1, en))
        return true;
    return false;
}
int isPresent(int *arr, int st, int en, int target)
{
    if (st > en)
        return -1;
    int mid = (st + en) / 2;
    if (arr[mid] == target)
        return mid + 1;
    else if (arr[mid] > target)
        return isPresent(arr, st, en - 1, target);
    else
        return isPresent(arr, st + 1, en, target);
}

int power(int a, int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return a;
    return a * power(a, n - 1);
}

int lastocc(int *arr, int n, int key)
{
    if (n == 0)
        return -1;

    int i = lastocc(arr + 1, n - 1, key);
    if (arr[0] == key && i == -1)
    {
        return 0;
    }
    else if (arr[0] != key && i == -1)
        return -1;
    return i + 1;
}

void allocc(int *arr, int i, int n, int key)
{
    if (i == n)
        return;
    if (arr[i] == key)
        cout << i << " ";
    allocc(arr, i + 1, n, key);
}

int firstocc(int *arr, int n, int key)
{
    if (n == 0)
        return -1;

    if (arr[0] == key)
        return 0;
    int i = firstocc(arr + 1, n - 1, key);
    if (i == -1)
        return -1;
    else
        return i + 1;
}

int fastpow(int a, int b, int &cnt)
{
    cnt++;
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    if (b & 1)
        return a * fastpow(a, b - 1, cnt);
    else
    {
        int temp = fastpow(a, b / 2, cnt);
        return temp * temp;
    }
}

void bubble_sort(int *arr, int i, int n)
{
    cout<<"bs "<<i<<" "<<n<<endl;
    if (n == 1)
        return;
    //
    if (i == n - 1)
    {
        return bubble_sort(arr, 0, n - 1);
    }

    if (arr[i] > arr[i + 1])
    {
        swap(arr[i], arr[i + 1]);
    }
    bubble_sort(arr, i + 1, n);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    int A[] = {7, 3, 11, 16, 20, 6};
    int cnt = 0;
    // cout<<fastpow(2,10,cnt);
    // cout<<endl<<cnt;

    int arr[] = {5, 4, 3, 2, 1};
    bubble_sort(arr, 0, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}