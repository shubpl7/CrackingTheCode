#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;
//   All permutations

void permute(int idx, string str){
    if(idx==str.length())
        cout<<str<<endl;
    for(int i=idx;i<str.length();i++) {
        swap(str[i], str[idx]);
        permute(idx+1, str);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif
    permute(0, "ABC");
    return 0;
}