#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;
int hsb(int x)
{
    int i=0;
    while((1<<i)<=x)
    {
        i++;
    }
    return i-1;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int a = hsb(x);
        int curr=0;
        int j;
        for(j=0;j<=a;j++)
        {
            if((1<<j) & n)
            {
                curr+= (1<<j);
            }
            if(curr>x)
                break;
        }
        a=j-1;

        //cout<<"val of a is: "<<a<<endl;
        if(a==-1 && (n&1))
        {
            cout<<"-1\n";
        }
        else
        {
            int ans1 = 0;
            int i1=0;
            while((1<<i1)<=n)
            {
                if(i1>a)
                {
                    if((1<<i1) & n)
                    {
                        if(i1%2==0)
                            ans1+=2;
                        else 
                            ans1++;
                    }
                }
                i1++;
                //cout<<"ans : "<<ans<<endl;
            }
            if(x!=0)
                ans1++;
            

            a+=1;

            int ans2=0;
            int i2=0;
            while((1<<i2)<=n)
            {
                if(i2>a)
                {
                    if((1<<i2) & n)
                    {
                        if(i2%2==0)
                            ans2+=2;
                        else 
                            ans2++;
                    }
                }
                i2++;
                //cout<<"ans : "<<ans<<endl;
            }
            if(x!=0)
                ans2++;
            cout<<min(ans1,ans2)<<endl;
            //cout<<ans<<endl;
        }
    }
    return 0;
}