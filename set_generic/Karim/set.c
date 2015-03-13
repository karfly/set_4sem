#include "set.h"

#include <malloc.h>
#include <string.h>

typedef struct list_node_t      list_node_t;
typedef struct set_t            set_t;

struct list_node_t {

        Data data;
        list_node_t * next;
};

struct set_t {

        list_node_t * head;
        int (*compare_func) (const Data, const Data);
};



ErrCode set_create (Set * set_ptr, int (*compar) (const Data, const Data)) {

        if (!set_ptr || !compar) {
                return WRONG_ARGUMENTS;
        }

        set_t * set_new = calloc (1, sizeof(set_t));
        if (!set_new) {
                return ERROR;
        }

        set_new->head = NULL;

        set_new->compare_func = compar;

        *set_ptr = set_new;

        return OK;
}

ErrCode set_put (Set set_void, Data data, size_t size) {

        if (!set_void || !data) {
                return WRONG_ARGUMENTS;
        }

        set_t * set = (set_t *) set_void;

        list_node_t * list_node_new = calloc (1, sizeof(list_node_t));
        if (!list_node_new) {
                return ERROR;
        }

        list_node_new->next = NULL;
        list_node_new->data = calloc (1, size);
        if (!list_node_new) {
                free (list_node_new);
                list_node_new = NULL;

                return ERROR;
        }
        memcpy (list_node_new->data, data, size);

        list_node_t * finder = set->head;
        list_node_t * finder_prev = finder;

        if (!set->head) {
                set->head = list_node_new;
                return OK;
        }

        do {
                if (!(*set->compare_func) (finder->data, data)) {
                        free (list_node_new->data);
                        list_node_new->data = NULL;
                        free (list_node_new);
                        list_node_new = NULL;

                        return OK;
                }

                finder_prev = finder;
                finder = finder->next;

        } while (finder != NULL);

        finder_prev->next = list_node_new;

        return OK;
}

ErrCode set_has (Set set_void, Data data) {

        if (!set_void || !data) {
                return WRONG_ARGUMENTS;
        }

        set_t * set = (set_t *) set_void;

        list_node_t * finder = set->head;

        while (finder != NULL) {
                if (!(*set->compare_func) (finder->data, data)) {
                        return OK;
                }
                finder = finder->next;
        }

        return WRONG_ARGUMENTS;
}

ErrCode set_remove (Set set_void, Data data) {

        if (!set_void || !data) {
                return WRONG_ARGUMENTS;
        }

        set_t * set = (set_t *) set_void;

        list_node_t * finder = set->head;
        list_node_t * finder_prev = finder;

        if (!set->head) {
                return WRONG_ARGUMENTS;
        }

        do {
                if (!(*set->compare_func) (finder->data, data)) {
                        if (finder == finder_prev) {
                                set->head = finder->next;
                        }
                        else {
                                finder_prev->next = finder->next;
                        }

                        free (finder->data);
                        finder->data = NULL;
                        free (finder);
                        finder = NULL;

                        return OK;
                }

                finder_prev = finder;
                finder = finder->next;

        } while (finder != NULL);

        return WRONG_ARGUMENTS;
}

ErrCode set_delete (Set * set_ptr) {

        if (!set_ptr) {
                return WRONG_ARGUMENTS;
        }

        set_t * set = (set_t *) (*set_ptr);

        list_node_t * finder = set->head;
        list_node_t * temp = NULL;

        while (finder != NULL) {
                temp = finder;

                free (temp->data);
                temp->data = NULL;
                free (temp);
                temp = NULL;

                finder = finder->next;
        }

        free (set);
        set = NULL;
        *set_ptr = NULL;

        return OK;
}

ErrCode set_dump (Set set_void, void (*printer) (const Data)) {

        if (!set_void) {
                return WRONG_ARGUMENTS;
        }

        set_t * set = (set_t *) set_void;

        list_node_t * dumper = set->head;

        while (dumper != NULL) {
                printer (dumper->data);
                dumper = dumper->next;
        }
}
