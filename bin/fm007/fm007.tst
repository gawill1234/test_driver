#!/bin/bash

gfortran -o fm007 FM007.f
x=$?

if [ $x -ne 0 ]; then
   echo "fm007: compilation failed"
   exit 1
else
   echo "fm007: compilation passed"
fi

if ! [ -f ./fm007 ]; then
   echo "fm007: fm007 file NOT created"
   exit 1
else
   echo "fm007: fm007 file created"
fi


./fm007
x=$?

if [ $x -ne 0 ]; then
   echo "fm007: test failed"
   exit 1
else
   echo "fm007: test passed"
fi

exit $x
