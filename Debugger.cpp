#include "Debugger.h"
int main()
{
   //freopen("output.txt", "a+", stdout);
   int i = 0;
   while(1)
   {
    PRINT_LOG("%d",i);
    i++;
    usleep(100);
    if(i == 50)
    {

        break;
    }

   }
    return 0;
}
