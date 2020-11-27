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
              Student * link;
              Student(string n,int i)
              {
                     name=n;
                     id=i;
                     link=NULL;
              }
};
void Print(Student *head)
{
       while(head!=NULL)
       {
              cout<<head->name<<" "<<head->id<<"--->";
              head=head->link;
       }
}

void deleteItem(string key,Student * &head)
{
       Student *prev=NULL,*curr=head;
       while(curr!=NULL)
       {
              if(curr->name==key)
              {
                     if(prev)
                            prev->link=curr->link;
                     else
                     {
                            head=head->link;
                     }
                     curr->link=NULL;
                     delete curr;
                     cout<<key<<" Deleted\n";
                     return;
              }
              prev=curr;
              curr=curr->link;
       }
       cout<<"Element not found\n";
}
int32_t main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
       #endif
       Student *s1=new Student("shubham",1);
       Student *s2=new Student("Aditi",3);
       Student *s3=new Student("Gaurav",6);
       //(*s1).link=s2;
       s1->link=s2;
       s2->link=s3;
       Print(s1);
       cout<<endl;
       deleteItem("shubham",s1);
       Print(s1);
       return 0;
}

