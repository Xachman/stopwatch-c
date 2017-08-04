#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int curTime = 0;
    int startTime = time(NULL);
    for (;;) {
        int seconds = curTime % 60;
        int minute =  (curTime / 60) % 60;
        int hour = curTime / (60*60);
        sleep(1);
        printf("%02d:%02d:%02d \r", hour, minute, seconds);
        fflush(stdout);
        curTime = time(NULL) - startTime;
    }
    return 0;
}