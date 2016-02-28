
// MT, 2016feb28

//#define NDEBUG

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "Obj.h"
#include "Stack.h"

int main()
{
    struct Stack * s = Stack_create(true);

    Stack_push(s, Obj_bool_create(true));
    Stack_push(s, Obj_char_create('A'));
    Stack_push(s, Obj_int_create(42));
    Stack_push(s, Obj_double_create(1234.5678));
    printf("POP %f\n", *(double*)Stack_pop(s));
    printf("POP %d\n", *(int*)Stack_pop(s));
    printf("TOP %c\n", *(char*)Stack_top(s));
    printf("TOP %c\n", *(char*)Stack_top(s));

    Stack_clear(s);

    printf("EMPTY? %d\n", (int)Stack_isEmpty(s));

    Stack_push(s, Obj_bool_create(false));
    printf("EMPTY? %d\n", (int)Stack_isEmpty(s));
    Stack_push(s, Obj_char_create('B'));
    printf("POP %c\n", *(char*)Stack_pop(s));
    Stack_push(s, Obj_int_create(666));
    printf("POP %d\n", *(int*)Stack_pop(s));
    Stack_push(s, Obj_double_create(321.654));
    printf("TOP %f\n", *(double*)Stack_top(s));

    Stack_delete(s);
    s = NULL;

    return EXIT_SUCCESS;
}
