#include "stack.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

static void test_init(){

  Stack *stack = (Stack *)malloc(sizeof(Stack));
  stack_init(stack, NULL);

  assert(0 == stack_size(stack));
  assert(NULL == stack_peek(stack));
/*
  int *d = (int *)malloc(sizeof(int));
  stack_pop(stack, (void **) &d);
  assert(NULL == d );*/

}

static void test_insert(){

  Stack *stack = (Stack *)malloc(sizeof(Stack));
  stack_init(stack, NULL);

  int a = 10;
  int b = 20;
  int c = 30;

  stack_push(stack, &a);
  assert(1 == stack_size(stack));
  assert(&a == stack_peek(stack));

  stack_push(stack, &b);
  assert(2 == stack_size(stack));
  assert(&b == stack_peek(stack));

  stack_push(stack, &c);
  assert(3 == stack_size(stack));
  assert(&c == stack_peek(stack));

  int *d = (int *)malloc(sizeof(int));
  stack_pop(stack, (void **) &d);
  assert(2 == stack_size(stack));
  assert(&c == d);

  stack_pop(stack, (void **) &d);
  assert(1 == stack_size(stack));
  assert(&b == d);

  stack_pop(stack, (void **) &d);
  assert(0 == stack_size(stack));
  assert(&a == d);

  stack_pop(stack, (void **) &d);
  assert(0 == stack_size(stack));
  assert(&a == d);


}


int main(){

  test_init();
  test_insert();
  printf("Tests finished");
  return 0;
}
