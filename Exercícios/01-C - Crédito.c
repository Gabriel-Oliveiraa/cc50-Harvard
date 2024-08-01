#include <cs50.h>
#include <stdio.h>
#include <math.h>


bool checksum(long number, int len)
{
    int sum1 = 0, sum2 = 0;
    for (int i=0; i < len; i++)
    {
       
        int digit = number % 10;
        number /= 10;
       
        if (i % 2 == 0)
        {
            sum2 += digit;
        }
        else
        {
            digit *= 2;
            if (digit > 9)
            {
               
                sum1 += (digit / 10) + (digit % 10);
            }
            else
            {
                sum1 += digit;
            }
        }
    }
   
    int sum = sum1 + sum2;
   
    if (sum % 10 == 0)
    { return true;  }
    else
    { return false; }
}

int main(void)
{
   long credit = get_long("Número sem ponto ou traço: ");
   int len = 0;
   long n = credit;
   do
   {
       n /= 10;
       len++;
   }
   while (n > 0);
   
   bool check = checksum(credit, len);
   
   if (check)
   {
       int two = (credit / (long)pow(10, len - 2));
       int one = (credit / (long)pow(10, len - 1));
       
       if (len == 15)
       {
           if (two == 34 || two == 37)
            {
           printf("amex\n");
            }
       else { printf("invalid\n"); }
        }
        else if (len == 16)
            {
            if (one == 4)
            {
                printf("visa\n");
            }
        else if (two > 50 && two < 56)
            {
                printf("mastercard\n");
            }
                else    { printf("invalid\n"); }
        }
        else if (len == 13)
            {
                if (one == 4)
                {
                printf("visa\n");
                }
                else {printf("invalid\n");}
            }
        else
            {
            printf("invalid\n");
            }
   }
    else
    {
      printf("invalid\n");  
    }
}