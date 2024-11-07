/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

void swap(int* _greater,int* _lower);
int main()
{   
    int arr[10] = {1,2,3,4,5,6,7,8,9,10},count = 1;;
    
    for(int i = 0; i<sizeof(arr)/sizeof(arr[0])-1;i++){
        
        for(int j = 0;j<sizeof(arr)/sizeof(arr[0]);j++){
           
            if(arr[j] > arr[j+1]) swap(&arr[j],&arr[j+1]);
        }
        
    }
    for(int i = 0;i < 10;i++) printf("%d ,",arr[i]);
    return 0;
}
void swap(int* _greater,int* _lower){
    int temp = *_greater;
    *_greater = *_lower;
    *_lower = temp; 
}