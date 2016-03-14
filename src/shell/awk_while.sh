BEGIN {
    printf "Press ENTER to continue with for loop example from MN v0.1"
}

{
    sum = 0
    i = 0
    for (i = 1;i <= 10; i++)
    {
        sum += i
    }
    printf "Sum for 1 to 10 numbers = %d \nGoodbye %s\n", sum, ENVIRON["USER"]
    exit 1
}
