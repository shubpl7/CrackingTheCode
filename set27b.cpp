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
struct Node{
       int data;
       Node *next;
       Node(int x)
       {
              data=x;
              next=NULL;
       }
};
class MyStack{
       public:
              Node *head;
              MyStack()
              {
                     head=NULL;
              }
              void push(int x);
              int pop();
              int peek();
              void Display();
              bool IsEmpty();
              void Clear();
};
void MyStack::push(int x)
{
       Node * temp = new Node(x);
       temp->next=head;
       head=temp;
}
int MyStack::pop()
{
       int x=-1;
       if(IsEmpty())
              return x;
       Node *temp=head;
       head=head->next;
       temp->next=NULL;
       x=temp->data;
       delete temp;
       return x;
}
bool MyStack::IsEmpty()
{
       if(head)
              return false;
       return true;
}
int MyStack::peek()
{
       if(IsEmpty())
              return -1;
       return head->data;
}
void MyStack::Display()
{
       Node *temp=head;
       while(temp)
       {
              cout<<temp->data<<" ";
              temp=temp->next;
              
       }       
       cout<<endl;
}
void MyStack::Clear()
{
       while(head)
       {
              pop();
       }
       cout<<"Your stack is empty now\n";
}
int32_t main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
       #endif
       MyStack *s=new MyStack();
       s->push(10);
       s->push(20);
       s->push(30);
       s->push(40);
       s->Display();
       cout<<s->pop()<<endl;
       s->Display();
       cout<<s->peek();
       cout<<endl;
       s->Clear();
       s->Display();
       s->push(22383);
       s->Display();
       return 0;
}