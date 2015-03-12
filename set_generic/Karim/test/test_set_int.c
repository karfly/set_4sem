#include "./../set.h"

#include <stdio.h>

#define FAIL(reason)    do {                                    \
                                printf ("FAIL: %s\n", reason);  \
                                return 1;                       \
                        } while (0);

int compare_int (const Data a, const Data b) {

        return (*((int *)a) != *((int *)b));
}

void printer_int (const Data data) {

        printf ("%d\n", *(int *)(data));
}


int main () {

        Set * mySet = NULL;
        if ( set_create ((void *)&mySet, &compare_int) ) {
                FAIL ("set_create");
        }

        int a = 1, b = 2, c = 3;

        if ( set_put (mySet, &a, sizeof(a)) ) {
                FAIL ("set_put");
        }

        if ( set_put (mySet, &b, sizeof(b)) ) {
                FAIL ("set_put");
        }

        if ( set_put (mySet, &c, sizeof(c)) ) {
                FAIL ("set_put");
        }

        if ( set_remove (mySet, &b) ) {
                FAIL ("set_remove");
        }

        if ( !set_has(mySet, &b) ) {
                FAIL ("set_has");
        }

        if ( set_put (mySet, &b, sizeof(b)) ) {
                FAIL ("set_put");
        }

        if ( set_has (mySet, &a) || set_has (mySet, &b) || set_has (mySet, &c) ) {
                FAIL ("set_has");
        }

        //set_dump (mySet, printer_int);

        if ( set_delete ((void *)&mySet) ) {
                FAIL ("set_delete");
        }

        printf ("OK\n");

        return 0;
}