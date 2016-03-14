BEGIN {
}

{
    sfile = $1
    dfile = $2
    cpcmd = "cp " $1 " " $2
    printf "Coping %s to %s\n", sfile, dfile
    system(cpcmd)
}

END {
}
