#include <stdio.h>
#include <stdlib.h>

struct node{
  int value;
  struct node * next;
};

struct node * empty_list(){
  return NULL;
}

struct node * add_value(int v, struct node * l){
  struct node * new_node = malloc(sizeof(struct node));
  new_node-> value = v;
  new_node-> next = l;
  return new_node;
}

void print(struct node * l){
  printf("list = [");
  for(struct node * p = l; p; p = p->next){
    printf(p->next?"%d, ":"%d", p->value);
  }
  printf("]");
}


int main(){
  struct node* my_list = empty_list();
  my_list = add_value(1, my_list);
  my_list = add_value(2, my_list);
  my_list = add_value(3, my_list);
  my_list = add_value(4, my_list);
  my_list = add_value(5, my_list);
  print(my_list);
  return 0;
}
