/*this solution find the uniqueness of digits and then finds if abcd * e == dcba
Problem:
Find all 4 digit numbers 'abcd' with distinct digits such that abcd * e == dcba (reversed)
 1<=e<10 and e should be a distinct digit from abcd

 i.e a,b,c,d,e are distinct digits
*/

#include<iostream>
using namespace std;

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
 int abcd,e,product,reversed;

 for(abcd=1001;abcd<=9999;abcd++)
 {
     int num=abcd; // abcd should be 4-digit number with distinct digits
     bool visited[10]={false};// visited digits are set to true

     while(num!=0)
        {
            if(visited[num%10])
            { // if a digit occurs more than once -> break
                break;
            }
            visited[num%10]=true;
            num=num/10;

            if(num==0)
                { // if number is unique -> check for abcd *e == dcba
                    for(e=0;e<10;e++)
                        {
                            if(!visited[e]) // e should be distinct from digits in abcd
                                {
                                    product=abcd*e;
                                    reversed=rev(product);

                                    if(reversed==abcd)
                                        cout<<abcd<<" * "<<e<<" = "<<product<<endl;
                                }
                        }

                }
        }


}
}
