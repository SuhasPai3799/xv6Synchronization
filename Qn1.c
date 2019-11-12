#include "types.h"
#include "stat.h"
#include "user.h"


int
main(int argc, char *argv[])
{
  int  i=0;
  int st = uptime();
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
      
    for(int i=0;i<10000;i++)
    {

   
   

      int g = get();
      set(g+1);

      

    }

   
    
    exit();
    }

  }
  for(int i=0;i<n_children;i++)
  wait();
  int g = get();
  printf(1,"Statistics for program with %d children to access a shared counter is as follows :\n",n_children);
  printf(1,"Final value of the shared counter is %d\n",g);
  int end = uptime() - st;
  end = end *10;
  printf(1,"Total execution time in milliseconds is %d\n",end);
  exit();

 
}
