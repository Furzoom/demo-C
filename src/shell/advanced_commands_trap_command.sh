#!/bin/bash

# version 2
del_file()
{
    echo "*** CTRL + C Trap Occurs (removing temporary file)***"
    rm -f /tmp/input0.$$
    exit 1
}

Take_input()
{
    recno=0
    clear
    echo "Appointment Note keeper Application for Linux"
    echo -n "Enter your database file name: "
    read filename
    if [ ! -f $filename ]
    then
        echo "Sorry, $filename does not exit, Creating $filename datebase"
        echo "Appointment Note keeper Application database file" > $filename
    fi
    echo "Data entry start data: `date`" >/tmp/input0.$$

    while :
    do
        echo -n "Appointment Title: "
        read na
        echo -n "time: "
        read ti
        echo -n "Any Remark: "
        read remark
        echo -n "Is data okay (y/n) ?"
        read ans
        if [ $ans = y -o $ans = Y ]
        then
            recno=`expr $recno + 1`
            echo "$recno. $na $ti $remark" >>/tmp/input0.$$
        fi
        echo -n "Add next appointment (y/n) ?"
        read isnext
        if [ $isnext = n -o $isnext = N ]
        then
            cat /tmp/input0.$$ >> $filename
            rm -f /tmp/input0.$$
            return
        fi
    done
}

trap del_file 2
Take_input
