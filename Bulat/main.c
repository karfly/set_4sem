#include "set.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct set_h set_h;
typedef struct list list;

set_h {
    list* head;
    int (*compare_f) (const Data, const Data);
};

list {
    list* next;
    Data data;
};

ErrCode set_create (Set * set_ptr, int (*compar)(const Data, const Data))
{

    if ( (!set_ptr) || (!compar)
        return WRONG_ARGUMENTS;

    set_h * set_new = (struct setik*) calloc (1, sizeof(struct setik));

    if (!set_new)
        return OUT_OF_RESOURSES;

    set_new->head = NULL;
    set_new->compare_func = compar;

    *set_ptr = set_new;

};



ErrCode set_put (Set set_ls, Data data)
{

    if ( (!set_ls) || (!data) )
        return WRONG_ARGUMENTS;

    set_h* set = (set_h*) set_ls;

    if (set->head == NULL){

        list* ls = (list*) calloc (1, sizeof(list));

        if (!ls)
            return OUT_OF_RESOURCES;

        ls->next = NULL;
        ls->data = data;

        return OK;

    }
    else
    {

        list* ptr = set->head;

        while (!ptr)
        {

            res = set->compare_f (ptr->data, data);

            if (!res)
                return OK;
            else
            {
                ptr = ptr->next;
            }

        }

        ptr = (list*) calloc (1, sizeof(list));

        ptr->next = NULL;
        ptr->data = data;

        if (!ptr)
            return OUT_OF_RESOURSES;

        return OK;

    }
};


ErrCode set_has (Set set_ls, Data data)
{

    if ( (!set_ls) || (!data) )
        return WRONG_ARGUMENTS;

    set_h* set = (set_h*) set_ls;

    if (set->head == NULL){

        return WRONG_ARGUMETS;

    }
    else
    {

        list* ptr = set->head;

        while (!ptr)
        {

            res = set->compare_f (ptr->data, data);

            if (!res)
                return OK;
            else
                ptr = ptr->next;

        }

        return WRONG_ARGUMENTS;

    }

};


ErrCode set_remove (Set, Data)
{

    if ( (!set_ls) || (!data) )
        return WRONG_ARGUMENTS;

    set_h* set = (set_h*) set_ls;

    if (set->head == NULL){

        return WRONG_ARGUMETS;

    }
    else
    {

        list* ptr = set->head;
        list* bptr = set;
        list* temp;

        while (!ptr)
        {

            res = compare_f (ptr->data, data);
            if (!res)
            {
                temp = ptr;
                bptr->next = ptr->next;
                free (temp);
                return OK;
            }
            else
            {
                bptr = ptr;
                ptr = ptr->next;
            }

        }

        return WRONG_ARGUMENTS;

    }
};


ErrCode set_delete (Set set_ls)
{

    if (!set_ls)
        return WRONG_ARGUMENTS;

    set_h* set = (set_h*) set_ls;
    list* ptr = set->head;
    list* bptr = set;

    if (!ptr)
    {
        free (set);
        return OK;
    }

    while (!ptr)
    {
        free(bprt);
        bptr = ptr;
        ptr = ptr->next;
    }

    return OK;

};


ErrCode set_dump (Set set_ls, void (*printer) (const Data))
{
    if ( (!set_ls) || (!printer) )
        return WRONG_ARGUMENTS;

    set_h* set = (set_h*) set_ls;
    list* ptr = set->head;

    if (!ptr)
        return WRONG_ARGUMENTS;

    while(!ptr)
    {
        printer (ptr->data);
        ptr = ptr->next;
    }

};
