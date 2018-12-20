#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;
  struct node * next;  
};

struct node * empty_list(){
  return NULL;
}

struct node* add_value(int v, struct node * list){
  struct node* new_node = (struct node*) malloc(sizeof(struct node));
  new_node->value = v;
  new_node->next = list;
  return new_node;  
}

void print_list (struct node* l){
  printf("list = [");
  for(struct node* p = l; p; p = p->next){
    printf(p->next?"%d, ":"%d", p->value);
  }
  printf("]\n");
}

int main (){
  struct node* my_list = empty_list();
  my_list = add_value(1, my_list);
  my_list = add_value(2, my_list);
  my_list = add_value(3, my_list);
  my_list = add_value(4, my_list);
  my_list = add_value(5, my_list);
  print_list(my_list);
  return 0;
}
