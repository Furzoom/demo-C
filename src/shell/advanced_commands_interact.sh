#!/bin/bash

echo Your good name please :
read na
echo Your age please :
read age
echo Hello $na, next year you will be `expr $age + 1`
