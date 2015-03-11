#include "set.h"
int main(){
    Set s;
    set_create(&s);
    set_put(s,5);
    set_put(s,2);
    set_put(s,3);
    set_put(s,4);
    set_put(s,1);
    set_dump(s);
    /*
    set_remove(s,3);
    set_remove(s,4);
    set_dump(s);
    printf("set has 2:%s\n",( set_has(s,2) == OK)?"true":"false");
    printf("set has 3:%s\n",( set_has(s,3) == OK)?"true":"false");*/
}
