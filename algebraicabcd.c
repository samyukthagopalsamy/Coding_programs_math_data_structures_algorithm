/*the solution works but accepts duplicated digits too and to find
the uniqueness of digits following algorithm can be used:
1.sort and check if the number are in increasing order

2. use arrays and count the occurrence of digits

3. rotate the number and check first and last digit,repeat until number comes back to original state

4. bitwise*/

#include<stdio.h>
int rev(int num)
{
    int digit,res=0;

    while(num!=0)
    {
        digit=num%10;
        res=(res*10)+digit;
        num=num/10;

    }
    return res;
}
int main()
{
 int abcd,e,product,reverse;
 for(abcd=1001;abcd<=9999;abcd++)
 {
     for(e=1;e<10;e++)
     {
         product=abcd*e;
         reverse=rev(product);
         if(reverse==abcd)
            printf("%d*%d=%d\n",abcd,e,product);
     }

}
}
