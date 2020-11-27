#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


//Cracking the Code
int main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
       #endif
       multiset<int> s;//1->2->4->6->10
       s.insert(4);s.insert(2);s.insert(1);s.insert(6);s.insert(10);
       s.insert(4);
       cout<<s.count(4);
       s.erase(4);
       cout<<endl<<s.count(4);
       return 0;
}