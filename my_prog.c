#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  	//init();
	for(int i=0;i<10000;i++)
	{
		//printf(1,"%d\n",i);
		my_lock();
		//printf(1,"%d\n",i);
		int g = get();
		set(g+1);
		//printf(1,"%d\n",i );
		my_unlock();
		//printf(1,"%d %d\n",i,g );	
	}
	int x = get();
	printf(1,"%d\n",x);
	exit();
 
}
