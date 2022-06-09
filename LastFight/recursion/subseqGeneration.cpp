#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;

void printSubseq(string input,int idx, string output) {
    if(idx == input.length()){
        cout<<output<<endl;
        return;
    }
    printSubseq(input, idx+1, input[idx]+output);
    printSubseq(input,idx+1,output);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt","r",stdin);
    freopen("../../output.txt","w",stdout);
    #endif
    string s;
    cin>>s;
    int n = s.length();

    string output ="";
    printSubseq(s,0,output);
    // for(int i=0;i<(1<<n);i++) {
    //     string ans="";
    //     for(int j=n-1;j>=0;j--){
    //         if( (i & (1<<j))){
    //             ans+=s[n-1-j];
    //         }
    //     }
    //     cout<<ans<<endl;
    // }
    return 0;
}