#include "./../set.h"

#include <stdio.h>

#define FAIL(reason)    do {                                    \
                                printf ("FAIL: %s\n", reason);  \
                                return 1;                       \
                        } while (0);

int compare_double (const Data a, const Data b) {

        return (*((double *)a) != *((double *)b));
}

void printer_double (const Data data) {

        printf ("%lg\n", *(double *)(data));
}


int main () {

        Set * mySet = NULL;
        if ( set_create ((void *)&mySet, &compare_double) ) {
                FAIL ("set_create");
        }

        double pi = 3.14, e = 2.71, h = 6.67;

        if ( set_put (mySet, &pi, sizeof(pi)) ) {
                FAIL ("set_put");
        }

        if ( set_put (mySet, &e, sizeof(e)) ) {
                FAIL ("set_put");
        }

        if ( set_put (mySet, &h, sizeof(h)) ) {
                FAIL ("set_put");
        }

        if ( set_remove (mySet, &e) ) {
                FAIL ("set_remove");
        }

        if ( !set_has(mySet, &e) ) {
                FAIL ("set_has");
        }

        if ( set_put (mySet, &e, sizeof(e)) ) {
                FAIL ("set_put");
        }

        if ( set_has (mySet, &pi) || set_has (mySet, &e) || set_has (mySet, &h) ) {
                FAIL ("set_has");
        }

        //set_dump (mySet, printer_double);

        if ( set_delete ((void *)&mySet) ) {
                FAIL ("set_delete");
        }

        printf ("OK\n");

        return 0;
}