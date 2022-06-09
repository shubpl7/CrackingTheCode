#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;


void ReplacePi(char * a, int i) {
    if(a[i]=='\0' || a[i+1]=='\0')
        return;
    
    if(a[i]=='p' && a[i+1]=='i') {
        int j=i+2;
        while(a[j]!='\0')
            j++;
        while(j>=i+2){
            a[j+2] = a[j];
            j--;
        }
        a[i] = '3';
        a[i+1] = '.';
        a[i+2] = '1';
        a[i+3] = '4';
        ReplacePi(a, i+4);
    }
    else
        ReplacePi(a, i+1);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt","r",stdin);
    freopen("../../output.txt","w",stdout);
    #endif
    char a[100];
    cin>>a;
    ReplacePi(a, 0);
    cout<<a;
    return 0;
}