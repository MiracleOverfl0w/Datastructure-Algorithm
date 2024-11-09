#include <stdio.h>
#include<stdbool.h>
#include<math.h> 
int cmp(void* a,void* b){
    return ((int*)a) - ((int*)b);
}
void swap(int *a, int *b){
   if(!cmp(a,b)) return;
   int temp = *a;
   *a = *b;
   *b = temp;
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
void mergsort(int* arr,int left,int right);
void _qsort(int *arr,int _begin,int _end){
   if(_begin > _end ) return;
   int *pivot = &arr[_end];
   int pos = _begin-1;
    for(int i = _begin;i<=_end;i++){
        if(arr[i] < *pivot) {
          ++pos;
          swap(&arr[pos],&arr[i]);
        }
    }
    ++pos;
    swap(&arr[pos],pivot);
    _qsort(arr,_begin,pos-1);
    _qsort(arr,pos+1,_end);
    
}

int binary_search(int *arr,int target,int _sizeof){
    int mid,left = 0,right = _sizeof;
    while(left<=right){
        mid = (left + right)/2;
        if(arr[mid] == target) return 1;
        else if(arr[mid] > target) right = mid+1;
        else if(arr[mid] < target) left = mid -1;
        
    }
    return 0;
}
int linear_search(int*arr,int _sizeof,int target){
    for(int i = 0;i<_sizeof;i++) 
        if(arr[i] == target) return 1;
    return 0;
}
int jmp_search(int *arr,int _sizeof,int _key){
   int jump = floor(sqrt(_sizeof));
   int _idx = 0;
   
   while(_idx < _sizeof && (arr[_idx] < _key)){
       if(arr[_idx] == _key) return 1;
       _idx+=jump;
   }
   for(;_idx >= (_idx-jump);_idx--) 
       if(arr[_idx] == _key) return 1;
   return 0;
}
