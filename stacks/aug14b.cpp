#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PB push_back
typedef vector<int> VI;
typedef vector<VI> VVI;
class node
{
public:
    int data;
    node *next;
    node *prev;
    node()
    {
        next = NULL;
        prev = NULL;
    }
};
class LRUCache
{
public:
    int capacity = 3;
    node *head, *rear;
    int currSize;
    LRUCache()
    {
        currSize = 0;
        head = NULL;
        rear = NULL;
    }
    unordered_map<int, node *> mp;
    void refer(int x)
    {
        if (mp.find(x) == mp.end())
        {
            if (currSize == capacity)
            {
                node *temp = rear;
                rear = rear->prev;
                temp->prev = NULL;
                rear->next = NULL;
                delete temp;
                mp.erase(temp->data);
                node *temp2 = new node;
                temp2->data = x;
                temp2->next = head;
                head->prev = temp2;
                head = temp2;
                mp.insert({x, temp2});
            }
            else
            {
                node *temp2 = new node;
                temp2->data = x;
                if (currSize == 0)
                {
                    head = temp2;
                    rear = temp2;
                }
                else
                {
                    temp2->next = head;
                    head->prev = temp2;
                    head = temp2;
                }
                mp.insert({x, temp2});
                currSize++;
            }
        }
        else
        {
            if (currSize == 1)
                return;

            node *loc = mp[x];
            if (loc == head)
                return;
            node *locPrev = loc->prev;
            node *locNext = loc->next;
            if (loc == rear)
            {
                loc->next = head;
                loc->prev = NULL;
                head->prev = loc;
                head = loc;

                locPrev->next = locNext;
                rear = locPrev;
            }
            else
            {
                loc->next = head;
                loc->prev = NULL;
                head->prev = loc;
                head = loc;

                locPrev->next = locNext;
                locNext->prev = locPrev;
            }
            // temp->next = NULL;
            // rear->next = head;
            // rear->prev = NULL;
            // head->prev = rear;
            // head = rear;
            // rear = temp;
        }
        cout << "Current size is : " << currSize << endl;
        for (auto x : mp)
        {
            cout << x.first << "------>" << x.second << endl;
        }
        cout << endl;
    }
    void display()
    {
        node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    LRUCache l;
    l.capacity = 3;
    l.refer(1);
    l.display();
    l.refer(2);
    l.display();
    l.refer(1);
    l.display();
    l.refer(4);
    l.display();
    l.refer(3);
    l.display();
    l.refer(1);
    l.display();
    return 0;
}