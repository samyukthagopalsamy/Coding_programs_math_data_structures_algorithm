#include<stdio.h>
#include<conio.h>
#include<limits.h>
#define SIZE sizeof(input) / sizeof(input[0])
int main()
{
int input[]={ 23 , 10 , 45 , 5 , 89 , 7 , 52 , 304 , 73 , 123 ,
1023,95,56,18 , 22 , 29 ,11, 1};
int help[10]={0} , output[18] ={0};
int max = INT_MIN , nod = 0 , ctr , index , start , pow = 1;

// find the maximum
for( ctr = 0 ; ctr < SIZE ; ctr++)
{
   if(max < input[ctr] )
     max = input[ctr];

}
// count the digits
while( max != 0 )
{
   max = max / 10;
   nod++;
}


while(nod != 0)
{
// traverse input array fill the count into help array
for(ctr = 0 ; ctr < SIZE ; ctr++)
{
     index = (input[ctr]/pow ) % 10 ;
     help[index]++;
}
// convert count into start
help[9] = SIZE - help[9];

for(ctr = 8 ; ctr >=0 ; ctr--)
  help[ctr] = help[ctr+1] -  help[ctr];

// traverse input array fill output using help array
for( ctr = 0 ; ctr < SIZE ; ctr++)
{
     index =  (input[ctr] / pow) % 10;
     start = help[index];
     output[ start]=  input[ctr];
     help[index]++;
}
// copy output to input array
for(ctr = 0 ; ctr < SIZE ; ctr++)
   input[ctr] = output[ctr];
// reset help array
for(ctr = 0 ; ctr < 10 ; ctr++)
   help[ctr] = 0;

   pow = pow * 10;
   nod--;
}
for(ctr=0;ctr<SIZE;ctr++){
    printf("%d ",input[ctr]);
}
}
