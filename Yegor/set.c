#include "../set.h"
#include <stdlib.h>
#include <stdio.h>
typedef struct node
{
    struct node* next;
    struct node* prev;
    Data value;
} node;
typedef struct array
{
    node* head;
} Array;
Array* Array_init()
{
    Array* a = malloc(sizeof (Array));
    a->head = NULL;
    return a;
}
void Array_destroy(Array* arr)
{
    node * nn = arr->head;
    while (nn)
    {
        node* next = nn->next;
        free(nn);
        nn = next;
    }
    free(arr);
}
void Array_insert(Array* arr, Data value)
{
    node* n = malloc (sizeof(node));
    n->value = value;
    n->next = NULL;
    if (arr->head == NULL)
    {
        arr->head = n;
        n->prev = NULL;
        return;
    }
    node * buf = arr->head;
    while (buf->next)
    {
        buf = buf->next;
    }
    buf->next = n;
    n->prev = buf;
    return;
}
void Array_remove_item(Array* arr, Data value)
{
    if (arr->head == NULL)
    {
        return;
    }
    node* nn = arr->head;

    do
    {
        node* next = nn->next;
        if (nn->value == value)
        {
            if (arr->head == nn)
            {
                arr->head = nn->next;
            }
            if (nn->next)
            {
                nn->next->prev = nn->prev;

            }
            if (nn->prev)
            {
                nn->prev->next = nn->next;
            }
            free(nn);
        }
        nn = next;
    }
    while (nn->next != NULL);
}
int Array_has_item(Array* arr,Data value)
{
    node* nn = arr->head;
    while(nn)
    {
        if (nn->value == value)
        {
            return 1;
        }
        nn = nn->next;
    }
    return 0;
}
ErrCode set_create (Set * set)
{
    *set = (Set*) Array_init();
    if (set == NULL)
        return OUT_OF_RESOURSES;
    return OK;
}
ErrCode set_put (Set s, Data value)
{
    Array* arr = (Array*) s;
    if (Array_has_item(arr,value))
    {
        return OK;
    }
    Array_insert(arr,value);
    return OK;
}
ErrCode set_has (Set set, Data value)
{
    Array* arr = (Array*) set;
    if (Array_has_item(arr,value))
    {
        return OK;
    }
    return WRONG_ARGUMENTS;
}
ErrCode set_remove (Set set, Data value)
{
    Array* arr = (Array*) set;
    Array_remove_item(arr,value);
    return OK;
}
ErrCode set_delete (Set set)
{
    Array* arr = (Array*) set;
    Array_destroy(arr);
    return OK;
}
ErrCode set_dump(Set set)
{
    Array* arr = (Array*) set;
    node* n = arr->head;
    while (n)
    {
        printf("%d\t",n->value);
        n = n->next;
    }
    printf("\n");
    return OK;
}
