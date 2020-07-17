#include<stdio.h>
int main()
{   //SQUARE-FREE--The numbers which are divisible by any prime factor only once.
    //1470=2*3*5*7*7
    int num=1470,factor=2,count=0;

    for(factor=2;num>1;factor++)
    {
        count =0;
        while(num%factor==0)
        {
            num=num/factor;
            count++;
            if(count>=2)
            {
                printf("The number is not square-free .");
                return 0;
            }
        }
    }
printf("The number is square free");


    return 0;
}
