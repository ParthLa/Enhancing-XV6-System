/*----------xv6 sync lab----------*/
#include "types.h"
#include "x86.h"
#include "defs.h"
#include "semaphore.h"


int
sem_init(int index, int val)
{
	sem[index].val=val;
	sem[index].channel=(void*)index;
	char* name="abc";
	initlock(&sem[index].lk,name);
  //to be done
  return 0;
}

int
sem_up(int index)
{
	acquire(&sem[index].lk);
	sem[index].val=sem[index].val+1;
	my_wakeup(sem[index].channel);
	release(&sem[index].lk);
  //to be done
  return 0;
}

int
sem_down(int index)
{
	acquire(&sem[index].lk);
	sem[index].val=sem[index].val-1;
	// cprintf("%d\n",sem[index].val);
	if((sem[index].val)<0){
		// cprintf("hello\n");
		sleep(sem[index].channel,&sem[index].lk);
	}
	release(&sem[index].lk);

	// acquire(&sem[index].lk);
	// // cprintf("%d\n",sem[index].val);
	// while((sem[index].val)<=0){
	// 	sleep(sem[index].channel,&sem[index].lk);
	// }
	// sem[index].val=sem[index].val-1;
	// release(&sem[index].lk);
  //to be done
  return 0;
}

/*----------xv6 sync lab end----------*/
