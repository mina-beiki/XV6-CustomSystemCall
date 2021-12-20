#include "types.h"
#include "user.h"
#include "stat.h"

#define PAGESIZE 4096

int thread_create(void (*fn) (void *), void *arg) {

 //allocating 2 * pagesize for fptr in heap
  void * fptr = malloc(2 * PAGESIZE);
  void * stack;

  if(fptr==0)
  return -1;

  //check page aligned:
  int mod = (uint)fptr % PAGESIZE;
  if(mod==0)
    stack = fptr;
  else
    stack = fptr + (PAGESIZE - mod);

  int thread_id = clone ((void *)stack); 
  
  //check clone:
  if (thread_id < 0)
    printf(1, "clone failed!\n");

  //success:

  else if(thread_id == 0){
      //call the func passed to thread_create:
      (fn)(arg);
      //free space when func is finished:
      free(stack);
      exit();
  }

  return thread_id;
}