#include "../set.h"
#include <stdio.h>

#define FAIL(reason)    do {                                    \
                                printf ("FAIL: %s\n", reason);  \
                                return 1;                       \
                        } while (0);



int main () {

        Set * mySet = NULL;
        if ( set_create ((void *)&mySet) ) {
                FAIL ("set_create");
        }

        int a = 1, b = 2, c = 3;

        if ( set_put (mySet, a) )  {
                FAIL ("set_put");
        }

        if ( set_put (mySet, b) ) {
                FAIL ("set_put");
        }

        if ( set_put (mySet, c) ) {
                FAIL ("set_put");
        }

        if ( set_remove (mySet, b) ) {
                FAIL ("set_remove");
        }

        if ( !set_has(mySet, b) ) {
                FAIL ("set_has");
        }

        if ( set_put (mySet, b) ) {
                FAIL ("set_put");
        }

        if ( set_has (mySet, a) || set_has (mySet, b) || set_has (mySet, c) ) {
                FAIL ("set_has");
        }

        if ( set_put (NULL, a) != WRONG_ARGUMENTS) {
                printf ("U Yegora etot test ne proidet lol\n");
                FAIL ("set_put");
        }

        //set_dump (mySet);

        if ( set_delete (mySet) ) {
                FAIL ("set_delete");
        }

        printf ("OK\n");

        return 0;
}