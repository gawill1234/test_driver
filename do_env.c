/***************************************************************************/
/*
 *   Author:  Gary Williams
 *   Made safe for uclibc
 *
 */
#include "defs.h"


void doenv()
{
char *testroot = NULL;

   tmpdirname = (char *)calloc(8, 1);
   strcpy(tmpdirname, "/tmp");

   testroot = getenv("TEST_ROOT");

   if (testroot == NULL) {
      printf("TEST_ROOT not set, exiting\n");
      fflush(stdout);
      exit(1);
   }
  

   //printf("TEST_ROOT=%s\n", getenv("TEST_ROOT"));
   //printf("TEST_BIN=%s\n", getenv("TEST_BIN"));
   //printf("PATH=%s\n", getenv("PATH"));
   //fflush(stdout);

   return;
}
