#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define sizemap 5
size_t hash(char *str){
    size_t hash_val = 0;
    for(size_t i = 0;i<strlen(str);i++)
        hash_val+=((str[i]) * 33 );
    return hash_val % sizemap;
}
typedef struct {
   char * __key__;
   int __val__;
   struct table_node * __next__;
}table_node;
typedef table_node* hashmap;
hashmap init(){
   hashmap temp = (hashmap)malloc(sizeof(table_node) * sizemap);
   if(!temp) return NULL;
   for(size_t i = 0;i<sizemap;i++){
       temp[i].__key__ = NULL;
       temp[i].__val__ = 0;
       temp[i].__next__ = NULL;
   }  
   return temp;  
}
void free_map(hashmap __garbg){
   for(size_t i = 0;i<sizemap;i++){
        table_node *current = __garbg[i].__next__;
        while (current != NULL) {
            table_node *temp = current;
            current = current->__next__;
            free(temp->__key__);
            free(temp);
        }
        free(__garbg[i].__key__);
   }
   free(__garbg);
}
void add(hashmap __Map,char* __key,int __val){
      size_t _idx = hash(__key);
      if(!__Map[_idx].__key__) {
         __Map[_idx].__key__ = strdup(__key);
         __Map[_idx].__val__ = __val;
      }
      else{
         hashmap temp = (hashmap)malloc(sizeof(table_node));
         hashmap curnt = &__Map[_idx];
         temp->__val__ = __val;
         temp->__key__ = strdup(__key);
         temp->__next__ = NULL;
         while(curnt->__next__ != NULL){
             curnt = curnt->__next__ ;
         }
         curnt->__next__ = temp;
      }
}
char** get_key(hashmap _table,int* count){
    
    char **keys = malloc(sizeof(char*) * sizemap * 2);
    int _idx = 0;
    
    for (size_t i = 0; i < sizemap; i++) {
        if (_table[i].__key__ != NULL) {
            keys[_idx++] = _table[i].__key__;
            table_node *current = _table[i].__next__;
            while (current != NULL) {
                keys[_idx++] = current->__key__;
                current = current->__next__;
            }
        }
    }
    *count = _idx;
    return keys;
}

int get_value(hashmap _table,char * _key){
    size_t _idx = hash(_key);
    if(_table[_idx].__key__ == NULL){
        fprintf(stderr,"\n---> cannot find value from this map");
        exit(1);
    }
    else if(strcmp(_table[_idx].__key__,_key) == 0)
    {
           return _table[_idx].__val__;
    }       
    else{
        hashmap current = &_table[_idx];
        while(current->__next__ != NULL){
            if(strcmp(current->__key__,_key) == 0) return current->__val__;
            current = current->__next__;
        }
        fprintf(stderr,"\n---> cannot find value from this map");
        exit(1);
    }
}
int main() {
    hashmap HashMap = init();
    add(HashMap, "hello", 22);
    add( HashMap,"olleh",1000);
      free_map(HashMap);
    return 0;
}
