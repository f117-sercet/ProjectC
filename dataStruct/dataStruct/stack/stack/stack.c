

#include <stdio.h>
#include <stdlib.h>



#include <assert.h>

#include "stack.h"
void **array;

int max = 10;


int counter = 0;

int offset = -1;

void initStack()
{
    array = malloc(sizeof(void *) * max);
    assert(array);
}


void grow()
{
    max += 10;
    int i;
    void **tmp = malloc(sizeof(void *) * max);

    for (i = 0; i < max - 10; i++)
    {
        *(tmp + i) = *(array + i);
    }
    free(array);
    array = tmp;
}

void push(void *object)
{
    assert(object); /* tests whether pointer isn't null */

    if (counter < max)
    {
        offset++; /* increases the element-pointer */


        *(array + offset) = object;

        /* increases the inner counter */
        counter++;
    }
    else
    {
        grow();
        push(object);
    }
}

/*
    pop: pops the top element of the stack from the stack.
*/
void *pop()
{
    void *top = *(array + offset);

    /* check pointers */
    assert(top);

    /* if use the pop-function, stack must not empty. */
    assert(!isEmpty());

    /* decreases the offset address for pointing of
        the new top element */
    offset--;

    /* decreases the inner counter */
    counter--;

    return top;
}

/*
    size: gets the number of elements of the stack.
*/
int size() { return counter; }

/*
    isEmpty(): returns 1 if stack is empty otherwise 0.
*/
int isEmpty() { return counter == 0; }

/*
    top: returns the top element from the stack without removing it.
*/
void *top()
{
    /* offset address points to the top element */
    return array[offset];
}
