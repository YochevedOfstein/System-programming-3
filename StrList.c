#include "StrList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct StrListNode{
    char* _data;
    struct StrListNode* _next;
}StrListNode;

typedef struct _StrList{
    StrListNode* _head;  
    size_t _size;
}StrList;

StrListNode* Node_alloc(const char* data, StrListNode* next ){
    StrListNode* newnode = (StrListNode*)malloc(sizeof(StrListNode));
    newnode->_data = strdup(data);
    newnode->_next = 0;

    return newnode;
}

void Node_free(StrListNode* Node){
    free(Node);
}

StrList* StrList_alloc(){
    StrList* newlist = (StrList*)malloc(sizeof(StrList));
    newlist->_head = NULL;
    newlist->_size = 0;

    return newlist;
}

void StrList_free(StrList* StrList){
    if(StrList == NULL || StrList->_head == NULL){
        return;
    }
    if(StrList->_head){
        free(StrList->_head);
    }
    free(StrList);
}

size_t StrList_size(const StrList* StrList){
    return StrList->_size;
}

void StrList_insertLast(StrList* StrList, const char* data){
    if(StrList == NULL){
        StrList->_head = Node_alloc(data, StrList->_head);
        (StrList->_size)++;
        return;
    }
    StrListNode* newNode = (StrListNode*)malloc(sizeof(StrListNode));
    newNode->_next = NULL;

    newNode->_data = strdup(data);

    if(StrList->_head == NULL){
        StrList->_head = newNode;
    }
    
    else{
        StrListNode* n = StrList->_head;
        while(n->_next != NULL){
            n = n->_next;
        }
            n->_next = newNode;
    }

    (StrList->_size)++;
}

void StrList_insertAt(StrList* StrList, const char* data,int index){
    if(StrList == NULL){
        printf("Empty list");
        return;
    }
    StrListNode* newnode = (StrListNode*)malloc(sizeof(StrListNode));
    newnode->_data = strdup(data);

    if(index == 0){
        newnode->_next = StrList->_head;
        StrList->_head = newnode;
    }
    else{
        int count = 0;
        StrListNode* current = StrList->_head;
        StrListNode* previous = NULL;

        while(count != index){
            previous = current;
            current = current->_next;
            count++;
        }
        previous->_next = newnode;
        newnode->_next = current;
    }
    StrList->_size = StrList->_size + 1;
}


char* StrList_firstData(const StrList* StrList){
    if((StrList->_head == NULL) || (StrList == NULL)){
        return "No firstData";
    }

    return StrList->_head->_data;
}

void StrList_print(const StrList* StrList){
    StrListNode* n = StrList->_head;
    if(n == NULL){
        printf("\n");
        return;
    }
    while(n->_next){
        printf("%s ", n->_data);
        n = n->_next;
    }
    printf("%s", n->_data);
    printf("\n");
}

void StrList_printAt(const StrList* Strlist,int index){
    if(Strlist == NULL || Strlist->_head == NULL){
        printf("Empty list");
        return;
    }

    int count = 0;
    StrListNode* n = Strlist->_head;

    while(count != index){
        n = n->_next;
        count++;
    }

    printf("%s\n", n->_data);
}

int StrList_printLen(const StrList* Strlist){
    if(Strlist == NULL || Strlist->_head == NULL){
        return 0;
    }
    int count = 0;
    StrListNode* current = Strlist->_head;
    while(current != NULL){
        count = count + strlen(current->_data);
        current = current->_next;
    }
    return count;
}

int StrList_count(StrList* StrList, const char* data){
    if(StrList == NULL || StrList->_head == NULL){
        return 0;
    }
    StrListNode* current = StrList->_head;
    int count = 0;
    while(current != NULL){
        if(strcmp(current->_data, data) == 0){
            count++;
        }
        current = current->_next;
    }
    return count;
}

void StrList_remove(StrList* StrList, const char* data){
    if(StrList == NULL || StrList->_head == NULL){
        printf("Empty list");
        return;
    }
    StrListNode* current = StrList->_head;
    StrListNode* previous = NULL;
    while(current != NULL){
        if(strcmp(current->_data, data) == 0){
            if(previous == NULL){
                StrList->_head = current->_next;
                free(current);
                StrList->_size = StrList->_size -1; 
                current = StrList->_head;
            }
            if(current->_next == NULL){
                free(current);
                StrList->_size = StrList->_size -1; 
                break;
            }
            else{
                previous->_next = current->_next;
                free(current);
                StrList->_size = StrList->_size -1; 
                current = previous->_next;
            }
        }
        else{
            previous = current;
            current = current->_next;
        }
    }
}

void StrList_removeAt(StrList* StrList, int index){
    if(StrList == NULL || StrList->_head == NULL){
        printf("Empty list");
        return;
    }
    if(index >= StrList->_size){
        printf("Out of bounds");
        return; 
    }

    int count = 0;
    StrListNode* current = StrList->_head;
    StrListNode* previous = NULL;

    while(count != index){
        previous = current;
        current = current->_next;
        count++;
    }
    if(previous == NULL){
        StrList->_head =  current->_next; 
    }
    else{
        previous->_next = current->_next;
    }
    free(current->_data);
    free(current);
    StrList->_size = StrList->_size -1;
}

int StrList_isEqual(const StrList* StrList1, const StrList* StrList2){
    const StrListNode* n1 = StrList1->_head;
    const StrListNode* n2 = StrList2->_head;
    while(n1 != NULL){
        if(n2 == NULL||strcmp(n1->_data, n2->_data) != 0){
            return 0;
        }
        n1 = n1->_next;
        n2 = n2->_next;
    }
    if(n2 != NULL){
        return 0;
    }
    return 1;
}

StrList* StrList_clone(const StrList* StrList){
    struct _StrList* list = StrList_alloc();
    const StrListNode* old = StrList->_head;
    StrListNode* *copy = &(list->_head);
    list->_size = StrList->_size;
    while(old){
        *copy = Node_alloc(old->_data, NULL);
        old = old->_next;
        copy = &((*copy)->_next);
    }
    return list;
}

void StrList_reverse( StrList* StrList){
    if(StrList == NULL || StrList->_head == NULL ||StrList->_head->_next == NULL){
        return;
    }
    StrListNode* current = StrList->_head;
    StrListNode* previous = NULL;
    StrListNode* next = NULL;
    while(current != NULL){
        next = current->_next;
        current->_next = previous;
        previous = current;
        current = next;
    }
   StrList->_head = previous; 
}

void StrList_sort( StrList* StrList){
    if(StrList == NULL || StrList->_head == NULL || StrList->_head->_next == NULL){
        return;
    }
    int swap = 1;
    char* temp;
    StrListNode* current = StrList->_head;
    StrListNode* nextNode = NULL;

    while(swap == 1){
        current = StrList->_head;
        swap = 0;
        while(current->_next != nextNode){
            if(strcmp(current->_data, current->_next->_data) > 0){
                temp = current->_data;
                current->_data = current->_next->_data;
                current->_next->_data = temp;
                swap = 1;
            }
            current = current->_next; 
        }
        nextNode = current;
    }  
}

int StrList_isSorted(StrList* StrList){
    if(StrList == NULL || StrList->_head == NULL || StrList->_head->_next == NULL){
        return 1;
    }
    StrListNode* current = StrList->_head;
    StrListNode* nextNode = current->_next;
    while(nextNode != NULL){
        if(strcmp(current->_data, nextNode->_data) > 0){
            return 0;
        }
        current = current->_next;
        nextNode = nextNode->_next;
    }
    return 1;
}


