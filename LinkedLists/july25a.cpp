#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;

class Node
{
public:
       int data;
       Node *next;
       Node()
       {
              next = NULL;
       }
};

class LinkedList
{
public:
       Node *head;
       LinkedList()
       {
              head = NULL;
       }
       void InsertAtBegin(int);
       void InsertAtEnd(int);
       void InsertAtPos(int, int);
       int DeleteAtBegin();
       int DeleteAtEnd();
       int DeleteAtPos(int);
       void Display();
};

void LinkedList::InsertAtBegin(int val)
{
       Node *temp = new Node();
       temp->data = val;
       temp->next = head;
       head = temp;
}

void LinkedList::InsertAtEnd(int val)
{
       Node *temp = new Node();
       temp->data = val;
       if (head == NULL)
              head = temp;
       else if (head->next == NULL)
       {
              head->next = temp;
       }
       else
       {
              Node *last = head;
              while (last->next != NULL)
              {
                     last = last->next;
              }
              last->next = temp;
       }
}

void LinkedList::InsertAtPos(int val, int pos)
{
       if (pos == 0)
       {
              InsertAtBegin(val);
              return;
       }
       int length = 0;
       Node *t = head;
       while (t->next != NULL)
       {
              t = t->next;
              length++;
       }
       if (pos == length + 1)
       {
              InsertAtEnd(val);
              return;
       }
       else if (pos > length + 1)
       {
              cout << "invalid\n";
              return;
       }
       Node *prev = NULL;
       Node *curr = head;
       while (pos > 0)
       {
              prev = curr;
              curr = curr->next;
              pos--;
       }
       Node *temp = new Node();
       temp->data = val;
       prev->next = temp;
       temp->next = curr;
       // if(pos==0 && curr==NULL)
       // {
       //     //INSERT AT END
       //     InsertAtEnd(val);
       // }
       // else if(pos!=0 && curr==NULL)
       // {
       //     cout<<"linked list contains lesser elements\n";
       // }
       // else
       // {
       //     Node * temp = new Node();
       //     temp->data = val;
       //     prev->next = temp;
       //     temp->next = curr;
       // }
}

int LinkedList::DeleteAtBegin()
{
       if (head == NULL)
              return -1;
       int ans = head->data;
       Node *temp = head;
       head = head->next;
       temp->next = NULL;
       delete temp;
       return ans;
}

void LinkedList::Display()
{
       Node *temp = head;
       while (temp != NULL)
       {
              cout << temp->data << "---->";
              temp = temp->next;
       }
       cout << endl;
}
int32_t main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
#ifndef ONLINE_JUDGE
       freopen("../input.txt", "r", stdin);
       freopen("../output.txt", "w", stdout);
#endif
       LinkedList l;
       l.InsertAtBegin(8);
       l.InsertAtBegin(2);
       l.InsertAtBegin(3);
       l.InsertAtBegin(6);
       l.Display();
       l.InsertAtEnd(10);
       l.InsertAtEnd(99);
       l.Display();
       l.InsertAtPos(111, 4);
       l.Display();
       l.InsertAtPos(200, 7);
       l.Display();
       int elem = 5;
       while (elem--)
       {
              cout << l.DeleteAtBegin() << endl;
       }
       l.Display();
       return 0;
}