#include <stdio.h>
#include "set.h"
int error (char* reason)
{
	printf ("Failed to %s\n", reason);
	return -1;
};

int compare_int (const Data d1, const Data d2) {

	int res = 0;
	if ((*(int*) d1) == (*(int*)d2))
		res  = 0;
	else
		res = 1;
        return res;
}

void printer_int (const Data data) {

        printf ("%d\n", *(int *)(data));
}

int main()
{
	int n1 = 1, n2 = 1, n3 = 3, n4 = 10, n5 = 3, n6 = 1000;
	
	Set set = NULL;

        if ( set_create (&set, &compare_int) ) {
               return error ("set_create");
        }

        if ( set_put (set, &n1) ) {
                return error("set_put");
        }

        if ( set_put (set, &n2) ) {
                return error ("set_put");
        }

        if ( set_put (set, &n3) ) {
                return error("set_put");
        }

	if ( set_put (set, &n4) ) {
                return error("set_put");
        }

	if ( set_put (set, &n5) ) {
                return error("set_put");
        }

	if ( set_put (set, &n6) ) {
                return error("set_put");
        }

        if ( set_remove (set, &n1) ) {
                return error ("set_remove");
        }

        if ( !set_has(set, &n1) ) {
                return error ("set_has");
        }

        if ( set_put (set, &n1) ) {
                return error("set_put");
        }

        if ( set_has (set, &n1) ) {
               return error ("set_has");
        }

	if ( set_dump (set, &printer_int)){
		return error ("set_dump");
	}

        if ( set_delete set ) {
                return error ("set_delete");
        }

        printf ("OK\n");

        return 0;
}
