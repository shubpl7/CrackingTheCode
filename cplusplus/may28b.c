#include<stdio.h>
struct student
{
       int age;
       char name[10];
       int marks[3];
};

void cal_avg(struct student s)
{
       float sum=0;
       for(int i=0;i<3;i++)
       {
              sum=sum+s.marks[i];
       }
       printf("the avg is %f\n",sum/3);
}
int main()
{
       struct student s1;
       s1.marks[0]=10;
       s1.marks[1]=15;
       s1.marks[2]=30;
       cal_avg(s1);
       return 0;
}