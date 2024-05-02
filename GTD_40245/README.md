This is a directory  that is produced by gtd.  It contains:
```
RESULTS - a file with the actual results
RUNTESTS.xml - a file with test run information stored as xml
FAILURES - a file saved as a test list so the failed tests can be rerun easily.
```
Also, there will be test directories.  In this case, fm001.  fm001 is a failed test
so the run data was kept to be reviewed.  You can have the driver keep all run data
by specifying the -k option to gtd.  This will cause the passing test data to be held
as well.

Within the test directory there will be a number of files.
```
FM001.f and fm001.tst  - the test source files
fm001 - the compiled test program
fm001.stdin,stderr,stdout - the input and output of the test
```
The file "prefix" (fm001) will vary based on source files and test name.
