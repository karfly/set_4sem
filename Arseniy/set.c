#include "set.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node* create_List() {
    Node *head = NULL;
    head = (Node*) malloc(sizeof(Node));
    head->next = NULL;
    return head;
}

void put_el_to_List(Node *head, void* value) {
    Node *ins;
    Node *tmp = head;
    while(tmp->next)
        if(tmp->value <= (int*)value){
            if( tmp->value == (int*) value){
                goto end;
            }
            tmp = tmp->next;
        }
        else{
            ins = (Node*) malloc(sizeof(Node));
            ins->value = (int*) value;
            ins->next = tmp->next;
            tmp->next = ins;
            goto end;
        }
    ins = (Node*) malloc(sizeof(Node));
    ins->value = (int*) value;
    tmp->next = ins;
    ins->next = NULL;
    end: ;
}

int has_el_from_List(Node *head, void* value){
    Node *tmp = head;
    while( tmp->next){
        if( tmp->value == (int*) value){
            return 1;
        }
        tmp = tmp->next;
    }
    return 0;
}

int remove_el_from_List(Node *head, void* value){
    Node *tmp = head->next;
    Node *prev = head;
    if( tmp )
        while( tmp->next){
            if( tmp->value == (int*) value){
                free(tmp);
                prev->next = tmp->next;
                return 1;
            }
            tmp = tmp->next;
        }
    if( prev )
        if( prev->value == (int*) value){
            free(prev);
            head = NULL;
            head->next = NULL;
            return 1;
        }
    return 0;
}

int pop(Node *head) {
    Node* prev = NULL;
    int val;
    if (head == NULL) {
        exit(-1);
    }
    prev = head;
    val = prev->value;
    head = head->next;
    free(prev);
    return val;
}

void deleteList(Node *head) {
    while (head->next) {
        pop(head);
        head = head->next;
    }
    free(head);
}

ErrCode set_create (Set * s){
    *s = (Node*) create_List();
    if (s == NULL)
        return OUT_OF_RESOURSES;
    return OK;
}

ErrCode set_put (Set s, Data value){
    Node* list = (Node*) s;
    if (has_el_from_List(list, value)){
        return OK;
    }
    put_el_to_List(list, value);
    return OK;
}

ErrCode set_has (Set s, Data value){
    Node* list = (Node*) s;
    if (has_el_from_List(s, value)){
        return OK;
    }
    return WRONG_ARGUMENTS;
}

ErrCode set_remove (Set s, Data value){
    Node* list = (Node*) s;
    if(remove_el_from_List(s, value))
        return OK;
}
ErrCode set_delete (Set * s)
{
    Node* list = (Node*) s;
    deleteList(list);
    return OK;
}
ErrCode set_dump(Set s)
{
    Node* tmp = (Node*) s;
    while (tmp)
    {

        printf("%d ",tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
    return OK;
}

