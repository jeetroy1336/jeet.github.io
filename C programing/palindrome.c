#include<stdio.h>
int main()
{
    int num,temp,a,sum = 0;
    printf("Enter a number:\n");
    scanf("%d",&num);
    temp = num;

    while (num > 0)
    {
        a = num % 10;
        sum = (sum * 10) + a;
        num = num / 10;
    }
    if (sum == temp)
    {
        printf("Palindrome.");
    }
    else
    {
        printf("Not palindrome.");
    }
    return 0;
}
