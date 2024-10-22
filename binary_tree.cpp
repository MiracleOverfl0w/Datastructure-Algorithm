#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

struct tree{
    int data;
    tree* left = nullptr;
    tree* right= nullptr;
};

void DFS(tree* root);
void BFS(tree* root);

bool tree_include (tree* root,int target);
bool BFS_search(tree *root,int target);

int treesum_DFS(tree* root);
int treesum_BFS(tree* root); 

int mintree(tree* root);
int maxpath(tree* root);
int main()
{
    
    tree a={20},b = {2} ,c = {3},d = {4},e = {5},f={6};
    // root = a
    
    tree* t=&a;
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.left = &f;
    
    //cout<<treesum_BFS(&a) <<"  "<<treesum_DFS(&a) ;
    int input;
    cout<< maxpath(t) <<endl;
    /*
          a 1
       /      \
       b  2        c 3
    /    \      /.  \
   d 4    e5     f 6   
    
    
    ans : 1 2 4 5 3 6 
    */
    
    return 0;
}
void DFS(tree* root){
    
    if(root != nullptr )
    {
       cout << root->data<<  " ";
       DFS(root->left);
       DFS(root->right);
    }
    
}
bool tree_include(tree* root,int target){
   if(root==nullptr) return false;
   if(root->data==target) return true;
   
   return tree_include(root->left,target) || tree_include(root->right,target);
   
}



void BFS(tree* root){
   queue<tree*> qt;
   qt.push(root);
   tree* current = nullptr;
   cout<< "[";
   while(!qt.empty()){
       current = qt.front();
       
       cout << current->data << ", " ;
       if (current->left != nullptr) qt.push(current->left);
       if (current->right!= nullptr) qt.push(current->right);
       qt.pop();
   }
   
   cout << "]" << endl;
}
bool BFS(tree* root,int target){
   queue<tree*> qt;
   qt.push(root);
   tree* current = nullptr;
   while(!qt.empty()){
       current = qt.front();
       
       if(current->data == target) return true;
       if (current->left != nullptr) qt.push(current->left);
       if (current->right!= nullptr) qt.push(current->right);
       qt.pop();
   }
   
   return false;
}
int treesum_DFS(tree* root){ 

    if (root == nullptr) return 0;
    return root->data+treesum_DFS(root->left)+treesum_DFS(root->right);
    
}
int treesum_BFS(tree* root){
    queue<tree*> q;
    q.push(root);
    tree* current;
    int result = 0;
    while(!q.empty()){
        current = q.front();
        result+=current->data;
        if(current->left!= nullptr) q.push(current->left);
        if(current->right!=nullptr) q.push(current->right);
        q.pop();
    }
    return result;
}

int mintree(tree* root){
    
    if (root == nullptr) return 10000000;
    vector<int> v{root->data,mintree(root->left),mintree(root->right)};
    sort(v.begin(),v.end());
    return v[0];
}

int maxpath(tree* root){
    if(root==nullptr) return -1000000;
    if (root->left == nullptr && root->right == nullptr) return root->data;
    return root->data+max(maxpath(root->left),maxpath(root->right));
