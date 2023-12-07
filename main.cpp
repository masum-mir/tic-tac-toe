#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include "conio.h"

void drawBoard(char *a[4][4]);
void board(int x, int y);
int main()
{
    int gd = DETECT, gm, x = 210, y = 150, i=0, j;

    char *a[4][4] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16"};

    char firstPlayer[20], secondPlayer[20];
    initgraph(&gd, &gm, "");
    setcolor(GREEN);

    // Wait for Enter key press
    outtextxy(150, 100, "Welcome to our Tic Tac Toe");
    outtextxy(170, 140, "Please click enter button.");
    while(getch() != 13);
    cleardevice();

//   while (getch() != 13); // 13 is the ASCII code for Enter

    outtextxy(220, 100, "Start Game");
    outtextxy(220, 120, "Control");
    outtextxy(220, 140, "Exits");

    while(1)
    {
        if(kbhit())
        {
            int keyb = getch();
            printf("Key::: %d", keyb);
            if(keyb == 13)
            {
                while(1)
                {
                    if(kbhit())
                    {
                        char ascii = getch();
                        printf("Second while loop: %d\n", ascii);
                        if(ascii == 13)
                        {
                            //  firstPlayer[i]='\0';
                            break;
                        }
                        else
                        {
                            //  for(ascii = 0; ascii <= 126; ascii++) {
                            firstPlayer[i++] = ascii;
                            cleardevice();
                            outtextxy(100, 80, "First Player Name: ");
                            //   char playerName[2] = {ascii, '\0'};
                            outtextxy(300, 80, &ascii);
                            //  }

                        }

                    }
                }
                cleardevice();
                outtextxy(100, 50, "Name: ");
                outtextxy(150, 50, firstPlayer);
                board(x, y);

            }
            else if(keyb == 99 || keyb == 68)
            {
                cleardevice();
                outtextxy(200, 100, "How to Play.");
            }
            else if(keyb == 27)
            {
                exit(0);
            }

        }
    }

    getch();
    closegraph();
    return 0;
}

void board(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            setfillstyle(SOLID_FILL, RED);
            rectangle(x, y, x + 70, y + 70);
            //outtextxy(x + 15, y + 15, a[i][j]);
            x += 70;
        }
        x = 210;
        y = y + 70;
    }
}

void drawBoard(char *a[4][4])
{
    printf("__________________________\n");
    printf("|%s   | %s    | %s    | %s   |\n", a[0][0], a[0][1], a[0][2], a[0][3]);
    printf("|    |      |      |     |\n");
    printf("|____|______|______|_____|\n");
    printf("|%s   | %s    | %s    | %s   |\n", a[1][0], a[1][1], a[1][2], a[1][3]);
    printf("|    |      |      |     |\n");
    printf("|____|______|______|_____|\n");
    printf("|%s   | %s   | %s   | %s  |\n", a[2][0], a[2][1], a[2][2], a[2][3]);
    printf("|    |      |      |     |\n");
    printf("|____|______|______|_____|\n");
    printf("|%s  | %s   | %s   | %s  |\n", a[3][0], a[3][1], a[3][2], a[3][3]);
    printf("|    |      |      |     |\n");
    printf("|____|______|______|_____|\n");
}
