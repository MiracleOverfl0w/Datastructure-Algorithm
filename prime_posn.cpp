#include<stdio.h>
int main(){
	int mark = 2,n;
	scanf("%d",&n);
	int list[n-2];
	for(int i = 2;i<=n;i++) list[i-2] = i;	//printf("%d %d\n",i,list[i-2]);

	while(mark <= n){
		for(int i = 0;i<n-2 ;i++){
			if(list[i] == 0) continue; 
			if(list[i] % mark == 0 && list[i] != mark) list[i] = 0;	 
		}
		++mark;
	}
	int count = 0;

}
