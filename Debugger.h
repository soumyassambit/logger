#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

using namespace std;

string GetTimeForLog();
#define PRINT_LOG(f_, ...)\
do\
{\
    FILE* pFile = fopen("logFile.log", "a+");\
    if(!pFile)\
    {\
        break;\
    }\
    fprintf(pFile,"%s:: at \"%s:%d\" \t in the function %s:> ",GetTimeForLog().c_str(),__FILE__,__LINE__,__func__);\
    fprintf(pFile,(f_), __VA_ARGS__);\
    fprintf(pFile,"\n");\
    fclose(pFile);\
}\
while(0)

string GetTimeForLog()
{

    struct timeval tv;
    time_t nowtime;
    struct tm *nowtm;
    char tmbuf[64], buf[64];
    gettimeofday(&tv, NULL);
    nowtime = tv.tv_sec;
    nowtm = localtime(&nowtime);
    strftime(tmbuf, sizeof tmbuf, "%Y-%m-%d %H:%M:%S", nowtm);
    snprintf(buf, sizeof buf, "%s:%06ld", tmbuf, tv.tv_usec);
   // printf("%s\n",buf);
    return buf;
}
