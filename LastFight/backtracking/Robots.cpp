#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;
int dx[] = {-1, -1, -1};
int dy[] = {-1, 0, 1};
int h, w= 5;
vector<vector<int> > grid, gridCopy;
void ApplySuperPower(int row){
    for(int i=row-1;i>=max(0LL,row-5);i--) {
        for(int j=0;j<w;j++)
            if(gridCopy[i][j]==-1)
                grid[i][j]=0;
    }
}
void RemoveSuperPower(int row) {
    for(int i=row-1;i>=max(0LL,row-5);i--) {
        for(int j=0;j<w;j++)
            if(gridCopy[i][j]==-1)
                grid[i][j]=-1;
    }
}


int BT(bool CanApplySuperPower, int row, int col) {
	//cout<<"BT: "<<CanApplySuperPower<<" "<<row<<" "<<col<<endl;
    if(row<0 || col<0 || col>=w)
        return 0;
    
    int maxPower = 0;
    if(CanApplySuperPower) {
        //apply superPower from all cells starting from row+1, to row+5
        ApplySuperPower(row);
        for(int k=0;k<3;k++) {
            int nx  = row+dx[k];
            int ny = col+dy[k];
            if((nx>=0 && ny>=0 && ny<w)) {
                maxPower = max(maxPower, grid[nx][ny]+BT(false,nx,ny));
            }
        }
        RemoveSuperPower(row);
        for(int k=0;k<3;k++) {
            int nx  = row+dx[k];
            int ny = col+dy[k];
            if((nx>=0 && ny>=0 && ny<w)) {
                maxPower = max(maxPower, grid[nx][ny]+BT(true,nx,ny));
            }
        }
    }
    else{
        for(int k=0;k<3;k++) {
            int nx  = row+dx[k];
            int ny = col+dy[k];
            if((nx>=0 && ny>=0 && ny<w)) {
                maxPower = max(maxPower, grid[nx][ny]+BT(false,nx,ny));
            }
        }
    }
    return maxPower;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt","r",stdin);
    freopen("../../output.txt","w",stdout);
    #endif
    int t;
    cin>>t;
    while (t--)
    {
        cin>>h;
        grid.resize(h, vector<int>(w));
        gridCopy.resize(h, vector<int>(w));
        for(int i=0;i<h;i++) {
            for(int j=0;j<w;j++) {
                cin>>grid[i][j];
                gridCopy[i][j] = grid[i][j];
            }
        }
    }
    cout<<BT(true, h, 2);
    
    return 0;
}