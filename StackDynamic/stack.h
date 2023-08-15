#ifndef _STACCK_H_
#define _STACCK_H_
#include <stdio.h>
#include <stdlib.h>
#include "Platform_Types.h"

typedef struct{
    void **Arr_ptr;
    uint32 stack_max_size;
    sint32 stack_count;
    sint32 stack_top;
}stack_t;

typedef enum{
    STACK_NOK = 0,
    STACK_OK = 1,
    STACK_FULL,
    STACK_EMPTY,
    STACK_NULL_PTR,
}stack_status_t;


stack_t *CreateStack(uint32 max_size, stack_status_t *return_status);
stack_t *DestroyStack(stack_t *object, stack_status_t *return_status);
stack_status_t PushStack(stack_t *object, void *item);
void *PopStack(stack_t *object, stack_status_t *return_status);
void *StackTop(stack_t *object, stack_status_t *return_status);
stack_status_t StackCount(stack_t *object, uint32 *stack_count);

#endif // _STACCK_H_
