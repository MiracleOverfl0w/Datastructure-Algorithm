#include<iostream>
#include<queue>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unordered_map>
using namespace std;
typedef struct node{
	int weight;
	char letter;
	struct node* left;
	struct node* right;
}node;


struct Compare {
    bool operator()(node* a, node* b) {
        return a->weight > b->weight; 
    }
};

node* huffman_Tree(priority_queue<node*,vector<node*>,Compare> &pq);
void kill(node* __kill);
node *init(int _weight,short int _letter);
void compress(node* t,unordered_map<char,string> &map,string bit);
char extrct(string path,string bit);
int main()
{
   priority_queue<node*,vector<node*>,Compare> pq;
   
   const int size = 128;
   int ascii_table[size],count = 0,i,j;
   size_t count_char = 1000;
   char* ch = (char*)malloc(count_char);
   char temp;
   fgets(ch,1000,stdin);
   int len = strlen(ch);
   ch = (char*)realloc(ch,len);
   len = strlen(ch);
   for(i= 0; i<size;i++) ascii_table[i] = 0;
   for(i = 0;i<len;i++){
   	 temp = ch[i];
   	ascii_table[(int)temp]++;	
   }
  for(i = 0;i<size;i++){
        if(ascii_table[i]>0) 
        { 
        	pq.push(init(ascii_table[i],i));
        	count++;
        }
  }
  
 node* huffman_tree = huffman_Tree(pq);
 node* traversal= NULL; 
 unordered_map<char,string> code;

 
 compress(huffman_tree,code,"");
 string binary_compress = "";
 for(i=0;i<len;i++){
 //	if(ch[i] == '\n') printf("compress  enter :    %s\n",code[ch[i]].c_str());
 	//else printf("compress  %c   :    %s\n",ch[i],code[ch[i]].c_str());
 	binary_compress+=code[ch[i]];
 }
 printf("compress to binary -->:%s\n",binary_compress.c_str());
 
 //extract
 printf("original  : %s",ch);
 printf("extract   : ");
 while(j<binary_compress.length()){
 	traversal = huffman_tree;
 	
 	while(traversal->left != NULL || traversal->right != NULL){
 		if(binary_compress[j]=='0'){
 			traversal = traversal->left;	
 		}
 		else{
 				traversal = traversal->right;	
 		}
 		++j;
 	} 
 	printf("%c",traversal->letter );
 }

 //free for protect memmory leke
 kill(huffman_tree);
 free(huffman_tree);
 free(huffman_tree);
 free(ch);
 return 0;
}
node* init(int _wight,short int _letter)
{
	 node* pnode = (node*)malloc(sizeof(node));
	 pnode->weight = _wight;
	 pnode->left =  NULL;
	 pnode->right= NULL;
	 if(_letter == -1) pnode->letter =  '\0';
	 else pnode->letter =  (char)_letter;
	 return pnode;
}
node* huffman_Tree(priority_queue<node*,vector<node*>,Compare> &pq)
{
	while(!pq.empty() && pq.size() >1)
	{ 
	    node* l = pq.top();
	    pq.pop();
	    node* r = pq.top();
	    pq.pop();
	    node* newNode = init(r->weight+l->weight,-1);
	    newNode->left = l;
	    newNode->right = r;
	    pq.push(newNode);
	}
	return pq.top();
}


void compress(node* t,unordered_map<char,string> &map,string bit)
{
	    if(t ==  NULL) return;
		if(t->letter != '\0') map[t->letter] = bit;
		compress(t->left,map,bit +"0");
		compress(t->right,map,bit+"1");
}
void kill(node* __kill){
	if(__kill!=NULL){
		kill(__kill->left);
		kill(__kill->right);
		free(__kill);
	}
}