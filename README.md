# test_driver
A driver to run tests.
Sorry, this is a little disorganized at the moment. Working on it ...

Questions: gawill1234@gmail.com
Put "github: test_driver" in the subject line.

Build (for now):
```
gcc -c -DMACBOOK *.c
gcc -o gtd *.o

or, if not a macbook,
gcc -c *.c
gcc -o gtd *.o
```
The difference above.  Linux will use sys/vfs.h.   The macbook will use sys/mount.h.

More information coming.

This is a test driver.  It will take a list of tests and run them.  Then save the results for
later review.

The tests are easy.  It can be ANY executable provided that the executable has an exit status.
The default is exit 0 (zero) means pass.  Anything else is a fail.  It can be changed.
For multi-file tests, the best way to do things it so put all of the files in a directory with the
same name as the test.  For example, for test fm006.tst, there is a directory named fm006 which
contains all of the files for that test.  The driver will use the test prefix (fm006) as the full
name and if it encounters a directory of that name, it will copy it to its run  area.  A sample  of
this is in the GTD_* directory.  If you look in fm001, you will see all of the test files plus the
saved output.  The actual final test results are in the RESULTS file.

There is a test list (goofy.gtd) as an example.  Each line in the file should be one test.

You will need to set a TEST_ROOT environment variable.
The executable test files will need to be in your PATH.

So:
```
export TEST_ROOT=$HOME/test_driver
export PATH=$PATH:$TEST_ROOT/bin
```
That should be enough for it to run.

Command to run:
```
./gtd -k -i ./goofy.gtd
```
The -k option will cause the run to keep ALL test runs.  Without -k, it will only keep  the failed
runs.

```
Usage:  gtd -i <input_file> -o <results_file> -C <number>
            -T <default_timeout> -t <run_time> -r <repeat_cnt>
            -n -k -R -D <directory>

All options except the -i option are optional.  -i must be specified.

   -i <input_file>     :  file is a list of test command lines
      default:  none, you must supply a test list (suffix = .gtd)
   -D <directory>      :  User specified run directory
      default:  The current directory
   -o <results_file>   :  file is where result should go
      default:  RESULTS
   -x <results_xml_file>   :  file is where XML result should go
      default:  RUNTESTS.xml
   -C <number>         :  number is the quantity of test running at all times
      default:  1, MAX=32
   -T <default_timeout>:  How long a test should run before begin killed
      default:  28800 seconds (8 hours)
   -t <run_time>       :  How long should this driver run
      default:  one complete pass through the test list
   -r <repeat_cnt>     :  How many time should a given test be run in a row
      default:  1
   -n                  :  All tests run in new session
      default:  no
   -k                  :  Keep ALL test results
      default:  dispose of passing results
   -R                  :  Randomize test list
      default:  run list in order given
   -a                  :  Put all results in results file
      default:  ignore results for unsupported or tests not found

Generated Files:
   RESULTS             :  List of test results (unless changed, above)
   RUNTESTS.xml        :  List of completed tests in XML format
   FAILURES            :  Command lines of the failed tests
   DRVLSxxx            :  Generated if the -R option is specified
                          xxx is generated by tempnam().  A new file
                          is generated for each pass through the list
                          and the old file is destroyed.

Generated Directories:
   GTD_<pid>           :  Directory which gtd moves into to run tests
   <test_name>         :  A directory named after the test is created
                          for each test to run in.  This directory and
                          its contents are destroyed for passing tests
                          unless -k is specified
```
