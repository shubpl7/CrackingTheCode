//-1 knapsack problem

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;
int knapsack(int * weights, int * prices, int N, int capacity) {
    cout<<"KP: "<<N<<" "<<capacity<<endl;
    if(N==0 || capacity==0)
        return 0;
    int inc = 0, exc =0;
    if(capacity>=weights[N-1]){
        inc = prices[N-1] + knapsack(weights, prices, N-1, capacity-weights[N-1]);
    }
    exc  = knapsack(weights, prices, N-1, capacity);
    return max(inc, exc);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt","r",stdin);
    freopen("../../output.txt","w",stdout);
    #endif
    int weights[] = {1, 2, 3, 5, 8, 2, 3};
    int prices[] = {40, 20, 30, 100, 75, 23, 90};

    int N = 7;
    int C = 10;
    cout<<knapsack(weights, prices, N, C);
    return 0;
}