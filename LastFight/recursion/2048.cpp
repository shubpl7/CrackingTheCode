#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;

map<int, string> intToString;

void fillMap() {
    intToString[0] = "zero";
    intToString[1] = "one";
    intToString[2] = "two";
    intToString[3] = "three";
    intToString[4] = "four";
    intToString[5] = "five";
    intToString[6] = "six";
    intToString[7] = "seven";
    intToString[8] = "eight";
    intToString[9] = "nine";
}

void ConverToString(int n){
    if(n==0)
        return;
    ConverToString(n/10);
    cout<<intToString[n%10]<<" ";
}

int ConvertToInt(string s, int i) {
    if(i==0) {
        return (s[i]-'0');
    }

    return ConvertToInt(s,i-1)*10 + (s[i]-'0');
}



int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../../input.txt","r",stdin);
    freopen("../../output.txt","w",stdout);
    #endif
    fillMap();
    int n = 783546;
    //ConverToString(n);
    string s = "789263";
    cout<<ConvertToInt(s,s.length()-1);
    return 0;
}