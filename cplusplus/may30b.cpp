#include<bits/stdc++.h>
using namespace std;


int calc_digits(int n)
{
       int digits=0;
       while(n!=0)
       {
              digits++;
              n = n/10;
       }
       return digits;
}

bool check_armstrong(int n)
{
       int d;
       d = calc_digits(n);

       int sum=0;
       int temp=n;
       while(n!=0)
       {
              int digit = n%10;
              sum+=(int)pow(digit,d);
              n= n/10;
       }
       if(temp == sum)
              return true;
       else
              return false;
}


//Cracking the Code
int32_t main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("../input.txt","r",stdin);
       freopen("../output.txt","w",stdout);
       #endif
       
       for(int n=1;n<=100000;n++)
       {
              //check for armstrong
              if(check_armstrong(n))
                     cout<<n<<"\n";
       }
       
       return 0;
}