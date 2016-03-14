#!/bin/bash
#
# comparision strings

if test "abc" == "abc"
then
    echo "=="
else
    echo "!="
fi

s1=""
if test $s1
then
    echo "\$s1 is NOT empty"
else
    echo "\$s1 is empty"
fi

s1=""
# not correct
if test -n $s1
then
    echo "\$s1 is NOT empty"
    echo "-$s1-"
else
    echo "\$s1 is empty"
fi

if test -z $s1
then
    echo "\$s1 is empty"
else
    echo "\$s1 is NOT empty"
fi
