#include "../set.h"
#include <stdio.h>

int main()
{
    printf("\tIf set has a member we will print 0\n");
    Set s;
    set_create(&s);
    //printf("%d",s);
    set_put(s,123);
    set_put(s,12);
    set_put(s,122222);
    set_put(s,23425);
    set_put(s,1);
    printf("set has 15:%d\n",set_has(s,15));
    printf("set has 123:%d\n",set_has(s,23425));
    set_put(s,256256);
    set_put(s,567);
    printf("set has 2456256:%d\n",set_has(s,567));
    printf("set has 2456256:%d\n",set_has(s,256256));
    set_remove(s,256256);
    printf("set has 2456256:%d\n",set_has(s,256256));
    set_delete(s);
}
