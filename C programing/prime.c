#include<stdio.h>
int prime(int);
int main()
{
  int i,n1,n2;

  printf("Enter two numbers:\n");
  scanf("%d%d",&n1,&n2);

  printf("All prime numbers between %d and %d are:  ",n1,n2);
  
  for (i = n1;i <= n2;i++)
  {
    if(prime(i))
    {
      printf("%d\t",i);
    }
  }
  return 0;
}
int prime(int n)
{
  int i;

  for (i = 2;i*i <= n;i++)
  {
    if (n % i == 0)
    {
    return 0;
    }
  }
  return 1;
}
