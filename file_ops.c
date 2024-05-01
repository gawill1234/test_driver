/***************************************************************************/
/*
 *   Author:  Gary Williams
 *   Made safe for uclibc
 *
 */
#include "defs.h"

/**************************************************************************/
/*   Get the file system type specified by path.
 */
long getFSType(char *path)
{
struct statfs buf;

   if (statfs(path, &buf) != (-1)) {
      return(buf.f_type);
   }

   return(-1);
}

/**************************************************************************/
/*   True/False, is file system NFS mounted.
 */
int fsIsNFS(long fstype)
{
   if (fstype == 0x6969) {
      return(1);
   }

   return(0);
}

/**************************************************************************/
/*   True/False, is file system directly mounted.
 */
int dirAttFS(char *path)
{
long fstype;

   fstype = getFSType(path);

   switch (fstype) {
      case EXT_SUPER_MAGIC:
      case EXT2_OLD_SUPER_MAGIC:
      case EXT3_SUPER_MAGIC:
      case REISERFS_SUPER_MAGIC:
      case JFFS2_SUPER_MAGIC:
      case UFS_MAGIC:
                                return(1);
                                break;
      case NFS_SUPER_MAGIC:
      default:
                                return(0);
                                break;
   }

   return(0);
}

/***************************************************************/
/*   Check for the existence of a directory
 */
int direxist(const char *directory_name)
{
struct stat buf;

   if (stat(directory_name, &buf) == 0) {
      if ((S_IFMT & buf.st_mode) != S_IFDIR)
         return(-1);
   } else {
      return(-1);
   }
   return(0);
}

/***************************************************************/
/*   Check for the existence of a file as a file or a pipe.
 */
int fileexist(char *filename)
{
struct stat buf;

   if (stat(filename, &buf) == 0) {
      if ((S_IFMT & buf.st_mode) != S_IFREG)
         if ((S_IFMT & buf.st_mode) != S_IFIFO)
            return(-1);
   } else {
      return(-1);
   }
   return(0);
}
