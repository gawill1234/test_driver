/***************************************************************************/
/*
 *   Author:  Gary Williams
 *   Made safe for uclibc
 *
 */
#include "defs.h"

/*************************************************/
/*   See if any of the child processes have been running
 *   for longer than allow.  If so, kill the pigs.
 */
void flusholdtests()
{
int curr_time, i, tstdone;

   curr_time =(int)time((time_t *)NULL);

   for (i = 0; i < MAXTESTS; i++) {
      if (running_tests[i].pid > 0) {
         tstdone = running_tests[i].start_time + running_tests[i].max_time;
         if (curr_time > tstdone) {
            killit(i);
         }
      }
   }

}
/*
 *   END OF KILL ROUTINES
 */
/******************************************************/
