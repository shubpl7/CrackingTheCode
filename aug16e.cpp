#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Student{
       public:
              string fname,lname;
              int id;
              Student(string f,string l,int i)
              {
                     fname=f;lname=l;id=i;
              }
              bool operator<(const Student &s)const{
                     return this->id<s.id;
              }
};
//Cracking the Code
int main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
       #endif
       Student s1("spoorthi","kumari",2),s2("amar","srivastava",19),s3("Aarav","verma",12),s4("shristi","agarwal",11);
       // multimap<Student,int> myMap;
       // myMap.insert({s1,100});
       // myMap.insert(make_pair(s2,99));
       // myMap.insert({s1,39});
       // myMap.insert({s3,99});
       // for(auto x:myMap)
       // {
       //        cout<<x.first.fname<<" "<<x.first.id<<" "<<x.second<<endl;
       // }
       set<Student> s;
       s.insert(s1);
       s.insert(s2);
       s.insert(s3);
       s.insert(s1);
       for(auto x:s)
       {
              cout<<x.fname<<" "<<x.id<<endl;
       }
       auto it=s.begin();
       advance(it,2);
       cout<<it->fname<<" @ "<<it->id;
}