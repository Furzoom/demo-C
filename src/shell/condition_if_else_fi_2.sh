#!/bin/bash
osch=0
echo "1. Unix (Sun OS)"
echo "2. Linux (Red Hat)"
echo -n "Select your os choice [1 or 2]"
read osch

if [ $osch -eq 1 ]
then
    echo "You pick up Unix (Sun OS)"
else
    if [ $osch -eq 2 ]
    then
        echo "You pick up (Red Hat)"
    else
        echo "What you don't like Unix/Linun OS."
    fi
fi
