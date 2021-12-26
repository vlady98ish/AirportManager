#include <stdio.h>
#include <stdlib.h>
#include "list.h"

#include "Date.h" //TODO added because of compareDates in l_find


//////////////////////////////////////////
// Init
// Aim:		create new list
// Input:	pointer to the list structure
// Output:	TRUE if succeeded
//////////////////////////////////////////
BOOL L_init(LIST *pList) {
    if (pList == NULL) return False;    // no list to initialize
    pList->head.next = NULL;
    return True;
}


/////////////////////////////////////////////////////////////////
// Insert
// Aim:		add new node
// Input:	pointer to the node BEFORE the place for the new one
//			a value to be stored in the new node
// Output:	pointer to the new node
/////////////////////////////////////////////////////////////////
NODE *L_insert(NODE *pNode, DATA Value) {
    NODE *tmp;
    if (!pNode) return NULL;
    tmp = (NODE *) malloc(sizeof(NODE));    // new node
    if (tmp != NULL) {
        tmp->key = Value;
        tmp->next = pNode->next;
        pNode->next = tmp;
    }
    return tmp;
}

int L_insertInCorrectPlace(NODE *head, DATA Value, int (*compareDate)(const void *,
                                                                      const void *)) //TODO function to insert a date in correct place
{
    NODE *pHead = head;

    if (L_find((head->next), Value, compareDates) != NULL) return 1;

    while (1) {
        if ((pHead->next == NULL) || (compareDate(Value, pHead->next->key) == -1)) {
            L_insert(pHead, Value);
            break;
        }

        if (compareDate(Value, pHead->next->key) == 1) pHead = pHead->next;
    }
    return 0;
}


//////////////////////////////////////////////////////////////
// Delete
// Aim:		erase node
// Input:	pointer to the node BEFORE the node to be deleted
// Output:	TRUE if succeeded
//////////////////////////////////////////////////////////////
BOOL L_delete(NODE *pNode, void (*freeFunc)(void *)) {
    NODE *tmp;

    if (!pNode || !(tmp = pNode->next)) return False;

    pNode->next = tmp->next;
    if (freeFunc != NULL)
        free(tmp);

    return True;
}


/////////////////////////////////////////////////////////
// Find
// Aim:		search for a value
// Input:	pointer to the node to start with
//			a value to be found
// Output:	pointer to the node containing the Value
/////////////////////////////////////////////////////////
NODE *L_find(NODE *pNode, DATA value, int(*compare)(const void *, const void *)) {
    NODE *temp = NULL;
    if (!pNode) return NULL;
    while (pNode != NULL) {
        if (compare(pNode->key, value) == 0) {
            temp = pNode;
            break;
        }
        pNode = pNode->next;
    }

    return temp;


}


////////////////////////////////////////////////
// Free (additional function)
// Aim:		free the list memory
// Input:	pointer to the list structure
// Output:	TRUE if succeeded
////////////////////////////////////////////////
BOOL L_free(LIST *pList, void (*freeFunc)(void *)) { //TODO do not forget to add in MAIN free for list
    NODE *tmp;

    if (!pList) return False;
    tmp = &pList->head;
    BOOL res = True;
    while (res) {
        res = L_delete(tmp, freeFunc);
    }

    return True;
}


////////////////////////////////////////////////
// Print (additional function)
// Aim:		print the list content (assume the DATA is int)
// Input:	pointer to the list structure
// Output:	a number of the printed elements
////////////////////////////////////////////////
int L_print(const LIST *pList, void(*print)(void *)) {
    NODE *tmp;
    int c = 0;

    if (!pList) return 0;

    printf("\n");
    for (tmp = pList->head.next; tmp; tmp = tmp->next, c++)
        print(tmp->key);
    printf("\n");
    return c;
}


