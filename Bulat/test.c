#include <stdio.h>

void error (char* reason)
{
	printf ("Failed to %s\n", reason);
	return -1;
};

int compare_int (const Data d1, const Data d2) {

        return (*((int *)d1) != *((int *)d2));
}

void printer_int (const Data data) {

        printf ("%d\n", *(int *)(data));
}

int main()
{
	int n1 = 1, n2 = 2, n3 = 3;
	
	Set set = NULL;

        if ( set_create (&set, &compare_int) ) {
                error ("set_create");
        }

        if ( set_put (set, &n1) ) {
                error("set_put");
        }

        if ( set_put (set, &n2) ) {
                error ("set_put");
        }

        if ( set_put (set, &n3) ) {
                error("set_put");
        }

        if ( set_remove (set, &n1) ) {
                error ("set_remove");
        }

        if ( !set_has(set, &n1) ) {
                error ("set_has");
        }

        if ( set_put (set, &n2) ) {
                error("set_put");
        }

        if ( set_has (set, &n1) ) {
               error ("set_has");
        }


        if ( set_delete (&set) ) {
                error ("set_delete");
        }

	if ( set_dump (set, &printer_int)){
		error ("set_dump");
	}

        printf ("OK\n");

        return 0;
}
