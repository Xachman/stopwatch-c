#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <curses.h>

int main(int argc, char *argv[]) {
    int curTime = 0;
    int startTime = time(NULL);
    WINDOW *w;
    char c;

    int breakTime;
    bool stop = false;
    for (;;) {
        int seconds = curTime % 60;
        int minute =  (curTime / 60) % 60;
        int hour = curTime / (60*60);


        w = initscr();
        timeout(1);
        c = getch();
        endwin();
        if(c == '\n') {
            stop = (stop)? false : true;
            if(!stop){
                stop = false;
                breakTime = time(NULL) - (curTime+startTime);
                startTime += breakTime;
            }
        }
        printf("%02d:%02d:%02d \r", hour, minute, seconds);
        fflush(stdout);
        if(!stop) {
            curTime = time(NULL) - startTime;
        }
    }
    return 0;
}