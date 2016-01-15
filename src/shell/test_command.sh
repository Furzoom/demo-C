# test command

# test mathematics
# -eq   ==      if test 1 -eq 2     if [1 -eq 2]
# -ne   !=      if test 1 -ne 2     if [1 -ne 2]
# -lt   <       if test 1 -lt 2     if [1 -lt 2]
# -le   <=      if test 1 -le 2     if [1 -le 2]
# gt    >       if test 1 -gt 2     if [1 -gt 2]
# ge    >=      if test 1 -ge 2     if [1 -ge 2]
#
# test string
# string1 =  string2    equal
# string1 != string2    not equal
# string1               length is nonzero
# -n string1            length is nonzero
# -z string1            length is zero

a='aaa'
b='aaa'
c=''

echo -n "test $a = $b: "
if test "$a" = "$b"
then
echo "Equal"
else
echo "Not equal"
fi

if test "$c"
then
echo "\$c is NOT NULL"
else
echo "\$c is NULL"
fi

if test "$a"
then
echo "\$a is NOT NULL"
else
echo "\$a is NULL"
fi

echo "\$foo is :$foo"
if test "$foo"
then
echo "\$foo is NOT NULL"
else
echo "\$foo is NULL"
fi


if test -z "$c"
then
echo "\$c is NULL"
fi

if test -z "$foo"
then
echo "\$foo is NULL"
fi

if test -n "$foo"
then
echo "\$foo is NOT NULL"
fi

