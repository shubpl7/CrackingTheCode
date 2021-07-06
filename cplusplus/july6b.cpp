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

class Matrix{
       // private:
       //        int rows;
       //        int cols;
       //        vector<vector<int>> arr;
       public:
              int rows;
              int cols;
              vector<vector<int>> arr;
              Matrix(int r,int c)
              {
                     rows = r;
                     cols = c;
                     arr.resize(r,vector<int>(c));
              }
              void FillMatrix()
              {
                     cout<<"Please enter a matrix of size "<<rows<<" X "<<cols<<endl;
                     for(int i=0;i<rows;i++)
                     {
                            for(int j=0;j<cols;j++)
                            {
                                   cin>>arr[i][j];
                            }
                     }
              }
              void Display()
              {
                     cout<<"your Matrix is :"<<endl;
                     for(int i=0;i<rows;i++)
                     {
                            for(int j=0;j<cols;j++)
                            {
                                   cout<<arr[i][j]<<" ";
                            }
                            cout<<endl;
                     }
              }
              // Matrix operator+(Matrix& b)
              // {
              //        Matrix temp(b.rows,b.cols);
              //        for(int i=0;i<rows;i++)
              //        {
              //               for(int j=0;j<cols;j++)
              //               {
              //                      temp.arr[i][j] = arr[i][j] + b.arr[i][j];
              //               }
              //        }
              //        return temp;
              // }
              friend Matrix operator+(Matrix A, Matrix B);
              friend ostream & operator<<(ostream &out, Matrix M);
              friend istream & operator>>(istream &i, Matrix &M);
};

Matrix operator+(Matrix A, Matrix B)
{
       Matrix temp(A.rows,A.cols);
       for(int i=0;i<A.rows;i++)
       {
              for(int j=0;j<A.cols;j++)
              {
                     temp.arr[i][j] = A.arr[i][j] + B.arr[i][j];
              }
       }
       return temp;
}
ostream & operator<<(ostream &o, Matrix M)
{
       o<<"your Matrix is :"<<endl;
       for(int i=0;i<M.rows;i++)
       {
              for(int j=0;j<M.cols;j++)
              {
                     o<<M.arr[i][j]<<" ";
              }
              o<<endl;
       }
       return o;
}
istream & operator>>(istream &o, Matrix &M)
{
       cout<<"Please enter your Matrix of Size "<<M.rows<<" X "<<M.cols<<endl;
       for(int i=0;i<M.rows;i++)
       {
              for(int j=0;j<M.cols;j++)
              {
                     o>>M.arr[i][j];
              }
       }
       return o;
}
int32_t main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       // #ifndef ONLINE_JUDGE
       // freopen("../input.txt","r",stdin);
       // freopen("../output.txt","w",stdout);
       // #endif
       Matrix A(2,3);
       cin>>A;
       cout<<A;
       Matrix B(2,3);
       cin>>B;
       cout<<B;
       Matrix C = A+B;
       cout<<C;

       return 0;
}