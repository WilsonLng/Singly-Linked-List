#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int item;
    struct node *next;
}ListNode;

typedef struct _linkedList{
    ListNode *head;
    int size;
}LinkedList;

int sizeList(LinkedList *ll);
void printList(LinkedList *ll);
ListNode *findNode(LinkedList *ll, int index);
int insertNode(LinkedList *ll, int index, int value);
int removeNode(LinkedList *ll, int index);

int main(){
    LinkedList ll;
    LinkedList *ptr_ll;

    insertNode(&ll, 0, 100);
    printList(&ll);
    printf("%d nodes\n", ll.size);
    removeNode(&ll, 0);

    ptr_ll = malloc(sizeof(LinkedList));
    insertNode(ptr_ll, 0, 100);
    printList(ptr_ll);
    printf("%d nodes\n", ptr_ll->size);
    removeNode(ptr_ll, 0);

    return 0;
}

int sizeList(LinkedList *ll){
    return ll->size;
}

void printList(LinkedList *ll){
    ListNode *temp = ll->head;

    if(temp == NULL){
        printf("There is nothing yet!");
    }

    while(temp != NULL){
        printf("%d ", temp->item);
        temp = temp->next;
    }
    printf("\n");
}

ListNode *findNode(LinkedList *ll, int index){
    ListNode *temp = ll->head;

    if(temp == NULL || index < 0){
        return NULL;
    }

    while(index > 0){
        temp = temp->next;
        if(temp == NULL){
            return NULL;
        }
        index--;
    }
    return temp;
}

int insertNode(LinkedList *ll, int index, int value){
    ListNode *temp = ll->head, *pre, *cur;

    if(temp == NULL || index == 0){
        cur = temp;
        temp = malloc(sizeof(ListNode));
        temp->item = value;
        temp->next = cur;
        (ll->size)++;
        return 0;
    }

    if((pre = findNode(ll, index-1)) != NULL){
        cur = pre->next;
        pre->next = malloc(sizeof(ListNode));
        pre->next->item = value;
        pre->next->next = cur;
        (ll->size)++;
        return 0;
    }

    return -1;
}

int removeNode(LinkedList *ll, int index){
    ListNode *temp = ll->head, *pre, *cur;

    if(temp == NULL || index < 0){
        return -1;
    }

    if(index == 0){
        cur = temp;
        temp = temp->next;
        free(cur);
        (ll->size)--;
        return 0;
    }

    if((pre = findNode(ll, index-1)) != NULL){
        cur = pre->next;
        pre->next = cur->next;
        free(cur);
        (ll->size)--;
        return 0;
    }

    return -1;
}
