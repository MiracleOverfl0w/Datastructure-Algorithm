#include<iostream>
#include <time.h>
using namespace std;
long double bi_ex(int base ,int power)
{ 
   if (power == 1) return base;
  if(power == 0)   return 1.0;
  long double half = bi_ex(base,power/2) ;
  
  long double full; 
  full = half * half;
    cout<<full<<endl;   
       
  if (power%2==1) return full * base;
  return full;  
}


int main(){

    
    printf("%.0Lf",  bi_ex(2,15));
    

    
    return 0;
}