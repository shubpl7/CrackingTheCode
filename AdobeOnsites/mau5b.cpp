#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;


int findPivot(int low, int high, vector<int> &v) {
    if(low>high)
        return -1;
    int mid = low+(high-low)/2;
    if(v[mid]<v[mid-1] && v[mid]<v[mid+1])
        return mid;
    else if(v[mid]>v[mid-1] && v[mid]<=v[high])
        return findPivot(low, mid-1, v);
    return findPivot(mid+1, high, v);
}

int firstOcc(int low, int high, vector<int> &v, int key) {
    if(low>high)
        return -1;
    int mid = low + (high-low)/2;
    if(v[mid]==key && (mid==0 || v[mid-1]!=key))
        return mid;
    else if(v[mid]>=key)
        return firstOcc(low, mid-1, v, key);
    else
        return firstOcc(mid+1, high, v, key);
}

int lastOcc(int low, int high, vector<int> &v, int key) {
    if(low>high)
        return -1;
    int mid = low + (high-low)/2;
    if(v[mid]==key && (mid==(v.size()-1) || v[mid+1]!=key))
        return mid;
    else if(v[mid]<=key)
        return lastOcc(mid+1, high, v, key);
    else
        return lastOcc(low, mid-1, v, key);
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
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    // int key;
    // cin>>key;
    // int fo = firstOcc(0, n-1, v, key);
    // int lo = lastOcc(0, n-1, v, key);
    int pivot = findPivot(0, n-1, v);
    cout<<pivot;
    return 0;
}