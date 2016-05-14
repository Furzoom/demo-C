#!/usr/bin/awk -f

BEGIN {
    printf("#include \"unp.h\"\n\n")
    printf("int main()\n")
    printf("{\n");
    while (getline <"sysconf.conf" > 0) {
        printf("#ifdef %s\n", $1)
        printf("\tprintf(\"%s: %%ld\\n\", (long)%s + 0);\n", $1, $1)
        printf("#else\n")
        printf("\tprintf(\"\\\"%s\\\" NOT DEFINED\\n\");\n", $1)
        printf("#endif\n\n")
    }
    printf("return 0;\n")
    printf("}\n")
    close("sysconf.conf")
}


