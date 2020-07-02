#include<stdio.h>
#include<math.h>
/*A circular prime is a prime number with the property that
the number generated at each intermediate step when cyclically
permuting its (base 10) digits will be prime.
For example, 1193 is a circular prime, since 1931, 9311 and 3119 all are also prime.*/
int isprime(long long  int num)
{

     static long long int prime[100000]={2,3,5};
     static long long int pctr=3;
      int factor;
      long int till=sqrt(num);
     if(!   (num%6==1 || num%6==5)  )
    return 0;

     for(factor=0;prime[factor]<=till;factor++)
     {
         if((num%prime[factor])==0)
            return 0;

     }
     prime[pctr++]=num;
     return 1;

 }

 long long int circularnum(long long int num)
 {
     long long int safe,cnum , power = 1;
     int digit;

 safe=num;
 while(num!=0)
{
num=num/10;
power=power*10;

}
num=safe;
power=power/10;
digit=num/power;
num=num%power;
cnum=num*10+digit;
return cnum;
 }
 int nod( long long int num )
 {

     int nod = 0 ;
     while( num)
     {

         num = num / 10;
         nod++;
     }
     return nod;
 }
int main()
{
   long  long int flag = 0 ,safe , num,ctr,cnum , ctr1;
   long long int prime[100000]={2,3,5},pctr=3;

     for(num=7;num<1000000;num+=2)
     {
        if(isprime(num)==1)
            prime[pctr++]=num;

     }

for(ctr1 = 1 ; ctr1 < pctr ; ctr1++ )
{
     num = prime[ ctr1 ];
     safe = num ;

     do
      {
          cnum = circularnum(num);
          for( ctr = 0 ; ctr < pctr ; ctr++)
          {
             if( cnum ==  prime[ctr])
             {
                break;
             }
          }
          if( ( nod(safe) == nod(cnum))&& safe!=cnum && ctr!=pctr)
                num = cnum;

        else break;

      } while(1);

    if( safe == cnum )
         printf("%lld  " , cnum);

}


}








