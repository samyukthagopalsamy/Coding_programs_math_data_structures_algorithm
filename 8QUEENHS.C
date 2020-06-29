#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
//Following are ASCII values of Box drawing characters
#define LT 218 // ┌
#define RT 191 // ┐
#define LB 192 // └
#define RB 217 // ┘
#define HL 196 // ─
#define VL 179 // │
#define PLUS 197 // ┼
#define TT 194 // ┬
#define BT 193 //  ┴
#define LST 195 // ├
#define RST 180 //  ┤
#define DIM 8  // 8 x 8
#define WIDTH 7
#define HEIGHT 1
#define SAFE 1
#define NOTSAFE 0
void delay(int);
void gotoxy(short, short);
void drawBox( int , int);
void placeQueen( int , int);
void removeQueen( int , int);
int isSafe(int , int) ;
int queenpos[8]={ -1,-1,-1, -1, -1, -1, -1, -1};
int sol[92][8];

int main()
{
int row , col ,ctr , safecol = 0 , count = 0;

row = ( 25 - ( DIM * HEIGHT + DIM + 1)) / 2;
col = ( 80 - (DIM * WIDTH + DIM + 1)) / 2;
drawBox( row , col);

for(row = 0 ; row < 8 ; row++)
{
   for(col = safecol ; col < 8 ; col++)
    {
	 if ( isSafe( row , col)  == SAFE )
	  {
	    queenpos[row] = col;
	    placeQueen( row , col);
	    safecol = 0;
	    break;
	  }
     } // for col
     // backtrack
     if(col == 8)
     {
	safecol = queenpos[row -1 ];
	removeQueen( row-1 , safecol);
	queenpos[ row -1] = -1;
	safecol++;
	row = row - 2;
     }
    if( row == 7)
     {
       for( ctr = 0 ; ctr < 8 ; ctr++)
            sol[count][ctr] = queenpos[ctr];
       gotoxy(1 , 1);
       printf("SOL#%d" , ++count);
       delay(1);

       if( count ==  92)
            break;
       safecol = queenpos[row];
       removeQueen( row , safecol);
       queenpos[row] = -1;
       row--;
       safecol++;

     }
}// for row

return 0;

}
//Moves Cursor to Position Specified i.e at (x,y)
void gotoxy(short col, short row)
{
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
COORD position={col,row};
SetConsoleCursorPosition(h,position);
}

void delay(int number_of_seconds)
{
    // Converting time into milliseconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
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
void placeQueen( int r , int c)
{

int sc_row , sc_col , brow , bcol;

sc_row = ( 25 - ( DIM * HEIGHT + DIM + 1)) / 2;
sc_col = ( 80 - (DIM * WIDTH + DIM + 1)) / 2;
brow = sc_row + 1;
bcol = sc_col + 2;

  gotoxy( bcol + 8 * c , brow + 2 * r);
  printf("Queen");

}

void removeQueen( int r , int c)
{

int sc_row , sc_col , brow , bcol;

sc_row = ( 25 - ( DIM * HEIGHT + DIM + 1)) / 2;
sc_col = ( 80 - (DIM * WIDTH + DIM + 1)) / 2;
brow = sc_row + 1;
bcol = sc_col + 2;

  gotoxy( bcol + 8 * c , brow + 2 * r);
  printf("%c%c%c%c%c", 32, 32, 32, 32, 32);

}

void drawBox( int r , int c)
{
int ctr , ctr1 , ctr2;
// first line
  gotoxy( c , r);
  printf("%c" , LT);

 for(ctr1 = 0 ; ctr1 < DIM ; ctr1++)
 {
     for( ctr = 0 ; ctr < WIDTH ; ctr++)
	 printf("%c" , HL);
  printf("%c" , TT);
 }
 printf("\b%c" , RT);
 // second line

for(ctr2 = 0 ; ctr2 < DIM ; ctr2++)
{
 r++;
 gotoxy( c , r) ;
 for(ctr1 = 0 ; ctr1 < DIM+1 ; ctr1++)
 {
   printf("%c", VL);
    for( ctr = 0 ; ctr < WIDTH ; ctr++)
      printf("%c" , 32);
 }
 // third line
 r++;
 gotoxy( c, r);
 printf("%c" , LST);
 for(ctr1 = 0 ; ctr1 < DIM ; ctr1++)
 {
   for(ctr = 0 ; ctr < WIDTH ; ctr++)
      printf("%c" , HL);
  printf("%c", PLUS);
 }
 printf("\b%c", RST);
}
// last line
  gotoxy( c , r);
  printf("%c" , LB);

 for(ctr1 = 0 ; ctr1 < DIM ; ctr1++)
 {
     for( ctr = 0 ; ctr < WIDTH ; ctr++)
	 printf("%c" , HL);
  printf("%c" , BT);
 }
 printf("\b%c" , RB);

}

















