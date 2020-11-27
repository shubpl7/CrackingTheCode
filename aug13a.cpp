#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Student{
       public:
       string name;
       int marks;
       Student(string str,int m)
       {
              name=str;
              marks=m;
       }
};

class comp{
       public:
       bool operator()(Student s1,Student s2)
       {
              if(s1.marks<s2.marks)
                     return true;
              else if(s1.marks>s2.marks)
                     return false;
              else
              {
                     return s1.name.length()>s2.name.length();
              }
              
       }
};

bool myComp(Student &s1,Student &s2)
{
       if(s1.marks>s2.marks)
              return true;
       if(s1.marks<s2.marks)
              return false;
       else
       {
              if(s1.name.length()<s2.name.length())
                     return true;
              else if(s1.name.length()>s2.name.length())
                     return false;
              else
              {
                     return s1.name<s2.name;
              }
              
       }
       

}
//Cracking the Code
int main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
       #endif
       vector<Student> students;
       // int n;
       // cin>>n;
       // for(int i=0;i<n;i++)
       // {
       //        string name;
       //        int marks;
       //        cin>>name>>marks;
       //        Student s(name,marks);
       //        students.push_back(s);
       // }
       // sort(students.begin(),students.end(),myComp);
       // for(auto x:students)
       // {
       //        cout<<x.name<<" "<<x.marks<<endl;
       // }
       priority_queue<Student,vector<Student>,comp> pq;
       int n;
       cin>>n;
       for(int i=0;i<n;i++)
       {
              string name;
              int marks;
              cin>>name>>marks;
              Student s1(name,marks);
              pq.push(s1);
       }
       while(!pq.empty())
       {
              cout<<pq.top().name<<"\n";
              pq.pop();
       }
       return 0;
}