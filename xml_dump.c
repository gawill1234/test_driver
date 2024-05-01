/***************************************************************************/
/*
 *   Author:  Gary Williams
 *   Made safe for uclibc
 *
 */
#include "defs.h"

void xmldump(int slotid)
{
   fprintf(runfp, "<test>\n");
   fprintf(runfp, "<pid>%d</pid>\n", running_tests[slotid].pid);
   fprintf(runfp, "<stime>%d</stime>\n", running_tests[slotid].start_time);
   fprintf(runfp, "<name>%s</name>\n", running_tests[slotid].name);
   fprintf(runfp, "<parent>");
   if (running_tests[slotid].suite != NULL) {
      fprintf(runfp, "/%s", running_tests[slotid].suite);
   } else {
      fprintf(runfp, "/UNKNOWN");
   }
   if (running_tests[slotid].category != NULL) {
      fprintf(runfp, "/%s", running_tests[slotid].category);
   } else {
      fprintf(runfp, "/UNKNOWN");
   }
   fprintf(runfp, "</parent>\n");
   fprintf(runfp, "<loc>%s</loc>\n", running_tests[slotid].directory);
   fprintf(runfp, "<path>%s</path>\n", running_tests[slotid].path);
   fprintf(runfp, "<info>%s</info>\n", running_tests[slotid].cmdline);
   if (running_tests[slotid].resstat == 0)
      fprintf(runfp, "<result>Test Passed</result>\n");
   else
      fprintf(runfp, "<result>Test Failed</result>\n");
   fprintf(runfp, "<etime>%d</etime>\n", running_tests[slotid].end_time);
   fprintf(runfp, "</test>\n");

   fflush(runfp);
}
