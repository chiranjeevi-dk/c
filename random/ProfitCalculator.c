#include<stdio.h>
int profitcalc(int x, int a, int b)
{
	int profit = (x * a) -( x * b) -100;
	 return profit;
}
int main(void)
{
	int x,a,b,profit;
	printf("Number of copies sold :\n");
	scanf("%d",&x);
	printf("Cost of each Copy :\n");
	scanf("%d",&a);
	printf("Cost spent by agency on each newspaper :\n");
	scanf("%d",&b);
	int result = profitcalc(x,a,b);
        printf("The profit obtained is Rs.%d\n",result);
	return 0;
}