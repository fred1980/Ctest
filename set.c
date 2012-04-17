#include <stdlib.h>

#include "list.h"
#include "set.h"


void set_init(Set *set, int(*match)(const void *key, const void *key2), void(*destroy)(void *data) ){
  list_init(set, destroy);
  set->match = match;
}

int set_insert(Set *set, const void *data){

  if(set_is_member(set, data)){
    return 1;
  }

  return list_ins_next(set, list_tail(set), data);

}

int set_remove(Set *set, void **data){

  ListElmt *member, *prev;
  prev = NULL;
  //return 0;
  for(member = list_head(set); member!=NULL; member = list_next(member)   ){

      if(set->match(*data, list_data(member) )){
        break;
      }
    }

}


int set_is_member(const Set *set, const void *data){
  ListElmt *member;

  for(member = list_head(set); member!=NULL; member = list_next(member)   ){
    if(set->match(data, list_data(member) /*member->data*/)){
      return 1;
    }
  }

  return 0;

}
