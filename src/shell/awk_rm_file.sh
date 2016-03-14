BEGIN {
}

{
    dcmd = "rm " $1
    if (system(dcmd) != 0)
        printf "rm command NOT successful\n"
    else
        printf "rm command is successful and %s file is removed\n", $1
}

END {
}
