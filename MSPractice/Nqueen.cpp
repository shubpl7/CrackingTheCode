#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;
int n;
vector<vector<int> > board;
int nos=0;
void print() {
    for(auto x:board){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}

bool isSafe(int row, int col) {
    //all queens from 0.. col-1 are placed
    for(int i=0;i<col;i++) {
        if(board[row][i]) {
            return false;
        }
    }
    for(int i=row,j=col;i>=0 && j>=0;i--,j--) {
        if(board[i][j]){
            return false;
        }
            
    }
    for(int i=row,j=col;i<n && j>=0;i++,j--) {
        if(board[i][j]){
            return false;
        }
    }
    return true;

}

bool solveNQueenUtil(int col) {

    if(col == n) {
        //All Queens placed
        nos++;
        print();

        return true;
    }
    bool res=false;
    for(int i=0;i<n;i++) {
        //checking if placing Queen at board(i,col) is safe
        if(isSafe(i, col)) {
            cout<<"NQ -- "<<i<<" "<<col<<endl;
        
            board[i][col]=1;
            //recur for next instances
            res = solveNQueenUtil(col+1) || res;

            //undo the step so that we can test for other rows of the col th column
            board[i][col]=0;
        }
    }
    return res;
}



bool solveNQueen() {
    board.resize(n,VI(n,0));
    return solveNQueenUtil(0);
}


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif
    cin>>n;
    if(!solveNQueen()) {
        cout<<"No ways found!!";
    }
    cout<<nos;
    return 0;
}