{
    no = $1
    remn = 0
    while (no > 1)
    {
        remn = no % 10
        no /= 10
        printf "%d", remn
    }
    printf "\nNext number please (CTRL+D to stop): ";
}
