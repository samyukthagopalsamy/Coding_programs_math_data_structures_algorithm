#include<stdio.h>
#include<stdlib.h>
#define SAFE 1
#define NOTSAFE 0

int isSafe(int , int) ;
int queenpos[8]={ -1,-1,-1, -1,-1,-1,-1, -1};
int sol[][8];

int main()
{
int DIM,row , col ,ctr , safecol = 0 , count = 0,i;
scanf("%d",&DIM);// DIM x DIM

for(row = 0 ; row < DIM ; row++)
{
   for(col = safecol ; col < DIM ; col++)
    {
	 if ( isSafe( row , col)  == SAFE )
	  {
	    queenpos[row] = col;
	    safecol = 0;
	    break;
	  }
     } // for col
     // backtrack
     if(col == DIM)
     {
	safecol = queenpos[row -1 ];
	queenpos[ row -1] = -1;
	safecol++;
	row = row - 2;
     }
    if( row == DIM-1)
     {

        for(i=0;i<DIM;i++){
    printf("%d ",queenpos[i]+1);
}
printf("\n");


       safecol = queenpos[row];
       queenpos[row] = -1;
       row--;
       safecol++;

     }
}// for row


return 0;

}



int isSafe(int r , int c)
{
   int sr = r , sc= c;
   // up
   for( r ; r != -1;  r--)
   {
     if( queenpos[r] == c)
       return NOTSAFE;
   }
   // left diagonal
   for( r = sr ; r != -1 && c != -1 ;r-- , c--)
   {
      if( queenpos[r] == c)
       return NOTSAFE;
   }
   // right diagonal
   for( r= sr , c = sc ; r != -1 && c != 8 ; c++ , r--)
   {
     if( queenpos[r] == c)
       return NOTSAFE;
   }
   return SAFE;

}


