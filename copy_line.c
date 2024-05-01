/***************************************************************************/
/*
 *   Author:  Gary Williams
 *   Made safe for uclibc
 *
 */
#include "defs.h"

char *copyline(char *mystr)
{
int len;
char *line;

   len = strlen(mystr);

   /**  Any use of this is freed when freeslot is called and the data
    **  is freed.
    **/
   line = (char *)calloc(len + 1, 1);

   if (line == NULL) {
      printf("FATAL:  calloc() failed, exiting\n");
      exit(1);
   }

   sprintf(line, "%s", mystr);

   if (line[len - 1] == '\n') {
      line[len - 1] = '\0';
   }

   return(line);
}
