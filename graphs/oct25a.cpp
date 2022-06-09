#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;

int invest(int N,int D, vector<int> A)
{
    vector<int> lis(N,1);
    lis[0]=1;
    for(int i=1;i<N;i++)
    {
        int j=i-1;
        while(j>=0 && (i-j)<=D)
        {
            if(A[i]>A[j])
            {
                lis[i] = max(lis[i],lis[j]+1);
            }
            j--;
        }
    }
    return *max_element(lis.begin(),lis.end());
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    int d;
    cin>>d;
    vector<int> A(n);
    for(int i=0;i<n;i++)
        cin>>A[i];
    cout<<invest(n,d,A);
    return 0;
}