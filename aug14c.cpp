#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


class Student{
       public:
              int marks,age;
       Student(int m,int a)
       {
              marks=m;
              age=a;
       }
};
class myComp{
       public:
              bool operator()(const Student &s1,const Student &s2)
              {
                     if(s1.marks==s2.marks)
                            return s1.age<s2.age;
                     return s1.marks<s2.marks;

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
       priority_queue<Student,vector<Student>,myComp> pq;
       int n;
       cin>>n;
       for(int i=0;i<n;i++)
       {
              int marks,age;
              cin>>marks>>age;
              Student s1(marks,age);
              pq.push(s1);
       }
       while(!pq.empty())
       {
              cout<<pq.top().marks<<" "<<pq.top().age<<endl;
              pq.pop();
       }
       return 0;
}