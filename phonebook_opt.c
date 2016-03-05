/*#include <stdlib.h>
#include "phonebook_opt.h"

entry *findName(char lastname[], entry *pHead)
{
    while (pHead != NULL) {
        if (strcasecmp(lastname, pHead->lastName) == 0)
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    e->pNext = (entry *) malloc(sizeof(entry));
    e = e->pNext;
    strcpy(e->lastName, lastName);
    e->pNext = NULL;

    return e;
}*/

#include <stdlib.h>
#include "phonebook_opt.h"

entry *findName(char lastName[], entry *pHead)
{
    char judge=lastName[0];
    while (pHead->pNext!=NULL && judge!=pHead->pNext->lastName[0] ) {
        pHead = pHead->pNext;
    }
    if(pHead->pNext==NULL)
        return NULL;
    else if(strcasecmp(lastName, pHead->pNext->lastName) == 0)
        return pHead->pNext;
    else if(judge==pHead->pNext->lastName[0]) {
        pHead=pHead->pNext->child;
        while(pHead!=NULL) {
            if(strcasecmp(lastName, pHead->lastName) == 0) {
                //printf("%s\n",pHead->lastName);
                return pHead;
            }
            pHead=pHead->pNext;
        }
        return NULL;
    }
}


entry *append(char lastName[], entry *e)
{
    entry *init=e;
    int remembernext=0;
    char judge=lastName[0];
    if(e->pNext!=NULL)
        remembernext=1;
    while(e->pNext!=NULL&&judge!=e->pNext->lastName[0]) {
        e = e->pNext;
    }
    if(e->pNext==NULL) {
        e->pNext=(entry *) malloc(sizeof(entry));
        strcpy(e->pNext->lastName, lastName);
        e->pNext->pNext=NULL;
    } else if(judge==e->pNext->lastName[0]) {
        e=e->pNext;
        if(e->child==NULL) {
            e->child = (entry *) malloc(sizeof(entry));
            strcpy(e->child->lastName, lastName);
            e->child->pNext=NULL;
        } else {
            entry *tmp=(entry *) malloc(sizeof(entry));
            strcpy(tmp->lastName, lastName);
            tmp->pNext=e->child;
            e->child=tmp;
        }
    }
    return init;
}

