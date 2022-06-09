#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;
void merge(int s,int e,int arr[]){
    
    int aux[e-s+1];
    int mid = (s+e)/2;
    int p=s,q=mid+1;
    int i=0;
    while(p<=mid && q<=e) {
        if(arr[p]<arr[q])
            aux[i++] = arr[p++];
        else if(arr[q]<arr[p]){
            aux[i++] = arr[q++];
        }
        else if(arr[p]==arr[q]){
            aux[i++] = arr[p++];
            aux[i++] = arr[q++];
        }
    }
    if(p==(mid+1)){
        while(q<=e){
            aux[i++] = arr[q++];
        }
    }
    if(q==e+1){
        while(p<=mid) {
            aux[i++]= arr[p++];
        }
    }
    for(int i=0;i<=e-s;i++)
        arr[i+s] = aux[i];
}
void mergesort(int s,int e,int arr[]) {
    cout<<"MergeSort: "<<s<<" "<<e<<endl;
    if(s==e)
        return;
    int mid = (s+e)/2;
    mergesort(s,mid,arr);
    mergesort(mid+1,e,arr);
    merge(s,e,arr);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif
    int arr[]={7,2,3,5,1,11,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    mergesort(0,n-1,arr);
    for(auto x:arr)
        cout<<x<<" ";
    return 0;
}