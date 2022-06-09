#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;

int dx[]={0, -1, 0, 1};
int dy[]={-1, 0, 1, 0};

bool DFS(int x, int y, vector<vector<char>> & board, vector<vector<bool>> &vis, int idx, string word){
    if(idx==word.length()-1)
    {
        return true;
    }
    for(int k=0;k<4;k++) {
        int nx = x+dx[k];
        int ny = y+dy[k];
        if(nx>=0 && nx<board.size() && ny>=0 && ny<board[0].size() && !vis[nx][ny]){
            if(board[nx][ny]==word[idx+1]) {
                vis[nx][ny] = true;
                bool doesWordExist = DFS(nx, ny, board, vis, idx+1, word);
                if(doesWordExist)
                    return true;
                vis[nx][ny] = false;
            }
        }
    }
    return false;
}

bool isWordPresent(vector<vector<char>> & board, string word){
    int m = board.size();
    int n = board[0].size();
    vector<pair<int, int>> startPos;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++) {
            if(board[i][j]==word[0]){
                startPos.push_back({i,j});
            }
        }
    }
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    for(auto coor: startPos){
        int x = coor.first;
        int y = coor.second;
        vis[x][y] = true;
        if(DFS(x, y, board, vis, 0, word))
            return true;
        vis[x][y]  = false;
    }
    return false;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif
    int m, n;
    cin>>m>>n;
    vector<vector<char>> board(m, vector<char>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            cin>>board[i][j];
    }
    string word;
    cin>>word;
    cout<<isWordPresent(board, word);
    return 0;
}