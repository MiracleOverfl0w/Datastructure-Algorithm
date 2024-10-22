#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
typedef struct node{
	int data_int;
	int mark_INDEX;
	struct node* next_link = NULL;
	struct node* pre_link = NULL;
}node;




node* CreateTempNode();
node* slyLinked();
node* slyLinked(int count);
node* slyLinked(int count,int data[]);
node* CirLinked();
void  ReMem(node* Delete);
void  add(node* _linkedlist,node* _nodeData);
void  add(node* _linkedlist,int _data);
void  setValue(node* likedlist,int position,int value);
node* CreateTempNode(){
	return (node*)malloc(sizeof(node));
}
void  ReMem(node* Delete){
	free(Delete);
}
void display(node* show){
	while(show != NULL){
		printf("%d # %d #  -> ",show->mark_INDEX,show->data_int);
		show = show->next_link;
		getch();
	}	
}
void  add(node* _linkedlist,node* _nodeData){
	while(_linkedlist->next_link != NULL) _linkedlist = _linkedlist->next_link;
	_linkedlist->next_link = _nodeData; 
}
void  setValue(node* likedlist,int position,int value){
	node* point = likedlist;
	while(point->mark_INDEX != position) point = point->next_link;
	point->data_int = value;
}

node* slyLinked(){
	node *HEAD = NULL,*Current = NULL;
	Current = CreateTempNode();
	Current->mark_INDEX = 1;
	Current->data_int = 0;
	Current->next_link = NULL;
	if (HEAD == NULL) HEAD = Current;
	else return NULL;
	return HEAD;
}
node* slyLinked(int count){
	node *HEAD = NULL,*Fix_in_HEAD = NULL,*Current = NULL;
	for(int i = 0;i<count;i++ )
	{
		Current = CreateTempNode();
		Current->data_int = 0;
		Current->mark_INDEX = i+1;
		Current->next_link = NULL;
		if (HEAD == NULL) HEAD = Current;
		else add(HEAD,Current);
	}
	return HEAD;
}
node* slyLinked(int count,int data[]){
	node *HEAD = NULL,*Current = NULL;
	int *Pdata = &data[0];
	for(int i = 0;i<count;i++ )
	{
		Current = CreateTempNode();
		Current->data_int = *(Pdata + i);
		Current->mark_INDEX = i+1;
		Current->next_link = NULL;
		
		if (HEAD == NULL) HEAD = Current;
		else add(HEAD,Current);	
	}
	return HEAD;
}
node* CirLinked(int count){
	node *HEAD = NULL,*Current = NULL,*keepAd = NULL;
	Current = CreateTempNode();
	Current->data_int = 0;
	Current->mark_INDEX = 1;
	keepAd = Current;
	for (int i = 2;i<count;i++){
	
		if(HEAD == NULL) HEAD = Current;
		else add(HEAD,Current);
	}
	return HEAD;
}
