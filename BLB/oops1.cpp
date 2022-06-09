#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;
class Account{
public:
    Account(double b): balance(b){}
    Account (double b, std::string c): balance(b), cur(c){} 
private:
    double balance;
    std::string cur;
};


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif
    // Account account = 100.0; // ERROR: implicit conversion
Account account2(100.0); // OK: explicit invocation
// Account account1 = {100.0,"EUR"}; // OK: implicit conversion
    return 0;
}