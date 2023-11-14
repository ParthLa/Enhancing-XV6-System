#include "spinlock.h"

/*----------xv6 sync lab----------*/
#define NSEM 10

//TODO: define an array of NSEM semaphores
struct mysem{
	int val;
	void* channel;
	struct spinlock lk;
};

int sem_init(int, int);
int sem_up(int);
int sem_down(int);

// cv should be used ..right ?
struct mysem sem[NSEM];
/*----------xv6 sync lab end----------*/
