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

class Student{
       public:
              string name;
              int id;
              Student *link;
              Student(){}
              Student(string n,int i)
              {
                     name=n;
                     id=i;
                     link=NULL;
              }
};

class LinkedList{
       public:
              Student *head;
              
              LinkedList()
              {
                     this->head=NULL;
              }
              void InsertAtBeg(Student);
              void InsertAtPos(int,Student);
              void deleteStudent(string);
              void Print();
              void Reverse();
              void Rreverse();
              void VectorToList(vector<pair<string,int>>);
};
Student * RevUtil(Student *temp,Student* & HeadOfReverseList)
{
       if(temp->link==NULL)
       {
              HeadOfReverseList=temp;
              return temp;
       }
       Student *LastofReverse = RevUtil(temp->link, HeadOfReverseList);
       temp->link=NULL;
       LastofReverse->link=temp;
       return temp;

}
void LinkedList::Rreverse()
{
       Student *HeadOfReverseList;
       Student *t=RevUtil(head,HeadOfReverseList);//it will return the last element of the reverse list
       head=HeadOfReverseList;
       return;
}
void LinkedList::InsertAtBeg(Student t)
{
       Student *temp=new Student();
       temp->name=t.name;
       temp->id=t.id;
       temp->link=head;
       head=temp;
}
void LinkedList::InsertAtPos(int pos,Student s)
{
       int cnt=1;
       Student *temp=head,*prev=NULL;
       while(temp)
       {
              if(cnt==pos)
              {
                     Student *t=new Student(s.name,s.id);
                     t->link=temp;
                     if(prev)
                            prev->link=t;
                     else
                     {
                            head=t;
                     }
                     cout<<s.name<<" successfully added\n";
                     return;

              }
              cnt++;
              prev=temp;
              temp=temp->link;
       }
       if(cnt==pos)
       {
              Student *t=new Student(s.name,s.id);
              if(prev)
                     prev->link=t;
              else
              {
                     head=t;
              }
              t->link=NULL;
              cout<<s.name<<" successfully added\n";
              return;
       }
       cout<<"pos out of range\n";
}

void LinkedList::Print()
{
       Student *temp=head;
       while(temp)
       {
              cout<<temp->name<<" "<<temp->id<<"--->";
              temp=temp->link;
       }
       cout<<endl;
}
void LinkedList::Print()
{
       Student *temp=head;
       while(temp)
       {
              cout<<temp->name<<" "<<temp->id<<"--->";
              temp=temp->link;
       }
       cout<<endl;
}
int32_t main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
       #endif
       LinkedList *LL=new LinkedList();
       Student s1("Shubham",12),s2("Shailly",67),s3("Arnav",89);
       LL->InsertAtBeg(s1);
       LL->InsertAtBeg(s2);
       LL->InsertAtBeg(s3);
       Student s4("Stuti",65);
       LL->InsertAtPos(4,s4);
       LL->Print();
       LL->Rreverse();
       LL->Print();
       return 0;
       
       
}