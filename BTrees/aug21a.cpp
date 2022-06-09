#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;

class apple{
    public:
        int size;
        int sv;
        apple(int x,int y)
        {
            this->size = x;
            this->sv = y;
        }
};


class shubh{
    public:
    bool operator()(const apple x,const apple y)
    {
        if(y.sv>x.sv)
            return true;
        else if(y.sv==x.sv)
            return y.size>x.size;
        return false;
    }
};
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif
    

    apple a1(10,32), a2(15,67), a3(20,56), a4(9,70), a5(25, 29), a6(30,56);


    priority_queue<apple, vector<apple>, shubh> pq;


    pq.push(a1);
    pq.push(a2);
    pq.push(a3);
    pq.push(a4);
    pq.push(a5);
    pq.push(a6);

    while(!pq.empty())
    {
        cout<<pq.top().size<<" "<<pq.top().sv<<endl;
        pq.pop();
    }
    return 0;
}