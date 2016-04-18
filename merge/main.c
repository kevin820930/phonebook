#include "merge.c"
#include <stdio.h>
#include <stdlib.h>
int main()
{
List *head = (List *) malloc(sizeof(List));
List *new = (List *) malloc(sizeof(List));
new->value=45;
head->next=new;
List *new1 = (List *) malloc(sizeof(List));
new->next=new1;
new1->value=76;
List *new2 = (List *) malloc(sizeof(List));
new2->value=31;
new1->next=new2;
new2->next=NULL;
List *new3 = (List *) malloc(sizeof(List));
new3->value=88;
new2->next=new3;
new3->next=NULL;

printf("hi\n");
List *count;
for(count=head->next;count!=NULL;count=count->next){
printf("%d \n",count->value);
}
head=merge_sort(head);
for(count=head->next;count!=NULL;count=count->next){
printf("%d \n",count->value);
}
}
