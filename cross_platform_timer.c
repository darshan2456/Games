#ifdef _WIN32

#include<windows.h>
#define SLEEP(val)  Sleep(val*1000)

#else

#include <unistd.h>
#define SLEEP(val)  usleep(val*1000000)

//enter number of seconds in floating point
void sleep_seconds(float val){
    SLEEP(val);
}

#endif