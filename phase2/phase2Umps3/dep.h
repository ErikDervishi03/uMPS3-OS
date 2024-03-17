#include <umps3/umps/libumps.h>
#include <umps3/umps/types.h>
#include <umps3/umps/const.h>
#include <umps3/umps/arch.h>
#include <umps3/umps/cp0.h>
#include "const.h"
#include "../phase1/headers/pcb.h"
#include "../phase1/headers/msg.h"

extern cpu_t prevTOD;
extern unsigned int processCount, softBlockCount;

extern struct list_head ready_queue;
extern pcb_t *currentProcess;

extern cpu_t getTimeElapsed ();