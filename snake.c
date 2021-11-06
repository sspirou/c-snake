#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>
#include <signal.h>

#define BOARD_WIDTH 40
#define BOARD_HEIGHT 25

static const int updateTime = 100000;  // 100 milliseconds

typedef enum
{
    FALSE,
    TRUE
} bool;

typedef enum
{
    UP,
    RIGHT,
    DOWN,
    LEFT
} direction;

struct Snake
{
    int x;
    int y;
    int length;
    direction direction;
};

////// GLOBALS
struct Snake s;
bool playing = TRUE;
//////

bool getIsBoarderCoordinate(int x, int y)
{
    return (y == 0 || y == BOARD_HEIGHT - 1) || (x == 0 || x == BOARD_WIDTH - 1);
}

void drawBoard(struct Snake *snake)
{
    system("clear");
    for (int y = 0; y < BOARD_HEIGHT; y++)
    {
        for (int x = 0; x < BOARD_WIDTH; x++)
        {
            if (getIsBoarderCoordinate(x, y))
            {
                write(STDOUT_FILENO, "#", 1);
            }
            else
            {
                write(STDOUT_FILENO, " ", 1);
            }
        }
        write(STDOUT_FILENO, "\n", 1);
    }
}

static void update(int signum)  // SIGALRM
{
    drawBoard(&s);
}

static void setAlarmHandler(void)
{
    struct sigaction act;

    act.sa_handler = update;
    act.sa_flags = SA_RESTART;
    sigfillset(&act.sa_mask);

    sigaction(SIGALRM, &act, NULL);
}

static void setTimer(void)
{
    struct itimerval it;

    it.it_interval = (struct timeval) { .tv_usec = updateTime };
    it.it_value = it.it_interval;

    setitimer(ITIMER_REAL, &it, NULL);
}

void initializeSnake(){
    s.x = 10;
    s.y = 10;
    s.length = 3;
    s.direction = DOWN;
}

int main(int argc, char *argv[])
{
    setAlarmHandler();
    setTimer();

    initializeSnake();

    while (playing)
    {
        //
    }

    _exit(EXIT_SUCCESS);
}