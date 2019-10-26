#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  int pid = fork();
  init();
  if(pid==0)
  {
  	for(int i=0;i<10000;i++)
  	{
  		int g = get();
  		set(g+1);
  	}
  	exit();
  }
  else
  {
  	for(int i=0;i<10000;i++)
  	{
  		int g = get();
  		set(g+1);
  	}
  }
  int ret = get();
  printf(1,"%d\n", ret);
  exit();
}
