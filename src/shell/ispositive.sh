# argument is positive
if test $# -eq 1
then
    if test $1 -gt 0
    then
        echo "$1 is positive"
    else if test $1 -lt 0
    then
        echo "$1 is not positive"
    else
        echo "$1 is zero"
    fi
else
    echo "Usage: $0 number"
fi
