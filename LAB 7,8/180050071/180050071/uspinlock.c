/*----------xv6 sync lab----------*/
#include "types.h"
#include "x86.h"
#include "uspinlock.h"

// #include "types.h"
// #include "defs.h"
// #include "param.h"
// #include "memlayout.h"
// #include "mmu.h"
// #include "x86.h"
// #include "proc.h"
// #include "spinlock.h"
// #include "uspinlock.h"

//TODO: define an array of NLOCK uspinlocks
struct myuserlock{
  uint locked;
};

struct myuserlock uspinlock_arr[NLOCK];

int
uspinlock_init(void)
{
  // Initialize all locks to unlocked state
  // To be done.
  // int x=A_init(void);
  // acquire(&ptable.lock);
  // pushcli();
  for (int i=0;i<NLOCK;i++){
    uspinlock_arr[i].locked=0;
  }
  // release(&ptable.lock);
  return 0;
}

int
uspinlock_acquire(int index)
{
  // acquire(&ptable.lock);
  // pushcli();
  // struct myuserlock* l=uspinlock_arr[index];
  while(xchg(&uspinlock_arr[index].locked,1)!=0)
    ; // wait
  // l->locked=1;
  // To be done.
  // release(&ptable.lock);
  return 0;
}

int
uspinlock_release(int index)
{
  // To be done.
  // acquire(&ptable.lock);
  // struct myuserlock* l=uspinlock_arr[index];
  // l->locked=0;
  xchg(&uspinlock_arr[index].locked,0);
  // release(&ptable.lock);
  // popcli();
  return 0;
}

int
uspinlock_holding(int index)
{
  // To be done.
  //Return 0 if lock is free, 1 if lock is held
  // acquire(&ptable.lock);
  // struct myuserlock* l=uspinlock_arr[index];
  // release(&ptable.lock);
  return uspinlock_arr[index].locked;
  // return 0;
}
/*----------xv6 sync lock end----------*/
