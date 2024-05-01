/***************************************************************************/
/*
 *   Author:  Gary Williams
 *   Made safe for uclibc
 *
 */
#include "defs.h"
#include <signal.h>

void killMyResiduals(int pid)
{
   pid = pid * (-1);
   kill(pid, 9);
   return;
}
