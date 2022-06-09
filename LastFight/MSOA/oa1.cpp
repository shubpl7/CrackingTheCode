//Min Deletions To Obtain String in Right Format
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;
bool solution(vector<string> &B) {
    int N = B.size();
    int M = B[0].length();
    vector<vector<char>> grid(N, vector<char>(M));
    int AssassinX, AssassinY;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(B[i][j]=='A'){
                AssassinX = i;
                AssassinY = j;
            }
            else if(B[i][j]=='X')
        }
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
    
    return 0;
}