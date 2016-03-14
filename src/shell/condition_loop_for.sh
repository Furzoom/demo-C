#!/bin/bash

# 1.
for i in 1 2 3 4 5
do
    echo "Welcome $i times"
done

# 2.
if [ $# -eq 0 ]
then
    echo "Error - Number missing from command line argument"
    echo "Syntax : $0 number"
    echo "Use to print multiplication table for given number"
    exit 1
fi

n=$1;
for i in 1 2 3 4 5 6 7 8 9 10
do
    echo "$n * $i = `expr $n \* $i`"
done

# 3.
for ((i = 0; i <= 5; i++))
do
    echo "Welcome $i times"
done

# 4.
for ((i = 1; i <= 5; i++))
do
    for ((j = 1; j <= 5; j++))
    do
        echo -n "$i "
    done
    echo ""
done

# 5.
for ((i = 1; i <= 9; i++))
do
    for ((j = 1; j <= 9; j++))
    do
        tot=`expr $i + $j`
        tmp=`expr $tot % 2`
        if [ $tmp -eq 0 ]
        then
            echo -e -n "\033[47m  "
        else
            echo -e -n "\033[40m  "
        fi
    done
    echo -e -n "\033[40m"
    echo ""
done

