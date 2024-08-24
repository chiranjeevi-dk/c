#include<stdio.h>
long fun(long n)
{

printf("%d",n);
printf(" ");
fun(n+1);

}
long main()
{
printf("%d",fun(5));
return 0;
}