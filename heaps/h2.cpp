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
class heap{
       int size;
       VI arr;
       int parent(int i){return (i-1)/2;}
       int left(int i){return 2*i+1;}
       int right(int i){return 2*i+2;}
       public:
              heap(int c)
              {
                     arr.resize(c);
                     size=0;
              }
              void insert(int x);
              void heapify(int i);
              int extractMin();
              void decreaseKey(int i,int x);
              void deleteKey(int i);
              void buildheap(int *A,int n);
              void heapsort(int *A,int n);
              void printheap();
};
void heap::printheap()
{
       cout<<"there are currently "<<size<<" elements in the heap:-->";
       for(int i=0;i<size;i++)
              cout<<arr[i]<<" ";
       cout<<endl;
}
void heap::heapsort(int *A,int n)
{
       buildheap(A,n);
       while(size)
       {
              arr[size-1]=extractMin();
       }
       for(int i=0;i<n;i++)
              A[i]=arr[i];
}
void heap::buildheap(int *A,int n)
{
       size=n;
       for(int i=0;i<n;i++)
       {
              arr[i]=A[i];
       }
       if(n==1)
       {
              return;
       }
       if(n==2)
       {
              if(arr[1]<arr[0])
                     swap(arr[0],arr[1]);
       }
       int i=(size-2)/2;
       while(i>=0)
       {
              heapify(i);
              i--;
       }
       for(int i=0;i<n;i++)
              A[i]=arr[i];
}
void heap::deleteKey(int i)
{
       arr[i]=arr[size-1];
       size--;
       heapify(i);
       /*
       decreaseKey(i,-10000);
       extractMin();
       */
}
void heap::decreaseKey(int i,int x)
{
       arr[i]=x;
       while(i!=0 && arr[i]<arr[parent(i)])
       {
              swap(arr[i],arr[parent(i)]);
              i=parent(i);
       }
}
int heap::extractMin()
{
       if(size==0)
              return -1;
       if(size==1)
       {
              size=0;
              return arr[0];
       }
       int ans=arr[0];
       swap(arr[0],arr[size-1]);
       size--;
       heapify(0);
       return ans;
}
void heap::heapify(int i)
{
       //i is parent
       // 2*i+1 is lchild, 2*i+2 is rchild
       int smallest=i;
       int l = left(i);
       int r = right(i);
       if(l<size && arr[l]<arr[smallest])
              smallest=l;
       if(r<size && arr[r]<arr[smallest])
              smallest=r;
       if(smallest!=i)
       {
              swap(arr[smallest],arr[i]);
              heapify(smallest);
       }
}
void heap::insert(int x)
{
       size++;
       arr[size-1]=x;
       int index=size-1;
       while(index!=0 && arr[index]<arr[parent(index)])
       {
              swap(arr[index],arr[parent(index)]);
              index=parent(index);
       }
}
int32_t main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("../input.txt","r",stdin);
       freopen("../output.txt","w",stdout);
       #endif
       int A[]={10,5,20,2,4,8};
       int n=sizeof(A)/sizeof(A[0]);
       heap h(100);
       h.heapsort(A,n);
       for(int i=0;i<n;i++)
              cout<<A[i]<<" ";
       //h.buildheap(A,n);
       // h.printheap();
       // h.deleteKey(1);
       // h.printheap();
       // h.decreaseKey(3,1);
       // h.printheap();
       
       return 0;
}