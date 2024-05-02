# test_driver
A driver to run tests.
Sorry, this is a little disorganized at the moment. Working on it ...

### What is it good for
What is is used for.  Compiler/interpreter testing, operating system testing,
network testing, search engine testing, database testing, UI and api testing,
...  All of those types of tests have been run using this driver.  It makes
it faster and more convenient.  At least, once it is setup.  Any application
that can use self contained tests would benefit for the added convenience and
performance of using a test driver.

You can also use it for different types of testing.  Setting the test concurrency
high can aid with load/stress testing.  And you can run self-contained performance
tests as well.

The beauty of this driver is that it is completely separate from the tests 
themselves.

### github languages
The "Languages" section of the github page says there is a lot of FORTRAN in here.  
There is not.  At least not as driver code.
There are 6 small FORTRAN files in the bin examples.  The project itself is
written entirely in C.  So, more like 98% C, 1% FORTRAN and 1% make.

### Questions: gawill1234@gmail.com
```
Put "github: test_driver" in the subject line.
```

### Build (for now):
```
gcc -c -D__MACBOOK__ *.c
gcc -o gtd *.o
OR
make mac

or, if not a macbook,
gcc -c -D__LINUX__ *.c
gcc -o gtd *.o
OR
make linux
```
The difference above.  Linux will use sys/vfs.h.   The macbook will use sys/mount.h.

More information coming.

This is a test driver.  It will take a list of tests and run them.  Then save the results for
later review.

### Test layout
The tests are easy.  It can be ANY executable provided that the executable has an exit status.
The default is exit 0 (zero) means pass.  Anything else is a fail.  It can be changed.
For multi-file tests, the best way to do things it so put all of the files in a directory with the
same name as the test.  For example, for test fm006.tst, there is a directory named fm006 which
contains all of the files for that test.  The driver will use the test prefix (fm006) as the full
name and if it encounters a directory of that name, it will copy it to its run  area.  A sample  of
this is in the GTD_* directory.  If you look in fm001, you will see all of the test files plus the
saved output.  The actual final test results are in the RESULTS file.

### FCVS
Full disclosure.  The sample fmxxx tests are from the FORTRAN Compiler Validation Suite (FCVS) available
from NiST (if you want all of it for fortran testing, it's free).  The .f (FORTRAN) files have been slightly
modified to have a proper exit status.

### Compare/golden file tests
For the moment, the missing test types are those that use compare/golden files.  It is doable, I just haven't
put an example in yet.  For those unfamiliar, this type of test generates a result file that must be 
compared to a known good result.  It's not hard to do, though you need a way to either remove the changeable
data(dates, timestamps, etc) or pull and save the bits you wish to compare to the good data.

### Example test list
There is a test list (goofy.gtd) as an example.  Each line in the file should be one test.

### Environment settings (basic):
You will need to set a TEST_ROOT environment variable.
The executable test files will need to be in your PATH.
```
export TEST_ROOT=$HOME/test_driver
export PATH=$PATH:$TEST_ROOT/bin
```
That should be enough for it to run.

### Sample run command (a common one):
```
./gtd -k -i ./goofy.gtd
```
The -k option will cause the run to keep ALL test runs.  Without -k, it will only keep  the failed
runs.

### Full usage/options list
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

### goofy.gtd
You can name the test file anything as long as the suffix is ".gtd".
The file specifies a list of tests to run, mostly.  However, you can do things specific
to each test within the file.  There are a number of key words that make that possible.
A default file looks like the example:
```
./a.tst
./b.tst
./c.tst
./987.tst
```
### Test key words
The keys are as follows:
```
TIME or RUN:  TIME=10, limits the test run time to 10 seconds
MBS: MBS=Y, Forces the test to be run standalone.  If you specify the multiple tests can be run,
     this will cause all other tests to pause until it has completed.
EXIT or  PASS: PASS=9, sets  the passing exit  value  to 9, rather than the 0 (zero) default
LOOP: LOOP=3, causes the test to be run  3 times  in a  row.
SUITE: SUITE=blah, labels the test as being part of the "blah" suite.
SESS: SESS=Y, causes the test to run in its own operating session
MCON: MCON=x, where x is an integer.  Set how many tests should start and run together.
SCON: SCON=x, where x is an integer.  Set how many copies of the same test should run together.
SCON and MCON are more like setting.  The number will stick until MCON/SCON is encountered
   again with a new number; like 1 to return to default setting.
```
Examples:
```
./a.tst
(MBS=Y)./b.tst
(MBS=Y,SESS=Y)./c.tst
(RUN=10)./987.tst
```
