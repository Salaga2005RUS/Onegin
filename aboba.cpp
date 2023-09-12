#include <stdio.h>
#include <stdlib.h>

void allocate_memory (int **a)
{
    int *b = (int *) calloc (2, sizeof(int));

    *a_p = b;

    printf("a pointer in function: %p\n", a);
}

int main ()
{
    int *a = NULL;

    printf("a before function: %p\n", a);

    allocate_memory(&a);

    printf("a after function: %p\n", a);
}
