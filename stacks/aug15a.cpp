#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;
//implementing queue using DLL
//insert at begin and delete at end

class node{
    public:
        int data;
        node * next;
        node * prev;
        node()
        {
            next=NULL;
            prev = NULL;
        }
};


class MyQueue{
    public:
        node *left, *right;
        int capacity = 10;
        int QueueSize = 0;
        MyQueue()
        {
            left = NULL;
            right = NULL;
        }
        void insert(int x)
        {
            if(QueueSize==capacity)
            {
                cout<<"Queue is full\n";
                return;
            }
            node * temp = new node;
            temp->data = x;
            if(QueueSize == 0)
            {
                left=right=temp;
            }
            else
            {
                temp->next = left;
                left->prev = temp;
                left = temp;
            }
            QueueSize++;
        }
        void pop()
        {
            if(QueueSize==0)
            {
                cout<<"Queue is Empty\n";
                return;
            }
            if(QueueSize==1)
            {
                cout<<right->data<<" is deleted\n";
                delete right;
                left=right=NULL;
                QueueSize--;
                return;
            }
            node * temp = right->prev;
            right->prev = NULL;
            temp->next = NULL;
            cout<<right->data<<" is deleted\n";
            delete right;
            QueueSize--;
            right = temp;
        }
        void display()
        {
            node * temp = left;
            while(temp!=NULL)
            {
                cout<<temp->data<<"--->";
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
    MyQueue q;
    q.insert(10);
    q.insert(7);
    q.insert(6);
    q.insert(65);
    q.display();
    q.pop();
    q.display();
    q.pop();
    q.display();

    return 0;
}