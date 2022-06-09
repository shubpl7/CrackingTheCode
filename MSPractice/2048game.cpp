#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;

class game {
    
    public:
        bool win;
        void ShiftUtilTop();
        void ShiftUtilBottom();
        void ShiftUtilLeft();
        void ShiftUtilRight();
        vector<vector<int> > mat;
        game() {
            win = false;
            mat.resize(4,VI(4,0));
            addTwoAtVacantRandomPosition();
            addTwoAtVacantRandomPosition();
        }
        void shift(int direction);
        void printMat();
        void addTwoAtVacantRandomPosition();
        bool isFull();
        bool evaluateGameStatus();

};

void game::printMat() {
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

void game::addTwoAtVacantRandomPosition() {
    if(isFull()) {
        win = false;
        return;
    }
    srand(time(0));
    vector<PII> vacant;
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            if(mat[i][j]==0) {
                vacant.push_back(make_pair(i,j));
            }
        }
    }
    int index  = rand()%(vacant.size());
    mat[vacant[index].first][vacant[index].second]=2;
    vacant.clear();
}

bool game::evaluateGameStatus() {
    if(isFull()) {
        return win;
    }
    return false;// false means game is not won yet
}

bool game::isFull() {
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            if(!mat[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void game::shift(int direction) {
    switch(direction) {
        case 0:
            ShiftUtilLeft();
            break;
        case 1:
            ShiftUtilRight();
            break;
        case 2:
            ShiftUtilTop();
            break;
        case 3:
            ShiftUtilBottom();
            break;
        default:
            cout<<"Invalid direction\n";
    }
}


void game::ShiftUtilTop() {
    for(int j=0;j<4;j++) {
        for(int i=3;i>0;i--) {
            if(mat[i][j]==0)
                continue;
            if(mat[i-1][j]==0){
                swap(mat[i][j], mat[i-1][j]);
            }
            else if(mat[i-1][j]==mat[i][j]) {
                mat[i][j]*=2;
            }
        }
    }
}

void game::ShiftUtilBottom() {
    for(int j=0;j<4;j++) {
        for(int i=0;i<3;i++) {
            if(mat[i][j]==0)
                continue;
            if(mat[i+1][j]==0){
                swap(mat[i][j], mat[i+1][j]);
            }
            else if(mat[i+1][j]==mat[i][j]) {
                mat[i][j]*=2;
            }
        }
    }
}

void game::ShiftUtilRight() {
    for(int i=0;i<4;i++) {
        for(int j=0;j<3;j++) {
            if(mat[i][j]==0)
                continue;
            if(mat[i][j+1]==0){
                swap(mat[i][j], mat[i][j+1]);
            }
            else if(mat[i][j+1]==mat[i][j]) {
                mat[i][j]*=2;
            }
        }
    }
}

void game::ShiftUtilLeft() {
    for(int i=0;i<4;i++) {
        for(int j=3;j>0;j--) {
            if(mat[i][j]==0)
                continue;
            if(mat[i][j-1]==0){
                swap(mat[i][j], mat[i][j-1]);
            }
            else if(mat[i][j-1]==mat[i][j]) {
                mat[i][j]*=2;
            }
        }
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
    cout<<"Entering the 2048 game\n";
    game g;
    while(!g.evaluateGameStatus()) {
        int dir;
        cout<<"Output matrix is : \n";
        g.printMat();
        cout<<"menu: \n";
        cout<<"0-->left\n1-->right\n2-->top\n3-->bottom\n-1-->exit\n";
        cout<<"Please enter your input: ";
        cin>>dir;
        if(dir==-1) {
            cout<<"User left the game";
            break;
        }
        g.shift(dir);
        
    }
    cout<<"matrix at last step is:\n";
    g.printMat();
    if(g.evaluateGameStatus()) {
        cout<<"2048 is found and you have won!!!\n";
    }
    else {
        cout<<" Matrix completely filled and you Lose!!!\n";
    }
    return 0;
}