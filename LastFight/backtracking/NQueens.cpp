#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;
vector<vector<int> > grid;
long RowMask=0, UpDiagMAsk=0, LowDiagMask=0;
// bool isSafe(int row, int col, int n){
//     for(int k = col-1;k>=0;k--)
//         if(grid[row][k])
//             return false;

//     for(int i=row+1,j = col-1;i<n && j>=0;i++, j--)
//         if(grid[i][j])
//             return false;
//     for(int i=row-1,j = col-1;i>=0 && j>=0;i--, j--)
//         if(grid[i][j])
//             return false;
//     return true;
// }
bool isSafe(int row, int col, int n) {
    if((RowMask & (1<<row)))
        return false;
    
    if((UpDiagMAsk & (1<<(n-(col-row+1)))))
        return false;
    
    if((LowDiagMask & (1<<(row+col))))
        return false;

    return true;
    
}

void setPos(int row, int col, int n) {
    grid[row][col] = 1;
    RowMask |= (1<<row);
    UpDiagMAsk |= (1<<(n-(col-row+1)));
    LowDiagMask |= (1<<(row+col));
}

void UnsetPos(int row, int col, int n) {
    grid[row][col] = 0;
    RowMask ^= (1<<row);
    UpDiagMAsk ^= (1<<(n-(col-row+1)));
    LowDiagMask ^= (1<<(row+col));
}
bool NQueen(int col, int n){
    if(col==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cout<<grid[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
        return false;
    }

    for(int row = 0;row<n; row++) {
        if(isSafe(row, col, n)){
            //place at {row, col}
            setPos(row, col, n);
            if(NQueen(col+1, n)) {
                //return true
                return true;
            }
            UnsetPos(row, col, n);

        }
    }
    return false;
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
    grid.resize(n, vector<int>(n, 0));
    bool res = NQueen(0,n);
    if(res==false)
        cout<<"Can't find Combination\n";
    return 0;
}