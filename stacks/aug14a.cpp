#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;
class node{
    public:
        int data;
        node * next;
        node()
        {
            next = NULL;
        }
};
class mystack{
public:
    node * head;
    int stackSize;
    mystack()
    {
        head = NULL;
        stackSize = 0;
    }
    int top()
    {
        if(head)
            return head->data;
        cout<<"Stack is Empty\n";
        return -1;
    }
    void push(int x)
    {
        node * temp = new node;
        temp->data = x;
        temp->next = head;
        head = temp;
        stackSize++;
    }
    int pop()
    {
        if(!head)
        {
            cout<<"Stack is Empty\n";
            return -1;
        }
        node * temp = head;
        head = head->next;
        temp->next = NULL;
        return temp->data;
        delete temp;
        stackSize--;
    }
    void ReverseStack()
    {
        node * curr=head, * prev=NULL, *next=NULL;
        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
        }
        head = prev;
    }
    void PrintStack()
    {
        node * temp = head;
        while(temp)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
            
    }
};
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    #endif
    mystack s;
    s.push(10);
    s.push(8);
    s.push(67);
    s.push(7);
    s.PrintStack();
    cout<<"Top is : "<<s.top()<<endl;
    s.pop();
    s.PrintStack();
    s.push(100);
    s.ReverseStack();
    s.PrintStack();
    cout<<"#"<<s.stackSize;
    return 0;
}