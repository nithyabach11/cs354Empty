#include <xinu.h>

bool8 isBadPid(pid32 pid) {
  if (pid < 0 || pid >= NPROC) return true;
  if (pid == NULLPROC || pid == PR_FREE) return true;
  if (proctab[pid].prstate == PR_FREE) return true;

  return false;
}

syscall cpuusage(pid32 pid) {
  struct procent *ptrptr;
  uint32 total_cpu;

  if (!isBadPid(pid)) {
    prptr = &proctab[pid]
    if (prptr->prstate == PR_FREE) return SYSERR;
    else if (prptr->prstate != PR_CURR) total_cpu = prptr->prcpu;
    else total-cpu = prptr->prcpu + currcpu;
    return total_cpu;
  }
  else return SYSERR;
}
