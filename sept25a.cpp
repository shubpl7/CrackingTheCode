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
       Node * next;
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
              void push(int);
              int pop();
              int top();
              void PrintStack();
              void EmptyStack();
};
void MyStack::push(int x)
{
       Node *temp=new Node(x);
       temp->next=head;
       head=temp;
}
int MyStack::pop()
{
       Node *temp=head;
       head=head->next;
       temp->next=NULL;
       int a=temp->data;
       delete temp;
       return a;
}
void MyStack::PrintStack()
{
       Node *temp=head;
       while(temp)
       {
              cout<<temp->data<<" ";
              temp=temp->next;
       }
       cout<<endl;
}
void MyStack::EmptyStack()
{
       while(head)
       {
              this->pop();
       }
       cout<<"Stack is Empty\n";
}
int32_t main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
       #endif
       MyStack *s = new MyStack();
       s->push(10);
       s->push(20);
       s->push(30);
       s->push(40);
       s->PrintStack();
       cout<<s->pop()<<endl;;
       s->PrintStack();
       s->EmptyStack();
       s->PrintStack();
       return 0;
}