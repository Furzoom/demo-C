# argument is positive
if test $# -eq 1
then
    if test $1 -gt 0
    then
    echo "$1 is positive"
    else
    echo "$1 is not positive"
    fi
else
echo "Usage: $0 number"
fi
