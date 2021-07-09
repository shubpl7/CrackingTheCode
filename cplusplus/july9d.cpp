#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define MP make_pair
#define PB push_back
#define MOD 1000000007
#define fi first
#define se second
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;

class student{
       public:
              string name;
              int id;
              int marks;
              student(string s,int i,int m)
              {
                     name = s;id=i;marks=m;
              } 
              bool operator<(const student &s)const
              {
                     return name<s.name;
              }   
              bool operator==(const student &s)const{
                     return name == s.name;
              } 
};


bool mycomp(student &a,student &b)
{
       // if(a.marks>=b.marks)
       //        return true;
       // return false;

       return a.name>b.name;
}
int32_t main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("../input.txt","r",stdin);
       freopen("../output.txt","w",stdout);
       #endif
       student s1("shubham",3,20),s2("ayesha",1,15),s3("ravi",4,30),s4("harshil",5,24);
       set<student> myset;
       map<student,string> mp;
       mp.insert({s1,"tea"});
       mp[s2]="juice";
       mp[s3]="milk";
       mp[s4]="coffee";

       for(auto x:mp)
       {
              cout<<x.first.name<<"  "<<x.first.id<<"----->"<<x.second<<endl;
       }
       student p("harshil",11,50);
       auto it = mp.upper_bound(p);
       if(it!=mp.end())
       {
              cout<<it->first.name<<" "<<it->first.id<<" "<<it->first.marks<<endl;
              mp.erase(it);
       }
       else
              cout<<"NOT found\n";
       for(auto x:mp)
       {
              cout<<x.first.name<<"  "<<x.first.id<<"----->"<<x.second<<endl;
       }




       // vector<student> v;
       // v.PB(s1);
       // v.PB(s2);
       // v.PB(s3);
       // v.PB(s4);

       // for(auto x:v)
       // {
       //        cout<<x.name<<" "<<x.id<<" "<<x.marks<<endl;
       // }
       // cout<<endl;
       // sort(v.begin(),v.end(),mycomp);

       // for(auto x:v)
       // {
       //        cout<<x.name<<" "<<x.id<<" "<<x.marks<<endl;
       // }

       // VI v(n);
       // for(int i=0;i<n;i++)
       //        cin>>v[i];
       // sort(v.begin(),v.end(), mycomp);

       // for(auto x:v)
       //        cout<<x<<" ";
       return 0;
}