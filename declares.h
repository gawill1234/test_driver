char *buildPath();
void checktmpdir();
void cleardir();
int clearDirectory();
void dostatus();
void clearLineUseTrack();
int copydirectory();
int copyfile();
char *copyline();
int create_nested_directories();
void dirsetup();
void doenv();
char **domyargs();
int whyNotRun();
void dofail();
int doTestCount();
int dohickey();
void driversetup();
void dumpline();
void envvarreplace();
int escapeWS();
long getFSType();
int fsIsNFS();
int dirAttFS();
int direxist();
int fileexist();
void validateInFile();
void do_reopen();
void move_std_files();
void fillNewFile();
char *findcmd();
int findend();
int findslotbypid();
int findThis(char *, int, char);
void flusholdtests();
void freeslot();
char *getmydate();
int getopenslot();
char *getTestLine();
void killit();
void killMyResiduals();
void initLims();
void dumpLims();
void setLimStruct();
void getLims();
int testLims();
void makeLineUseTrack();
int mkTestDir();
int matchmode();
char *newdir();
char *newTestFileData();
char *newTestListFile();
void randomize();
int readline();
void replaceit();
int runit();
char *searchdir();
void setstarttime();
int checktime();
int streq();
void testsetup();
void version_info();
void commandLineError();
int useslot();
void hardwait();
void waitforit();
void xmldump();