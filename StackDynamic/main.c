#include "stack.h"

stack_t *stack1 = NULL;
uint32 stack1_size = 0;
uint32 stack1_count = 0;
void *stack1_return = NULL;
uint32 var1 = 11;
float32 var2 = 22.8;
char Var3 = 'a';

int main()
{
    stack_status_t stack1_status = STACK_NOK;
    printf("Please Enter Number of Elemnts:");
    scanf("%i", &stack1_size);
    stack1 = CreateStack(stack1_size, &stack1_status);
    if(stack1)
    {
        printf("stack1 created\n");
    }

    stack1_status = PushStack(stack1, &var1); printf("Stack1_Status = %i \n", stack1_status);

    stack1_status = PushStack(stack1, &var2) ;printf("Stack1_Status = %i \n", stack1_status);

    stack1_status = PushStack(stack1, &Var3); printf("Stack1_Status = %i \n", stack1_status);

    stack1_status = PushStack(stack1, &Var3); printf("Stack1_Status = %i \n", stack1_status);

    stack1_status = StackCount(stack1, &stack1_count); printf("Stack1_Status = %i \n", stack1_status);
    printf("stack count = %i\n", stack1_count);

    stack1_return = StackTop(stack1, &stack1_status); printf("Stack1_Status = %i \n", stack1_status);
    printf("StackTop = %c \n", *((uint32 *)stack1_return));

    stack1_return = PopStack(stack1, &stack1_status); printf("Poped value = %c \n", *((uint32 *)stack1_return));
    stack1_return = PopStack(stack1, &stack1_status); printf("Poped value = %c \n", *((uint32 *)stack1_return));
    stack1_return = StackTop(stack1, &stack1_status); printf("Stack1_Status = %i \n", stack1_status);
    printf("StackTop = %f \n", *((float32 *)stack1_return));

    stack1_status = StackCount(stack1, &stack1_count); printf("Stack1_Status = %i \n", stack1_status);
    printf("stack count = %i\n", stack1_count);



    stack1 = DestroyStack(stack1, &stack1_status);
    if(!stack1)
    {
        printf("stack1 destroy\n");
    }
    return 0;
}
