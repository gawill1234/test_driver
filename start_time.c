/***************************************************************************/
/*
 *   Author:  Gary Williams
 *   Made safe for uclibc
 *
 */
#include "defs.h"

void setstarttime()
{
   GL_start_time = time((time_t *)NULL);
   GL_end_time = GL_start_time + RUN_TIME;
}

int checktime()
{
time_t now;

   now = time((time_t *)NULL);

   if (now > GL_end_time)
      return(1);
   else
      return(0);
}
