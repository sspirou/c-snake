#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define BOARD_WIDTH 40
#define BOARD_HEIGHT 25

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

bool playing = TRUE;

int main(int argc, char *argv[])
{
    struct timespec ts;
    ts.tv_sec = 10 / 1000;
    ts.tv_nsec = (10 % 1000) * 1000000;

    struct Snake s;
    s.x = 10;
    s.y = 10;
    s.length = 3;
    s.direction = DOWN;

    while (playing)
    {
        drawBoard(&s);

        nanosleep(&ts, &ts);
    }

    _exit(EXIT_SUCCESS);
}