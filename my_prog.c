#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  	//init();
	for(int i=0;i<10000;i++)
	{
		//my_lock();
		int g = get();
		set(g+1);
		//my_unlock();
	}
	int x = get();
	printf(1,"%d\n",x);
	exit();
 
}
