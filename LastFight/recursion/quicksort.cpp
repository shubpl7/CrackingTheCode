#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;
int partition(vector<int> &v, int st, int en) {
    int pivot = en;
    int i=st-1, j=st;
    //i is the ending index of smaller than pivot elements
    //j is the current element
    for(;j<=en-1;j++) {
        if(v[j]<=v[pivot]){
            i++;
            swap(v[j],v[i]);
        }
    }
    swap(v[pivot], v[i+1]);
    return i+1;
}

void quicksort(vector<int> &v, int st, int en) {
    if(st>=en)
        return;
    int pivot = partition(v, st, en);
    quicksort(v, st, pivot-1);
    quicksort(v, pivot+1, en);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;
    quicksort(v, 0, n-1);
    for(auto x: v)
        cout<<x<<" ";
    return 0;
}