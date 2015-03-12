#include "./../set.h"

#include <stdio.h>

#define FAIL(reason)    do {                                    \
                                printf ("FAIL: %s\n", reason);  \
                                return 1;                       \
                        } while (0);

int compare_int (const Data a, const Data b) {

        return (*((int *)a) != *((int *)b));
}


int main () {

        Set * mySet = NULL;
        int a = 42;

        if ( set_create (NULL, NULL) != WRONG_ARGUMENTS) {
                FAIL ("set_create");
        }

        if ( set_create ( (void *)&mySet, compare_int) ) {
                FAIL ("set_create");
        }

        if (set_delete ((void *)&mySet)) {
                FAIL ("set_delete");
        }

        if ( set_put (mySet, &a, sizeof(a)) != WRONG_ARGUMENTS) {
                FAIL ("set_put");
        }


        if ( set_has (mySet, &a) != WRONG_ARGUMENTS) {
                FAIL ("set_has");
        }

        if ( set_remove (mySet, &a) != WRONG_ARGUMENTS) {
                FAIL ("set_remove");
        }

        if ( set_dump (mySet, NULL) != WRONG_ARGUMENTS) {
                FAIL ("set_dump");
        }

        printf ("OK\n");

        return 0;
}