#!/usr/bin/env bash

for ((i = 0; i < 20; i++))
do
    `touch $i.txt`
done

ls -l
sleep 1

rename txt ini *.txt
ls -l

rm *.ini
