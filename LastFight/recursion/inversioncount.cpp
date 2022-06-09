#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;

int merge(vector<int> &v, int st, int mid, int en) {
    int i=st,j=mid+1,k=st;
    int temp[1000];
    int crossInv = 0;
    while(i<=mid && j<=en) {
        if(v[i]>v[j]){
            crossInv += (mid-i+1);
            temp[k++] = v[j++];
        }
        else
            temp[k++] = v[i++];
    }
    while(i<=mid)
        temp[k++] = v[i++];
    while(j<=en)
        temp[k++] = v[j++];
    
    for(int i=st;i<=en;i++)
        v[i] = temp[i];
    return crossInv;
}

int inversions(vector<int> &v, int st, int en){
    if(st>=en)
        return 0;
    int mid = (st+en)/2;

    int left = inversions(v, st, mid);
    int right = inversions(v, mid+1, en);

    int crossInv = merge(v, st, mid, en);
    return left+right+crossInv;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt","r",stdin);
    freopen("../../output.txt","w",stdout);
    #endif
    
    int n;
    cin>>n;
    vector<int> v(n);
    for( auto &x: v)
        cin>>x;
    cout<<inversions(v,0,n-1);
    return 0;
}