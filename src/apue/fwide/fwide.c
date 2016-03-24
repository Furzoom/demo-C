/**
 * fwide()
 */

#include "unp.h"
#include <wchar.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    int stream_orientation;
    char buf[128];
    //wchar_t wbuf[128];

    if (argc < 2)
        err_quit("usage: %s <filepath>", argv[0]);
    if ((fp = fopen(argv[1], "r")) == NULL)
        err_sys("fopen error");
    if (fgets(buf, sizeof(buf), fp) == NULL)
        err_sys("fgets error");
    stream_orientation = fwide(fp, 0);
    fclose(fp);

    if (stream_orientation > 0) 
        puts("wide-character orientation");
    else if (stream_orientation < 0)
        puts("byte orientation");
    else
        puts("none orientation");
 

    if ((fp = fopen(argv[1], "r")) == NULL)
        err_sys("fopen error");
    if (fgetwc(fp) == WEOF)
        err_sys("fgetwc error");
    stream_orientation = fwide(fp, 0);
    fclose(fp);

    if (stream_orientation > 0) 
        puts("wide-character orientation");
    else if (stream_orientation < 0)
        puts("byte orientation");
    else
        puts("none orientation");
    return 0;
}
