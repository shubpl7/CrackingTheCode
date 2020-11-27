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
                     this->name=n;
                     this->id=i;
                     link=NULL;
              }
};

class LinkedList{
       public:
              Student* head=NULL;
              LinkedList()
              {
                     this->head=NULL;
              }
              void InsertAtBeg(Student);
              void DeleteStudent(string);
              void InsertAtPosition(int,Student);
              void Reverse();
              void Print();
              void Rreverse();
              void VectorToList(vector<pair<string,int>>);
};
void LinkedList::VectorToList(vector<pair<string,int>> v)
{
       for(auto x:v)
       {
              Student *temp=new Student();
              temp->name=x.first;
              temp->id=x.se;
              InsertAtBeg(*temp);
       }
}
Student *RevUtil(Student *t,Student * &ans)
{
       if(t->link==NULL)
       {
              ans=t;
              return t;
       }
       Student * LastOfReveseList = RevUtil(t->link,ans);
       t->link=NULL;
       LastOfReveseList->link=t;
       return t;
}
void LinkedList::Rreverse()
{
       Student *ans;
       RevUtil(head,ans);
       head=ans;
}
void LinkedList::Reverse()
{
         Student * current = head; 
        Student *prev = NULL, *next = NULL; 
  
        while (current != NULL) {  
            next = current->link;  
            current->link = prev; 
            prev = current; 
            current = next; 
        } 
        head = prev; 
       cout<<"\n List Reversed\n";
}
void LinkedList::InsertAtBeg(Student s)
{
       Student* temp= new Student();
       temp->name=s.name;
       temp->id=s.id;
       temp->link=head;
       head=temp;
}
void LinkedList::Print()
{
       Student * temp=head;
       while(temp)
       {
              cout<<temp->name<<" "<<temp->id<<"--->";
              temp=temp->link;
       }
       cout<<endl;
}
void LinkedList::InsertAtPosition(int pos,Student s)
{
       int cnt=1;
       Student *temp=head;
       Student *prev=NULL;
       while(temp)
       {
              if(cnt==pos)
              {
                     Student *t=new Student(s.name,s.id);
                     t->link=temp;
                     if(prev)
                     {
                            prev->link=t;
                     }
                     else
                            head=t;
                     cout<<"successfully added\n";
                     return;
              }
              prev=temp;
              temp=temp->link;
              cnt++;
       }
       if(pos==cnt)
       {
              Student *t=new Student(s.name,s.id);
              t->link=NULL;
              if(prev)
                     prev->link=t;
              else
              {
                     head=t;
              }
              cout<<"successfully added\n";
              return;
       }
       cout<<"pos outside the Range\n";
}
void LinkedList::DeleteStudent(string name)
{
       Student *temp=head;
       Student* prev=NULL;
       while(temp)
       {
              if(temp->name==name)
              {
                     if(prev)
                            prev->link=temp->link;
                     else
                     {
                            head=temp->link;
                     }
                     temp->link=NULL;
                     delete temp;
                     cout<<endl;
                     cout<<name<<" successfully deleted\n";
                     return;
              }
              prev=temp;
              temp=temp->link;
       }
       cout<<name<<"\n NOTfound\n";
}
int32_t main()
{
       // ios_base::sync_with_stdio(false);
       // cin.tie(NULL);
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
       LL->InsertAtPosition(4,s4);
       LL->Print();
       LL->Rreverse();
       LL->Print();
       return 0;
}
for (int i = 1; i <= max_level; i++) 
{
       if(sum[i]>maxSum)
       {
              maxSum=sum[i];
              maxLevel=i;
       }
}        