#!/bin/bash
i=1
n=10
while [ $i -le 10 ]
do
    echo "$i * $n = `expr $i \* $n`"
    i=`expr $i + 1`
done
