#include <stdio.h>
int comp(void* a, void* b){
    return (((int*) a ) - ((int*) b));
}   
void swap(int* _greater,int* _lower){
    if(comp(_greater,_lower) == 0) {
       //printf("same address\n");
       return;
    }   
    int temp = *_greater;
    *_greater = *_lower;
    *_lower = temp;
}
void bbsort(int* arr,int _sizeof){
    for(int i = 0; i<_sizeof;i++){
        for(int j = 0;j<_sizeof-i-1;j++){
            if(arr[j] > arr[j+1])
               swap(&arr[j],&arr[j+1]);
        }      
   }
}
void selctsort(int* arr,int size){
    int select = 0,i,j;
    for (i = 0;i<size;i++){
        select = i;
        for (j = i;j<size-1;j++){
           if(arr[j] > arr[j+1]) select = j+1;
        }
        swap(&arr[i],&arr[select]);
    }
}
void mergsort(int* arr,int left,int right);
void q_sort(int* arr,int left,int right);
void show(int arr*,size){
   printf("your array : { ");
   for(int i = 0;i<size,i++) printf("%d ,",arr[i]);
   printf(" }\n");
}
int main(){
     int a[5] = {8988,7,5,8,9};
}
