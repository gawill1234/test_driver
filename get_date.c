/***************************************************************************/
/*
 *   Author:  Gary Williams
 *   Made safe for uclibc
 *
 */
#include "defs.h"

/**********************************************/
/*  Get the date.
 */
char *getmydate()
{
struct tm *tm_ptr;
time_t the_time;
char *buf;

   buf = (char *)calloc(32, 1);
   if (buf != NULL) {
      (void) time(&the_time);
      tm_ptr = localtime(&the_time);
      strftime(buf, 32, "%F", tm_ptr);
   }

   return(buf);
}
