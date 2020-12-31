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
       Node *left, *right;
       Node(int k)
       {
              data =k;
              left=right=NULL;
       }
};
class Btree{
       public:
              Node *root;
              VI v;
              int res=0;
              int ans=0;
              map<int,int> mp;
              void PreOrder(Node *);
              void LevelOrder(Node *);
              int height(Node *);
              void diameter(Node *);
              void RootToLeaf(Node *);
              void TopView(Node *,int);
              void BottomView(Node *,int);
              int InfectTree(Node *,int leaf,int &dis);
};
int Btree::InfectTree(Node *head,int leaf,int &dis)
{
       if(head==NULL)
              return 0;
       if(head->data==leaf)
       {
              dis=0;
              return 1;
       }
       int ld=-1,rd=-1;
       int leftHeight = InfectTree(head->left,leaf,ld);
       int rightHeight = InfectTree(head->right,leaf,rd);
       if(ld!=-1)
       {
              dis=ld+1;
              ans = max(ans, dis+rightHeight);
       }
       else if(rd!=-1)
       {
              dis=rd+1;
              ans = max(ans, dis+leftHeight);
       }
       return max(leftHeight,rightHeight)+1;
}
void Btree::TopView(Node *head,int hd)
{
       if(head==NULL)
              return;
       if(mp.count(hd)==0)
       {
              mp[hd]=head->data;
       }
       TopView(head->left,hd-1);
       TopView(head->right,hd+1);
}
void Btree::BottomView(Node *head,int hd)
{
       if(head==NULL)
              return;
       mp[hd]=head->data;
       BottomView(head->left,hd-1);
       BottomView(head->right,hd+1);
}
void Btree::PreOrder(Node *head)
{
       if(head==NULL)
              return;
       cout<<head->data<<" ";
       PreOrder(head->left);
       PreOrder(head->right);
}
void Btree::LevelOrder(Node *head)
{
       queue<Node *> q;
       q.push(head);
       int level=0;
       while(!q.empty())
       {
              int cnt =q.size();
              int sum=0;
              VI v;
              for(int i=0;i<cnt;i++)
              {
                     Node *t = q.front();
                     //cout<<t->data<<" ";
                     //sum+=t->data;
                     // if(i==cnt-1)
                     //        cout<<t->data<<" ";
                     v.push_back(t->data);
                     q.pop();
                     if(t->left)
                            q.push(t->left);
                     if(t->right)
                            q.push(t->right);
              }
              if(level%2==0)
                     reverse(v.begin(),v.end());
              for(auto x:v)
                     cout<<x<<" ";
              cout<<endl;
              v.clear();
              level++;
              //cout<<"--->"<<sum<<endl;
       }
}
int Btree::height(Node *head)
{
       if(head==NULL)
              return 0;
       int lh=height(head->left);
       int rh = height(head->right);
       return max(lh,rh)+1;
}
void Btree::diameter(Node *head)
{
       if(head==NULL)
              return;
       int lh = height(head->left);
       int rh= height(head->right);
       res=max(res,lh+rh);
}
void Btree::RootToLeaf(Node *head)
{
       if(head==NULL)
              return;
       v.push_back(head->data);
       if(head->left==NULL && head->right==NULL)
       {
              int sum=0;
              for(auto x:v)
              {
                     sum+=x;
                     cout<<x<<" ";
              }
              cout<<"--->"<<sum<<endl;
       }
       RootToLeaf(head->left);
       RootToLeaf(head->right);
       auto it =v.end();
       it--;
       v.erase(it);
}
int32_t main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("../input.txt","r",stdin);
       freopen("../output.txt","w",stdout);
       #endif
       Btree t;
       t.root = new Node(0);
       t.root->left = new Node(1);
       t.root->right = new Node(2);
       t.root->left->left = new Node(3);
       t.root->left->right = new Node(4);
       t.root->right->left = new Node(5);
       t.root->right->right = new Node(6);
       t.root->left->left->left = new Node(7);
       t.root->left->left->right = new Node(8);
       // t.PreOrder(t.root);
       // cout<<endl;
       //t.LevelOrder(t.root);
       // t.diameter(t.root);
       // cout<<"Diameter is : "<<t.res;
       // cout<<endl;
       // t.RootToLeaf(t.root);
       // t.BottomView(t.root,0);
       // for(auto x:(t.mp))
       // {
       //        cout<<x.second<<" ";
       // }
       int dis=0;
       t.InfectTree(t.root,7,dis);
       cout<<"Infection time : "<<t.ans;
       return 0;
}