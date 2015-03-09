#!/bin/sh

for i in ./test/exec/*;
do
        echo -n $i;
        echo -n ":\t"
        $i;

done;

exit 0