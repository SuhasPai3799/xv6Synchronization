#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  char *argv_1[] = { "my_prog",0 };
  char *argv_2[] = {"race_cond",0}; 
  init();
  int pid = fork();
  if(pid == 0)
  {
    exec("my_prog",argv_1);
   
  }
  else
  {
    exec("race_cond",argv_2);
    
  }
  
 
}
