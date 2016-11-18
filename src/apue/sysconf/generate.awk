#!/usr/bin/awk -f

BEGIN {
    printf("#include \"unp.h\"\n")
    printf("#include <limits.h>\n\n")
    printf("int main()\n")
    printf("{\n");
    while (getline <"sysconf.conf" > 0) {
        printf("\terrno = 0;\n");
        printf("\tif (sysconf(%s) == -1 && errno != 0) {\n", $1);
        printf("\t\tprintf(\"%-25s: NOT SUPPORT!\\n\");\n", $1);
        printf("\t} else {\n");
        printf("\t\tprintf(\"%-25s: %%10ld\\n\", sysconf(%s));\n", $1, $1)
        printf("\t}\n\n");
    }
    close("sysconf.conf")
}

{
    printf("\tprintf(\"%-25s: %%10ld\\n\", pathconf(\"%s\","\
            "%s));\n", $1, $2, $1);
}

END {
    close("pathconf.conf")
    printf("return 0;\n")
    printf("}\n")
}
