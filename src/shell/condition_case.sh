#!/bin/bash
if [ -z $1 ]
then
    rental="*** Unknow vehicle ***"
elif [ -n $1 ]
then
    rental=$1
fi

case $rental in
    "car") echo "For $rental Rs.20 per k/m";;
    "van") echo "For $rental Rs.10 per k/m";;
    "jeep") echo "For $rental Rs.5 per k/m";;
    "bicycle") echo "For $rental Rs.20 paisa per k/m";;
    *) echo "Sorry, I can not gat a $rental for you";;
esac