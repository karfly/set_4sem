#include "set.h"
int main(){
    Set s;
    set_create(&s);
    set_put(s,5);
    set_put(s,5);
    set_put(s,5);
    set_put(s,2);
    set_put(s,3);
    set_put(s,4);
    set_put(s,1);
    //set_dump(s);
    set_remove(s,3);
    set_remove(s,4);
    //set_dump(s);
    printf("Set has 2: %s\n ",( set_has(s,2) == OK)?"True":"False");
    printf("Set has 3: %s\n ",( set_has(s,3) == OK)?"True":"False");
    set_put(s,6);
    set_put(s,6);
    //set_dump(s);
    set_put(s,10000);
    set_put(s,94034850);
    //set_dump(s);
    printf("Set has 94034850: %s\n ",( set_has(s,94034850) == OK)?"True":"False");
    printf("Set has 94034851: %s\n ",( set_has(s,94034851) == OK)?"True":"False");
    printf("Set has 0: %s\n ",( set_has(s,0) == OK)?"True":"False");
    set_delete(s);
    printf("OK\n");
}
