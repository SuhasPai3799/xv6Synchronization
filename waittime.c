#include "types.h"
#include "stat.h"
#include "user.h"


int
main(int argc, char *argv[])
{
  int  i=0;
  
  init();
  int n_children = atoi(argv[1]);
  if(argc<2)
  {
    printf(1,"Error, please check the number of arguments\n");
    exit();
  }

  for(i=0;i<n_children;i++)
  {
    int pid = fork();
    if(pid==0)
    {
      int tot_time = 0;
      int real_time = uptime();
    for(int i=0;i<10000;i++)
    {

      int t = my_lock();
      tot_time+=t;

      int g = get();
      set(g+1);

      my_unlock();

    }

    real_time = uptime() - real_time;
    real_time = real_time *10;
    int t = my_lock();
    printf(1,"Total wait time in milliseconds using spinlock is %d\n",tot_time*10 );
    t = t+1;
    my_unlock();
    exit();
    }

  }
  for(int i=0;i<n_children;i++)
  wait();
  for(i=0;i<n_children;i++)
  {
    int pid = fork();
    if(pid==0)
    {
      int tot_time = 0;
      int real_time = uptime();
    for(int i=0;i<10000;i++)
    {

      int t = my_futex_lock();
      tot_time+=t;

      int g = get();
      set(g+1);

      my_unlock();

    }

    real_time = uptime() - real_time;
    real_time = real_time *10;
    int t = my_futex_lock();
    printf(1,"Total wait time in milliseconds using futex lock is %d\n",tot_time*10 );
    t = t+1;
    my_unlock();
    exit();
    }

  }
  for(int i=0;i<n_children;i++)
  wait();
  exit();

 
}
