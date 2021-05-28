#include<iostream>
using namespace std;

class student{
       private:
              int age;
              int marks[3];
              string name;
       public:
              float cal_avg()
              {
                     float sum=0;
                     for(int i=0;i<3;i++)
                            sum+=marks[i];
                     return sum/3;
                     //cout<<" the avg. is : "<<sum/3<<"\n";
              }
              void getmarks()
              {
                     for(int i=0;i<3;i++)
                     {
                            cout<<"Enter the marks of "<<i<<" th sub."<<endl;
                            cin>>marks[i];
                     }
              }

};
int main()
{
       student s1;
       int a;
       s1.getmarks();
       cout<<"avg is: "<<s1.cal_avg();
       return 0;
}