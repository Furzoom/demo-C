#!/bin/bash

file="`pwd`/ginfo.sh"
dir=`pwd`

if test -s $file
then
    echo "Non empty file"
else
    echo "empty file"
fi

if test -f $file
then
    echo "normal file"
else
    echo "not normal file"
fi

if test -d $dir
then
    echo 'directory'
else
    echo 'no directory'
fi

if test -w $file
then
    echo 'writable file'
else
    echo 'non writable file'
fi

if test -r $file
then
    echo 'read-only file'
else
    echo 'non read-only file'
fi

if test -x $file
then
    echo 'executable file'
else
    echo 'non executable file'
fi
