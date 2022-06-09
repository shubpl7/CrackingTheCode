#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;
int rows, cols;
vector<vector<char> > grid;
vector<vector<int> > sol;

bool ratInMaze(int i, int j)
{
    cout<<"RM: "<<i<<" "<<j<<endl;
    if (i == rows - 1 && j == cols - 1)
    {
        //answer exists
        sol[i][j] = 1;
        for (auto x : sol)
        {
            for (auto y : x)
                cout << y << " ";
            cout << endl;
        }
        cout << endl;
        return true;
    }
    if (i >= rows || j >= cols)
        return false;
    if (grid[i][j] == 'X')
        return false;

    sol[i][j] = 1;

    bool rightSuccess = ratInMaze(i, j + 1);
    bool downsuccess = false;
    if(rightSuccess==false)
        downsuccess= ratInMaze(i + 1, j);

    sol[i][j] = 0;
    if (rightSuccess || downsuccess)
        return true;
    return false;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    cin >> rows >> cols;
    grid.resize(rows, vector<char>(cols));
    sol.resize(rows, vector<int>(cols, 0));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cin >> grid[i][j];
    }
    bool res = ratInMaze(0, 0);
    if (res == false)
        cout << "No path exists\n";
    return 0;
}