#include "queue.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

static void test_init(){

  Queue *queue = (Queue *)malloc(sizeof(Queue));
  queue_init(queue, NULL);

  assert(0 == queue_size(queue));
  assert(NULL == queue_peek(queue));


}

static void test_insert(){

  Queue *queue = (Queue *)malloc(sizeof(Queue));
  queue_init(queue, NULL);

  int a = 10;
  int b = 20;
  int c = 30;

  queue_enqueue(queue, &a);
  assert(1 == queue_size(queue));
  assert(&a == queue_peek(queue));

  queue_enqueue(queue, &b);
  assert(2 == queue_size(queue));
  assert(&a == queue_peek(queue));

  queue_enqueue(queue, &c);
  assert(3 == queue_size(queue));
  assert(&a == queue_peek(queue));

  int *d = (int *)malloc(sizeof(int));
  queue_dequeue(queue, (void **) &d);
  assert(2 == queue_size(queue));
  assert(&a == d);

  queue_dequeue(queue, (void **) &d);
  assert(1 == queue_size(queue));
  assert(&b == d);

  queue_dequeue(queue, (void **) &d);
  assert(0 == queue_size(queue));
  assert(&c == d);

  queue_dequeue(queue, (void **) &d);
  assert(0 == queue_size(queue));
  assert(&c == d);


}


int main(){

  test_init();
  test_insert();
  printf("Tests finished");
  return 0;
}
