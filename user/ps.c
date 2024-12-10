#include "kernel/types.h"
#include "user/user.h"
static char *states[] = {
  "unused",
  "used",
  "sleep",
  "runnable",
  "running",
  "zombie"
  };

int main() {
    struct pstat p;

    // Call getpinfo to retrieve process information
    if (getpinfo(&p) < 0) {
        printf("Error: Unable to retrieve process information\n");
        return -1;
    }

    // Print process information
    
for (int i = 0; i < p.usedProcs; i++) {
    printf("NAME: %s, PID: %d, PPID: %d, STATE: %s, PRIORITY: %d, SIZE: %d\n",
        p.name[i],
        p.pid[i],
        p.ppid[i],
        states[p.state[i]],
        p.priority[i],
        p.size[i]);
    }
    return 0;
}