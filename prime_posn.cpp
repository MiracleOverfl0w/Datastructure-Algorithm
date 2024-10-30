#include<stdio.h>
int main(){
	int mark = 2,n;
	scanf("%d",&n);
	int list[n-2];
	for(int i = 2;i<=n;i++) list[i-2] = i;

	while(mark <= n){
		for(int i = 0;i<n-2 ;i++){
			if(list[i] == 0) continue; 
			if(list[i] % mark == 0 && list[i] != mark) list[i] = 0;	 
		}
		++mark;
	}
	int i,j = 0 ,count[5];
	for(i = 0;i < 5 ;i++) count[i] = 0;
	for(i = sizeof(list)/sizeof(list[0])-1;i>=0 && j<5  ;i--) {
		if(list[i] > 0 && j <5 ){
			count[j] = list[i];
			++j;
		} 
	}
	for(i = sizeof(count)/sizeof(count[0])-1;i>=0;i--) {
		if(count[i] > 0 ) printf("%d ",count[i]);
	}
	
}
