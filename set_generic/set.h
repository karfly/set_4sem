#ifndef SET_H
#define SET_H

#include <stdlib.h>

typedef void * Set;
typedef void * Data;

typedef enum {

        ERROR            = -1,
        OK               =  0,
        WRONG_ARGUMENTS  =  1,
        OUT_OF_RESOURSES =  2,
} ErrCode;

ErrCode set_create (Set *, int (*compar) (const Data, const Data));     // Comparing func returns zero if items are equal
                                                                        // and not not zero if not equal

ErrCode set_put (Set, Data, size_t);

ErrCode set_has (Set, Data);            // Returns OK                   If putted successfully
                                        //         WRONG_ARGUMENTS      If there is no such item

ErrCode set_remove (Set, Data);         // Returns OK                   If removed successfully
                                        //         WRONG_ARGUMENTS      If there is no such item

ErrCode set_delete (Set *);                                             // After this functiom pointer to set is NULL.
                                                                        // NULL pointer to set means spoiled set

ErrCode set_dump (Set set_void, void (*printer) (const Data));          // Second argument is a pointer to the
                                                                        // function, which works like printer
                                                                        // of current data
#endif