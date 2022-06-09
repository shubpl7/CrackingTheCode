#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;
vector<string> keypad{"","","ABC","DEF","GHI"};

void generate_seq( string in, string out, int idx) {
    if(idx==in.size())
        cout<<out<<endl;
    int curr_digit = in[idx]-'0';
    for(char x: keypad[curr_digit]) {
        generate_seq(in,out+x, idx+1);
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
    string in="23",out="";
    generate_seq(in, out, 0);
    return 0;
}