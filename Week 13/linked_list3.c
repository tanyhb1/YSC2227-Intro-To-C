#include <stdio.h>
#include <stdlib.h>

struct node{
  int v;
  struct node* next;
};

struct node* empty_list(){
  return NULL;
}

struct node* add_value(int v, struct node* list){
  struct node* new_node = (struct node*) malloc(sizeof(struct node));
  new_node->v = v;
  new_node->next = list;
  return new_node;  
}

void print(struct node* list){
  printf("list = [");
  for(struct node* p = list; p; p = p->next){
    printf(p->next?"%d, ":"%d", p->v);
  }
  printf("]");
}

void print_rec(struct node* list){
  if (list->next){
    printf("%d, ", list->v);
    print_rec(list->next);
  }
  else{
    printf("%d]\n", list->v);
  }

}
int main(){
  struct node* my_list = empty_list();
  my_list = add_value(1, my_list);
  my_list = add_value(2, my_list);
  my_list = add_value(3, my_list);
  my_list = add_value(4, my_list);
  my_list = add_value(5, my_list);
  print_rec(my_list);
  return 0;
}
