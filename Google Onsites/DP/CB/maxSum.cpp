#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;

int maxSumKadane(int * arr, int n) {
    int currSum = 0, max_so_far = 0;
    for(int i=0;i<n;i++) {
        currSum += arr[i];
        if(currSum<0)
            currSum = 0;
        max_so_far = max(max_so_far, currSum);
    }
    return max_so_far;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../../../input.txt","r",stdin);
    freopen("../../../output.txt","w",stdout);
    #endif
    int arr[] = {5,8, 11, -10, -11, -12, 3 , 20};
    cout<<maxSumKadane(arr, 8);
    return 0;
}