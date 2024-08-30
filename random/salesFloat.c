#include<stdio.h>
int main()
{
  int s1,s2,s3,s4,s5;
  float avg;
  printf("First month sale:\n");
  scanf("%d",&s1);
  printf("Second month sale:\n");
  scanf("%d",&s2);
  printf("Third month sale:\n");
  scanf("%d",&s3);
  printf("Fourth month sale:\n");
  scanf("%d",&s4);
  printf("Fifth month sale:\n");
  scanf("%d",&s5);
  printf("Avg sale:\n");
  scanf("%f",&avg);
  float s6= 6* avg - (s1+s2+s3+s4+s5);
  printf("Sixth month sale is Rs.%.2lf\n",s6);
  return 0;
}