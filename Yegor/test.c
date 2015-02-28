#include "../set.h"
#include <stdio.h>

int main()
{
    printf("\tIf set has a member we will print 0\n");
    Set s;
    set_create(&s);
    set_put(s,123);
    set_put(s,12);
    set_put(s,122222);
    set_put(s,23425);
    set_put(s,1);
    //set_dump(s);
    printf("set has 15:%s\n",(set_has(s,15)==OK)?"true":"false");
    printf("set has 23425:%s\n",(set_has(s,23425)==OK)?"true":"false");
    set_remove(s,123);
    set_put(s,256256);
    set_put(s,567);
    //set_dump(s);
    printf("set has 123:%s\n",(set_has(s,123)==OK)?"true":"false");
    printf("set has 17:%s\n",(set_has(s,17)==OK)?"true":"false");
    printf("set has 2456256:%s\n",(set_has(s,256256)==OK)?"true":"false");
    set_remove(s,256256);
    //set_dump(s);
    printf("set has 2456256:%s\n",(set_has(s,256256)==OK)?"true":"false");
    set_delete(s);
    getch();
}
