#include <stdio.h>
#include <stdlib.h>
#include "list.h"


BOOL L_init(LIST *pList) {
    if (pList == NULL)
        return False;    // no list to initialize

    pList->head.next = NULL;
    return True;
}


NODE *L_insert(NODE *pNode, DATA Value) {
    NODE *tmp;

    if (!pNode)
        return NULL;

    tmp = (NODE *) malloc(sizeof(NODE));    // new node

    if (tmp != NULL) {
        tmp->key = Value;
        tmp->next = pNode->next;
        pNode->next = tmp;
    }
    return tmp;
}


BOOL L_delete(NODE *pNode, void(*freeFunction(void *))) {
    NODE *tmp;
    if (!pNode)
        return False;
    tmp = pNode->next;
    if (!tmp)
        return False;

    pNode->next = tmp->next;
    if (freeFunction != NULL)
        freeFunction(tmp);
    free(tmp);
    return True;
}


NODE *L_find(NODE *pNode, DATA Value) {
    NODE *tmp = pNode;

    while (tmp != NULL) {
        if (tmp->key == Value)
            return tmp;
        tmp = tmp->next;
    }

    return NULL;
}


BOOL L_free(LIST *pList, void (*freeFunction)(void *)) {
    NODE *tmp;
    BOOL cont = True;
    if (!pList)
        return False;

    tmp = &(pList->head);
    while (cont)
        cont = L_delete(tmp, freeFunction);

    return True;
}


int L_print(LIST *pList, void(*print)(const void *)) //Genery print
{
    NODE *tmp;
    int c = 0;

    if (!pList)
        return False;

    printf("\n");
    tmp = pList->head.next;
    while (tmp != NULL) {
        print(" %d ---> ", tmp->key);
        c++;
        tmp = tmp->next;
    }
    printf("\n");
    return c;
}
