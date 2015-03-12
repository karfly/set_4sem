typedef void * Set;
typedef int Data;

typedef enum {

        ERROR            = -1,
        OK               =  0,
        WRONG_ARGUMENTS  =  1,
        OUT_OF_RESOURSES =  2,
} ErrCode;

ErrCode set_create (Set *);      // Comparing func returns zero if items are equal
                                                                        // and not not zero if not equal

ErrCode set_put (Set, Data);

ErrCode set_has (Set, Data);            // Return OK                    If putted successfully
                                        //        WRONG_ARGUMENTS       If there is no such item

ErrCode set_remove (Set, Data);         // Returns OK                   If removed successfully
                                        //         WRONG_ARGUMENTS      If there is no such item

ErrCode set_delete (Set);
