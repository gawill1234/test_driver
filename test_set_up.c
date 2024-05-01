/***************************************************************************/
/*
 *   Author:  Gary Williams
 *   Made safe for uclibc
 *
 */
#include "defs.h"

void testsetup(char *cmd, int slotid)
{
char *basename(), *fullcmd, *srcdir, *mangle;
char prename[64];
int dirlen;

   if (running_tests[slotid].newsess == 1)
      setsid();

   /****************************************************/
   /*   Files required by driver could interfere with
    *   a test.  Close them.
    */
   fclose(runfp);
   fclose(outfp);
   fclose(failfp);
   fclose(fp);

   signal(SIGHUP, SIG_DFL);
   signal(SIGINT, SIG_DFL);

   signal(SIGUSR1, SIG_DFL);
   signal(SIGUSR2, SIG_DFL);

   signal(SIGABRT, SIG_DFL);
   signal(SIGSTOP, SIG_DFL);
   signal(SIGQUIT, SIG_DFL);
   signal(SIGTERM, SIG_DFL);

   copydirectory(running_tests[slotid].path, running_tests[slotid].directory);

   if (chdir(running_tests[slotid].directory) != 0) {
      printf("GTD:  Could not enter test directory %s\n",
              running_tests[slotid].directory);
      fflush(stdout);
      exit(-1); 
   }

   /********************************************/
   /*   Do copydir junk here.
    */
   if (running_tests[slotid].copy == 1) {
      dirlen = strlen(cmd);
      mangle = (char *)malloc(dirlen + 10);
      strcpy(mangle, cmd);
      srcdir = dirname(mangle);
      copydirectory(srcdir, running_tests[slotid].directory);
      free(mangle);
   }

   move_std_files(running_tests[slotid].directory, running_tests[slotid].name);

   /****************************************************/
   /*    Run a ".pre" setup file for a test if it exists.
    */
   sprintf(prename, "%s.pre", running_tests[slotid].name);
   if ((fullcmd = findcmd(prename)) != NULL) {
      system(fullcmd);
      free(fullcmd);
   }


   return;
}
