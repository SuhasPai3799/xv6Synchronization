#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "spinlock.h"


int glob_counter ;
struct spinlock counter_lock;
int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{

  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}
void sys_init(void)
{
  glob_counter = 0;
  initlock(&counter_lock, "counter_lock");
  return;
}
int sys_get(void)
{
  int x;
  //acquire(&counter_lock);
  x = glob_counter;
  //release(&counter_lock);
  return x;
}
void sys_set(int x)
{
  
  //acquire(&counter_lock);
  acquire(&counter_lock);
  glob_counter++;
  //wakeup(&glob_counter);
  release(&counter_lock);
  // wakeup(&glob_counter);
  // release(&counter_lock);
  return;
}
void sys_my_lock(void)
{
  acquire(&counter_lock);
  return;
}
void sys_my_unlock(void)
{
  wakeup(&glob_counter);
  release(&counter_lock);
  return;
}