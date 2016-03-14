#!/bin/bash

if [ $# -eq 0 ]
then
    echo "$0 : You must give/supply one integers"
    exit 1
fi

if [ $1 -gt 0 ]
then
    echo "$1 is positive"
else
    echo "$1 is negative"
fi
