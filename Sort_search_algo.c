#include <stdio.h>
#include<stdbool.h>
int comp(void* a, void* b){
    return (((int*) a ) - ((int*) b));
}   
void swap(int* _greater,int* _lower){
    if(comp(_greater,_lower) == 0) return;
    
    int temp = *_greater;
    *_greater = *_lower;
    *_lower = temp;
}
int sqar_int(int _int,int _val){
    if(_val*_val == _int) return _val;
    if(_val*_val > _int) return -1;
    
}
void bbsort(int* arr,int _sizeof){
    for(int i = 0; i<_sizeof;i++){
        for(int j = 0;j<_sizeof-i-1;j++){
            if(arr[j] > arr[j+1])
               swap(&arr[j],&arr[j+1]);
        }      
   }
}
void selctsort(int* arr,int _sizeof){
    int select = 0,i,j;
    for (i = 0;i<_sizeof;i++){
        select = i;
        for (j = i;j<_sizeof-1;j++){
           if(arr[j] > arr[j+1]) select = j+1;
        }
        swap(&arr[i],&arr[select]);
    }
}
void instsort(int *arr,int _sizeof){
    for(int i = 1;i<_sizeof;i++){   
        for(int j = i;j>0;j--){
            if(arr[j] > arr[j-1]) swap(&arr[j],&arr[j-1]);
        }
    }
}
void mergsort(int* arr,int left,int right){

}
void q_sort(int* arr,int left,int right);
void show(int* arr,size){
   printf("your array : { ");
   for(int i = 0;i<size;i++) printf("%d ,",arr[i]);
   printf(" }\n");
}

int binary_search(int *arr,int target,int _sizeof){
    int mid,left = 0,right = _sizeof;
    while(left<=right){
        mid = (left + right)/2;
        if(arr[mid] == target) return 1;
        else if(arr[mid] > target) right = mid+1;
        else if(arr[mid] < target) left = mid -1;
        
    }
    return -1;
}
int linear_search(int*arr,int _sizeof,int target){
    for(int i = 0;i<_sizeof;i++) 
        if(arr[i] == target) return 1;
    return 0;
}

int main(){
     int a[1000];
     for(int = 0;i<1000;i++) a[i] = i;
     
     
}
