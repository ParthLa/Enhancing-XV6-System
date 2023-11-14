#include "types.h"
#include "stat.h"
#include "user.h"

int main()
{
	int ret;
	int i;
	int channel1=1;
	int channel2=2;
	uspinlock_init();
	ucounter_init();
	// int shared=1;
	ret = fork();
	if(ret == 0)
	{
	  for(i=0; i < 10; i++) {
	  	uspinlock_acquire(0);
	  	while(ucounter_get(0)==1){
	  		ucv_sleep(channel1,0);
	    }
	    printf(1, "I am child\n");
	  	ucounter_set(0,1);
	    ucv_wakeup(channel2);
	    uspinlock_release(0);
	  }
	  ucv_wakeup(channel2);
      exit();
	}
	else
	{
	  for(i=0; i < 10; i++) {
	  	uspinlock_acquire(0);
	  	while(ucounter_get(0)==0){
	  		ucv_sleep(channel2,0);
	    }
	    printf(1, "I am parent\n");
	  	ucounter_set(0,0);
	  	ucv_wakeup(channel1);
	    uspinlock_release(0);
	  }
	  ucv_wakeup(channel1);
	  wait();
      exit();
	}
}

