#include "types.h"
#include "stat.h"
#include "user.h"


int
main(int argc, char *argv[])
{
  int  i=0;
  int st = uptime();
  //int all_wait_time = 0;
  for(i=0;i<10;i++)
  {
    int pid = fork();
    if(pid==0)
    {
      int tot_time = 0;
      int real_time = uptime();
    for(int i=0;i<10000;i++)
    {
      //printf(1,"%d\n",i);
      int t = my_futex_lock();
      tot_time+=t;
      //int st = uptime();
      //printf(1,"%d\n",i);
      int g = get();
      set(g+1);

      //printf(1,"%d\n",i );
      my_unlock();
      //yield();
      //printf(1,"%d %d\n",i,g ); 
    }
    //int x = get();
    real_time = uptime() - real_time;
    real_time = real_time *10;
    //int end = uptime();
    //end = (end-st)*10;
    //printf(1,"Total waiting time in microseconds is %d\n", tot_time*10);
    //printf(1,"%Total execution time in microseconds is %d\n",real_time);
    //printf(1,"%d\n",x);
    exit();
    }

  }
  for(int i=0;i<10;i++)
  wait();
  int end = uptime() - st;
  end = end *10;
  printf(1,"Total execution time is %d\n",end);
  
 
}
