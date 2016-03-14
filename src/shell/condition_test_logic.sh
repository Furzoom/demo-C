#!/bin/bash
s1="abc"
s2=""

if test ! $s2
then
    echo "empty"
else
    echo "Non empty"
fi

if test "$s2" = ""
then
    echo "\$2 is empty"
else
    echo "\$2 is not empty"
fi

if test "$s1" = 'abc' -a "$s2" = ''
then
    echo "yes"
else
    echo "no"
fi
    
if test "$s1" != 'abc' -o "$s2" != ''
then
    echo "yes"
else
    echo "no"
fi
