/***************************************************************************/
/*
 *   Author:  Gary Williams
 *   Made safe for uclibc
 *
 */
#include "defs.h"
#include <signal.h>

/***********************************************************/
/*   KILL ROUTINES
 *       killit(), flusholdtests()
 */
/**************************************************/
/*   Send the kill signal to the hoggish child.
 */
void killit(int slotid)
{

   killMyResiduals(running_tests[slotid].pid);
   kill(running_tests[slotid].pid, SIGKILL);

   return;
}
