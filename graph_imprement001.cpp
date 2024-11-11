#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node_graph{
	int data;
	struct graph* egde; 
}graph;
graph * build_node(){
	graph * __c = (graph*)malloc(sizeof(graph));
	__c->data = 0;
	__c->edge = NULL;
}
graph * init(int * list,int * val,int size){
	graph * _start;
	graph *node[size];
	for(int i = 0;i<size;i++) node[i] = build_node();
	for(int i = 0;i < size ; i++){
		for(int j = i+1;j < size ; j++){
		
		}	
	}
	return 
}
int main(){
	
	const int graph_cnt = 4;
	int graph[graph_cnt][graph_cnt];
	int val[graph_cnt][graph_cnt];
	for(int i = 0;i<graph_cnt;i++)
		scanf("%d %d %d %d",&graph[i][0],&graph[i][1],&graph[i][2],&graph[i][3]); //edge
	printf("-----------------------------------------\n");
	for(int i = 0;i<graph_cnt;i++)
		scanf("%d %d %d %d",&val[i][0],&val[i][1],&val[i][3],&val[i][4]); //assign
	
	/*
		printf("-----------------------------------------\n");
		for(int i = 0;i<graph_cnt;i++)
			printf("%d %d %d %d\n",graph[i][0],graph[i][1],graph[i][2],graph[i][3]); //edge
		printf("-----------------------------------------\n");
		for(int i = 0;i<graph_cnt;i++)
			printf("%d %d %d %d\n",val[i][0],val[i][1],val[i][2],val[i][3]); //assign
	*/
		
	
	return 0;
}
