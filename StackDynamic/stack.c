#include "stack.h"

static uint8 stack_full(stack_t *object)
{
    return (object->stack_count == object->stack_max_size);
}

static uint8 stack_empty(stack_t *object)
{
    return (object->stack_count == 0);
}


stack_t *CreateStack(uint32 max_size, stack_status_t *return_status)
{
    stack_t *my_stack = NULL;
    if(NULL == return_status)
    {
        *return_status = STACK_NULL_PTR;
        my_stack = NULL;
    }
    else
    {
        my_stack = (stack_t *)malloc(sizeof(stack_t));
        if(NULL == my_stack)
        {
            *return_status = STACK_NOK;
            my_stack = NULL;
        }
        else
        {
            my_stack->stack_count = 0;
            my_stack->stack_max_size = max_size;
            my_stack->stack_top = -1;
            my_stack->Arr_ptr = (void **)calloc(my_stack->stack_max_size, sizeof(void *));
            if(!my_stack->Arr_ptr)
            {
                free(my_stack);
                my_stack = NULL;
                *return_status = STACK_NOK;
            }
            else
            {
                *return_status = STACK_OK;
            }
        }
    }
    return my_stack;
}
stack_t *DestroyStack(stack_t *object, stack_status_t *return_status)
{
    if((NULL == return_status) || (NULL == object))
    {
        *return_status = STACK_NULL_PTR;
    }
    else
    {
        free(object->Arr_ptr);
        free(object);
        *return_status = STACK_NOK;
    }
    return NULL;
}
stack_status_t PushStack(stack_t *object, void *item)
{
    stack_status_t ret = STACK_NOK;
    if((NULL == object) || (NULL == item))
    {
        object = NULL;
        ret = STACK_NULL_PTR;
    }
    else
    {
        if(stack_full(object))
        {
            ret = STACK_FULL;
        }
        else
        {
            (object->stack_top)++;
            object->Arr_ptr[object->stack_top] = item;
            (object->stack_count)++;
            ret = STACK_OK;
        }
    }
    return (ret);
}
void *PopStack(stack_t *object, stack_status_t *return_status)
{
    void *dataout = NULL;
    if((NULL == object), (NULL == return_status))
    {
        *return_status = STACK_NULL_PTR;
        dataout = NULL;
    }
    else
    {
        if(stack_empty(object))
        {
            *return_status = STACK_FULL;
            dataout = NULL;
        }
        else
        {
            dataout = object->Arr_ptr[object->stack_top];
            (object->stack_top)--;
            (object->stack_count)--;
            *return_status = STACK_OK;
        }
        return dataout;
    }
}
void *StackTop(stack_t *object, stack_status_t *return_status)
{
    void *dataout = NULL;
    if((NULL == object), (NULL == return_status))
    {
        *return_status = STACK_NULL_PTR;
    }
    else
    {
        if(stack_empty(object))
        {
            *return_status = STACK_FULL;
        }
        else
        {
            dataout = object->Arr_ptr[object->stack_top];
            *return_status = STACK_OK;
        }
    }
    return dataout;
}
stack_status_t StackCount(stack_t *object, uint32 *stackcount)
{
    stack_status_t ret = STACK_NOK;
    if((NULL == object), (NULL == stackcount))
    {
        ret = STACK_NULL_PTR;
    }
    else
    {
        if(stack_empty(object))
        {
            ret = STACK_EMPTY;
        }
        else
        {
            *stackcount = object->stack_count;
            ret = STACK_OK;
        }
    }
    return ret;
}
