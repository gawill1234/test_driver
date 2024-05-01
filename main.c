/***************************************************************************/
/*
 *   Author:  Gary Williams
 *   Made safe for uclibc
 *
 */
#include "defs.h"

int main(int argc, char **argv)
{
char mystr[READLEN];
char *usefile, *buf;
int done, i, slotid;
struct timespec mine;

   done = 0;

   SLEEPTIME = 2;

   driversetup(argc, argv);

   mine.tv_sec = SLEEPTIME;
   mine.tv_nsec = 50000;
   usefile = NULL;
   optDir = NULL;

   /*****************************************/
   /**  If we are using the timed option,  **/
   /**  get now, so we can use it for time **/
   /**  comparisons as we go.              **/
   setstarttime();

   //fprintf(runfp, "<gtd>\n");
   fprintf(runfp, "<pid>%d</pid>\n", getpid());
   buf = getmydate();
   if (buf != NULL) {
      fprintf(runfp, "<sdate>%s</sdate>\n", buf);
      free(buf);
   }
   fprintf(runfp, "<stime>%ld</stime>\n", GL_start_time);

   fflush(runfp);

   do {

      /*********************************************/
      /**  The randomizer.  If enabled, generate  **/
      /**  a random order test file for use by    **/
      /**  the driver.  Uses a file so that if    **/
      /**  something happens (like a crash), the  **/
      /**  run in question can be recreated.      **/
      if (GL_dorandom) {
         usefile = newTestFileData(infile, usefile);
      } else {
         usefile = infile;
      }

      fp = fopen(usefile, "r");
      if (fp == NULL) {
         printf("GTD:  Could not open input file:  %s\n", infile);
         exit(0);
      }

      do {
         for (i = 0; i < READLEN; i++)
            mystr[i] = '\0';
         if (readline(fp, mystr)) {
            if (strlen(mystr) > 1) {
               if (mystr[0] != '#') {
                  slotid = dohickey(mystr);
                  nanosleep(&mine, NULL);
                  runit(slotid);
               }
#ifdef DEBUG
               else {
                  printf("COMMENT:  %s\n", mystr);
                  fflush(stdout);
               }
#endif
            }
         } else {
            done = 1;
         }

         /***************************************/
         /**  Are we out of time(if enabled)?  **/
         if (RUN_TIME > 0)
            GL_time_over = checktime();

      } while ((!done) && (!GL_time_over));

      /***************************************/
      /**  Close the existing file because  **/
      /**  we may be generating a new one.  **/
      fclose(fp);

      /***************************************/
      /**  Are we out of time(if enabled)?  **/
      /**  Are we just done?  End of file   **/
      /**  for a single pass ...            **/
      if (RUN_TIME == 0) {
         GL_time_over = 1;
      } else {
         done = 0;
         GL_time_over = checktime();
      }

   } while (!GL_time_over);

   /*********************************************/
   /**  Wait of the remaining tests to finish  **/
   hardwait();

   buf = getmydate();
   if (buf != NULL) {
      fprintf(runfp, "<edate>%s</edate>\n", buf);
      free(buf);
   }
   fprintf(runfp, "<etime>%d</etime>\n", (int)time((time_t *)NULL));
   //fprintf(runfp, "</gtd>\n");

   fflush(runfp);

   printf("RUN TIME:  %ld seconds\n", ((int)time((time_t *)NULL) - GL_start_time));

   exit(0);
}
