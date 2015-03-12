#include "./../set.h"

#include <stdio.h>
#include <string.h>

#define FAIL(reason)    do {                                    \
                                printf ("FAIL: %s\n", reason);  \
                                return 1;                       \
                        } while (0);

int compare_string (const Data a, const Data b) {

        return strcmp ((char *) a, (char *) b);
}

void printer_string (const Data data) {

        printf ("%s\n", (char *)(data));
}



int main () {

        Set * mySet = NULL;
        if ( set_create ((void *)&mySet, &compare_string) ) {
                FAIL ("set_create");
        }

        char s1[] = "Karim";
        char s2[] = "Egor";
        char s3[] = "Bulat";
        char s4[] = "Arseniy";
        char s5[] = "Ivan";

        if ( set_put (mySet, s1, strlen(s1) + 1) ) {
                FAIL ("set_put");
        }

        if ( set_put (mySet, s2, strlen(s2) + 1) ) {
                FAIL ("set_put");
        }

        if ( set_put (mySet, s3, strlen(s3) + 1) ) {
                FAIL ("set_put");
        }

        if ( set_put (mySet, s4, strlen(s4) + 1) ) {
                FAIL ("set_put");
        }

        if ( set_put (mySet, s5, strlen(s5) + 1) ) {
                FAIL ("set_put");
        }


        if ( set_remove (mySet, s2) ) {
                FAIL ("set_remove");
        }

        if ( !set_has(mySet, s2) ) {
                FAIL ("set_has");
        }

        if ( set_put (mySet, s1, strlen(s1) + 1) ) {
                FAIL ("set_put");
        }

        if ( set_has (mySet, s1) || set_has (mySet, s3) || set_has (mySet, &s4) || set_has (mySet, &s5) ) {
                FAIL ("set_has");
        }

        // set_dump (mySet, printer_string);

        if ( set_delete ((void *)&mySet) ) {
                FAIL ("set_delete");
        }

        printf ("OK\n");

        return 0;
}