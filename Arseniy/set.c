#include "set.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node* create_List() {
    Node* head = (Node*) malloc(sizeof(Node));
    head->next = NULL;
    return head;
}

void put_el_to_List(Node *head, void* value) {
    Node* tmp = head;
    while(tmp->next){
        tmp = tmp->next;
    }
    Node* ins = (Node*) malloc(sizeof(Node*));
    ins->next = NULL;
    tmp->value = (int*) value;
    tmp->next = ins;
}

int has_el_from_List(Node *head, void* value){
    Node *tmp = head;
    while( tmp->next ){
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
    if( head->next){
        if( head->value == (int*) value){
            while(tmp->next){
                prev->value = tmp->value;
                prev = prev->next;
                tmp = tmp->next;
            }
            free(tmp);
            prev->next = NULL;
            return 1;
        }
    }
    while(tmp->next){
        if( tmp->value == (int*) value){
            prev->next = tmp->next;
            free(tmp);
            return 1;
        }
        tmp = tmp->next;
        prev = prev->next;
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
    while (tmp->next)
    {
        printf("%d ",tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
    return OK;
}
