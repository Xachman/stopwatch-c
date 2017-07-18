#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int count = 0;
    for (;;) {
        int seconds = count % 60;
        int minute =  (count / 60) % 60;
        int hour = count / (60*60);
        sleep(1);
        printf("%02d:%02d:%02d \r", hour, minute, seconds);
        fflush(stdout);
        count++;
    }
    return 0;
}