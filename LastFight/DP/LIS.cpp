#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;
int longestSubsequence(int n, int a[])
    {
       // your code here
       int lis[n];
       lis[0] = 1;
       for(int i=1;i<n;i++) {
           lis[i] = 1;
           for(int j=i-1;j>=0;j--) {
               if(a[j]<a[i]) {
                   lis[i] = max(lis[i], 1+lis[j]);
               }
           }
       }
       int ans=0;
       for(int i=0;i<n;i++) {
           //cout<<lis[i]<<" ";
           ans = max(ans, lis[i]);
       }
       return ans;
    }

int FindCeil(int * tail, int low, int high, int target) {
        while(low<high) {
            int mid = low+(high-low)/2;
            if(tail[mid]<target) {
                low = mid+1;
            }
            else{
                high = mid;
            }
        }
        return low;
    }
    int longestSubsequence(int n, int a[])
    {
       // your code here
       //n logn
       int tail[n];
       tail[0] = a[0];
       int len = 1;
       for(int i=1;i<n;i++) {
           if(a[i]>tail[len-1]){
               tail[len++] = a[i];
           }
           else{
               int idx = FindCeil(tail, 0, len-1, a[i]);
               tail[idx] = a[i];
           }
       }
       return len;
    }

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt","r",stdin);
    freopen("../../output.txt","w",stdout);
    #endif
    
    return 0;
}