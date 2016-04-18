#include "swap.c"
List *merge_sort(List *head)
{
    if (head == NULL)
        return head;
    List *count=head;
    count=head;
    int n;
    if(count->next->next==NULL)
	return head;
    for(n=0;count->next->next!=NULL;count=count->next)
    n++;
    count=(head);
    List *lefthead = (head);
    List *righthead = (List *) malloc(sizeof(List));
    int a;
    for(a=0;a<n+2;a++,count=count->next){
        if(a==(n+1)/2){
	righthead->next=count->next;
	count->next=NULL;
	a=n+2;
	}
    }
    lefthead=merge_sort(lefthead);
    righthead=merge_sort(righthead);
    List *newline = (List *) malloc(sizeof(List));
    List *newhead = newline;
    int leftnum,rightnum;
    lefthead=lefthead->next;
    righthead=righthead->next;
    leftnum=lefthead->value;
    rightnum=righthead->value;
    for(a=1;a<n+2;a++){
        if(leftnum<=rightnum){
	    newline->next=lefthead;
	    newline=newline->next;
	    lefthead=lefthead->next;
	    if(lefthead==NULL)
		leftnum=99999;
	    else
    	        leftnum=lefthead->value;
	}
        else if(leftnum>rightnum){
	    newline->next=righthead;
            newline=newline->next;
	    righthead=righthead->next;
            if(righthead==NULL)
                rightnum=99999;
            else
                rightnum=righthead->value;
	}
    }
    newline->next=NULL;
    return newhead;
}
