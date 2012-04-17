#include "set.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

static void test_init(){

  Set *set = (Set *)malloc(sizeof(Set));
  set_init(set, NULL, NULL);

  assert(0 == set_size(set));



}

int equals(const void *a, const void *b){
  int x, y;

  memcpy(&x, a, sizeof(int) );
  memcpy(&y, b, sizeof(int) );

  return x==y;
}

static void test_insert(){

  Set *set = (Set *)malloc(sizeof(Set));
  set_init(set, equals, NULL);

  int a = 10;
  int b = 20;
  int c = 30;

  assert(0 == set_is_member(set, (void *)&a));

  int n;

  n = set_insert(set, (void *)&a);

  assert(1 == set_is_member(set, (void *)&a));

  n = set_insert(set, (void *)&a);
  assert(1 == n);
  assert(1 == set_size(set));

  n = set_insert(set, (void *)&b);

  assert(2 == set_size(set));

  set_remove(set, (void *)&c);
  assert(2 == set_size(set));

  int *x;
  x = &b;
  set_remove(set, (void **)&x);
  assert(1 == set_size(set));


/*
  set_enset(set, &a);
  assert(1 == set_size(set));
  assert(&a == set_peek(set));

  set_enset(set, &b);
  assert(2 == set_size(set));
  assert(&a == set_peek(set));

  set_enset(set, &c);
  assert(3 == set_size(set));
  assert(&a == set_peek(set));

  int *d = (int *)malloc(sizeof(int));
  set_deset(set, (void **) &d);
  assert(2 == set_size(set));
  assert(&a == d);

  set_deset(set, (void **) &d);
  assert(1 == set_size(set));
  assert(&b == d);

  set_deset(set, (void **) &d);
  assert(0 == set_size(set));
  assert(&c == d);

  set_deset(set, (void **) &d);
  assert(0 == set_size(set));
  assert(&c == d);
*/

}


int main(){

  test_init();
  test_insert();
  printf("Tests finished");
  return 0;
}
