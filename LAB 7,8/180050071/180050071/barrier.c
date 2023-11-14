/*----------xv6 sync lab----------*/
#include "types.h"
#include "x86.h"
#include "spinlock.h"
#include "defs.h"
#include "barrier.h"

//define any variables needed here
int count;
// pthread_mutex &m;
struct spinlock lk;
char* name="barrier";
void* channel=(void*)1;

int
barrier_init(int n)
{
	initlock(&lk,name);
	acquire(&lk);
	count=n;
	release(&lk);
  //to be done
  return 0;
}

int
barrier_check(void)
{
	acquire(&lk);
	count--;
	while(count!=0){
		// cprintf("sleeping\n");
		sleep(channel,&lk);
	}
	wakeup(channel);
	release(&lk);
  //to be done
  return 0;
}

/*----------xv6 sync lock end----------*/
