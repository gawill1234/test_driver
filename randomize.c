/***************************************************************************/
/*
 *   Author:  Gary Williams
 *   Made safe for uclibc
 *
 */
#include "defs.h"

/********************************************************************/
/*   Set up a random list of tests from the supplied file.  The file
 *   is save in an iterim file.  The reason is that if there is an
 *   issue, the interim file can be use to duplicate the irksome
 *   results of a bad run.
 */
void randomize(int count)
{
int i, puthere;
int tmp;

   srand48(time((time_t *)NULL));

   for (i = 0; i < count; i++) {
      puthere = (int)(drand48() * count);
      tmp = mymess[i]->line;
      mymess[i]->line = mymess[puthere]->line;
      mymess[puthere]->line = tmp;
   }
}
