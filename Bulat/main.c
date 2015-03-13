#include "set.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef struct set_h    set_h;
typedef struct list     list;



struct list {
    list* next;
    Data data;
};

struct set_h {
    list* head;
    int (*compare_f) (const Data, const Data);
};

ErrCode set_create (Set * set_ptr, int (*compar)(const Data, const Data))
{

    if ( (!set_ptr) || (!compar) ){
        return WRONG_ARGUMENTS;
    }

    set_h * set_new = (set_h*) calloc (1, sizeof(set_h));

    if (!set_new)
        return OUT_OF_RESOURSES;

    set_new->head = NULL;
    set_new->compare_f = compar;

    *set_ptr = set_new;

    return OK;

};



ErrCode set_put (Set set_ls, Data data)
{

    if ( (!set_ls) || (!data) )
        return WRONG_ARGUMENTS;

    set_h* set = (set_h*) set_ls;

    if ((set->head) == NULL){

        list* ls = (list*) calloc (1, sizeof(list));

        if (!ls)
            return OUT_OF_RESOURSES;

        ls->next = NULL;

        ls->data = data;

        set->head = ls;

        return OK;

    }

    list* ptr = set->head;
    list* temp;

    while (ptr != NULL)
    {

        if (!(*set->compare_f) (ptr->data, data)){
            return OK;
        }

	    temp = ptr;
	    ptr = ptr->next;

    }

    list* list_new = (list*) calloc (1, sizeof(list));

    if (!list_new)
        return OUT_OF_RESOURSES;

    list_new->next = NULL;

    list_new->data = data;

    temp->next = list_new;

    return OK;

};


ErrCode set_has (Set set_ls, Data data)
{

    if ( (!set_ls) || (!data) )
        return WRONG_ARGUMENTS;

    set_h* set = (set_h*) set_ls;

    if (set->head == NULL){

        return WRONG_ARGUMENTS;

    }
    else
    {

        list* ptr = set->head;

        while (ptr)
        {

            if (!(*set->compare_f) (ptr->data, data))
                return OK;

            ptr = ptr->next;

        }


        return WRONG_ARGUMENTS;

    }

};


ErrCode set_remove (Set set_ls, Data data)
{

    if ( (!set_ls) || (!data) )
        return WRONG_ARGUMENTS;

    set_h* set = (set_h*) set_ls;

    if (set->head == NULL){

        return WRONG_ARGUMENTS;

    }
    else
    {

        list* ptr = set->head;
        list* bptr = ptr;

        while (ptr)
        {

            if (!(*set->compare_f) (ptr->data, data))
            {
		if (ptr == bptr)
		{
			set->head = ptr->next;
			free (ptr);
			return OK;
		}
                bptr->next = ptr->next;
                free (ptr);
                return OK;
            }

                bptr = ptr;
                ptr = ptr->next;

        }

        return WRONG_ARGUMENTS;

    }
};


ErrCode set_delete (Set * set_ls)
{

    if (!set_ls)
        return WRONG_ARGUMENTS;

    set_h* set = (set_h*) set_ls;
    list* ptr = set->head;
    list* bptr;

    if (!ptr)
    {
        free (set);
        set_ls = NULL;
        return OK;
    }

    while (ptr)
    {
        free(bptr);
        bptr = ptr;
        ptr = ptr->next;
    }

    set_ls = NULL;

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

    while(ptr)
    {
        printer (ptr->data);
        ptr = ptr->next;
    }

    return OK;

};
