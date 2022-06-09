#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;
void toh(int n, char st, char aux, char dest) {
    if(n){
        toh(n-1, st, dest, aux);
        cout<<"Move disk "<<n<<" from tower "<<st<<" to tower "<<dest<<endl;
        toh(n-1, aux, st, dest);
    }
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
    toh(n, 'A', 'B', 'C');
    return 0;
}