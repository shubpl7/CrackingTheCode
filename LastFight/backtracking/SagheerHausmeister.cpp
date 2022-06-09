#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;
vector<string> grid;
vector<int> LSBfromLeft, LSBfromRight;
int n, m, ans;
void BT(string dir, int idx, int val) {
	//cout<<"BT "<<dir<<" "<<idx<<" "<<val<<endl;
    if(idx==0)
    {
        if(dir=="left") {
            ans = min(ans, val+LSBfromLeft[idx]);
        }
        else
            ans = min(ans, val+LSBfromRight[idx]);
        return;
    }
    if(dir=="left") {
        BT("left", idx-1, val+2*LSBfromLeft[idx]+1);
        BT("right", idx-1, val+m+2);
    }
    else{
        BT("right", idx-1, val+2*LSBfromRight[idx]+1);
        BT("left", idx-1, val+m+2);
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
    cin>>n>>m;
    grid.resize(n);
    for(auto & x: grid)
        cin>>x;
    string sample;
    for(int i=0;i<m+2;i++)
        sample+='0';
    bool flag= false;
    for(auto it = grid.begin();it!=grid.end();it++){
        if(*it==sample && flag==false){
            grid.erase(it);
        }
        else{
            flag = true;
            break;
        }
    }
    n = grid.size();
    LSBfromLeft.resize(n,-1);
    LSBfromRight.resize(n,-1);
    for(int i=0;i<n;i++) {
        for(int j=m+2;j>=0;j--) {
            if(grid[i][j]=='1'){
                LSBfromLeft[i] = j;
                break;
            }
        }
        for(int j=0;j<m+2;j++) {
            if(grid[i][j]=='1'){
                LSBfromRight[i] = m-j+1;
                break;
            }
        }
    }
    if(n==1){
        ans = min(2*LSBfromLeft[n-1],m+1);
        return ans;
    }
    ans = INT_MAX;
    BT("left", n-2, 2*LSBfromLeft[n-1]+1);
    BT("right", n-2, m+2);
    cout<<ans;
    return 0;
}