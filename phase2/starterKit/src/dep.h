#ifndef DEP_H
#define DEP_H

#include <umps3/umps/libumps.h>
#include <umps3/umps/types.h>
#include <umps3/umps/const.h>
#include <umps3/umps/arch.h>
#include <umps3/umps/cp0.h>
#include "const.h"
#include "./headers/pcb.h"
#include "./headers/msg.h"
#include "debug.h"
#include "../../../phase3/include/vmSupport.h"


#define NDEV 6

extern int processCount, softBlockCount, currPid;

extern cpu_t prevTod;

extern struct list_head ready_queue;
extern struct list_head blockedForClock;

extern struct list_head blockedForDevice[NDEV];
/*

  element 0 : struct list_head blockedForDisk;
  element 1 : struct list_head blockedForFlash;
  element 2 : struct list_head blockedForEthernet;
  element 3 : struct list_head blockedForPrinter;
  element 4 : struct list_head blockedForRecv;
  element 5 : struct list_head blockedForTransm;

*/

#define blockedForRecv blockedForDevice[4]
#define blockedForTransm blockedForDevice[5]

extern pcb_t *current_process;

extern pcb_t *ssi_pcb;

extern struct list_head pcbFree_h;

extern void terminate_process(pcb_t *arg);

extern void memcpy(void *dest, void *src, unsigned int n);

extern cpu_t getTimeElapsed ();

extern void interruptHandler(); 

extern void scheduler();

extern void exceptionHandler ();

extern void SSI_function_entry_point ();

extern void getRemainTime(pcb_t *target);

extern void ssi_terminate_process(pcb_t* proc);

extern unsigned int SSIRequest(pcb_t* sender, ssi_payload_t *payload);

extern void saveState(state_t* dest, state_t* to_copy);

extern void SSI_entry_point();

extern int sendMessage(pcb_t *sender, pcb_t *dest, unsigned int payload);

extern void getDeltaTime(pcb_t *p) ;


#endif