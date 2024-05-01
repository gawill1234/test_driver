/***************************************************************************/
/*
 *   Author:  Gary Williams
 *   Made safe for uclibc
 *
 */
#include "defs.h"

/**************************************************************/
/*   Find a test by its process id.
 */
int findslotbypid(int pid)
{
int found, i;
   
   found = 0;
   i = 0;

   while (!found) {
      if (running_tests[i].pid == pid) {
         found = 1;
      } else {
         i++;
      }

      if (i >= MAXTESTS) {
         printf("GTD:  slot search error\n");
         found = 1;
         i = -1;
      }
   }

   return(i);
}
