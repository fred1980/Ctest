#include "list.h"
#include <assert.h>
#include <stdbool.h>


static void test_init(){

  List *list = (List *)malloc(sizeof(List));
  list_init(list, NULL);
  assert( 0 == list_size(list));
  assert(NULL == list_head(list) );
  assert(NULL == list_tail(list) );
}

static void test_insert(){

  List *list = (List *)malloc(sizeof(List));
	list_init(list, NULL);

	int *a = malloc(sizeof(int));
	*a = 50;
	int b = 10;
	int c = 15;

	list_ins_next(list, NULL, a);

	assert( 1 == list_size(list));
	assert(list->head->data == a );

	list_ins_next(list, NULL, &b);
	assert(list->head->data == &b );
	assert(list->tail->data == a );
	assert(list->head->next->data == a );

	assert( 2 == list_size(list));

	list_ins_next(list, list->tail, &c);
	assert( 3 == list_size(list));

	//now remove
	void *x;
	int removed = list_rem_next(list, list->head->next, &x);
	assert( removed != -1);
	assert( 2 == list_size(list));
	assert( 15 == *((int *)x) );

	//clear

	list_destroy(list);
	assert(NULL == list->head);
	assert(NULL == list->tail);
	assert(NULL == list->destroy);
	assert( 0 == list_size(list));


}


int main(){
  test_init();
  test_insert();
  return 0;
}
