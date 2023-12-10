#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include "conio.h"

void drawBoard(char *a[4][4]);
void board(int x, int y);

int handleClick(int x, int y)
{
    // Map mouse coordinates to board position
    if (x < 100 && y < 100) return 0;
    if (x >= 100 && x < 200 && y < 100) return 1;
    if (x >= 200 && y < 100) return 2;
    if (x < 100 && y >= 100 && y < 200) return 3;
    if (x >= 100 && x < 200 && y >= 100 && y < 200) return 4;
    if (x >= 200 && y >= 100 && y < 200) return 5;
    if (x < 100 && y >= 200) return 6;
    if (x >= 100 && x < 200 && y >= 200) return 7;
    if (x >= 200 && y >= 200) return 8;

    return -1; // Click outside the board
}


void controlPanals()
{
    cleardevice();
    outtextxy(220, 100, "Start Game");
    outtextxy(220, 120, "Control");
    outtextxy(220, 140, "Exits");
}

void inputPlayerName(char firstPlayer[], char secondPlayer[], int i, int j)
{
    cleardevice();
    outtextxy(120, 80, "First Player Name: ");
    while(1)
    {
        if(kbhit())
        {
            char ascii = getch();
            printf("Player One: %d\n", ascii);
            if(ascii == 13)
            {
                //  firstPlayer[i]='\0';
                break;
            }
            else
            {
                //  first player name
                firstPlayer[i++] = ascii;
                firstPlayer[i]=0;
                outtextxy(250, 80, firstPlayer);
            }
        }
    }
    cleardevice();
    outtextxy(120, 80, "Second Player Name: ");
    while(1)
    {
        if(kbhit())
        {
            char ascii = getch();
            printf("Player two ::; %d", ascii);
            if(ascii==13)
            {
                break;
            }
            else
            {
                // second player name
                secondPlayer[j++] = ascii;
                secondPlayer[j]=0;
                outtextxy(270, 80, secondPlayer);
            }
        }
    }
}

int main()
{
    int gd = DETECT, gm, x = 210, y = 150, i=0, j=0;

    char *a[4][4] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16"};

    char firstPlayer[20], secondPlayer[20];
    initgraph(&gd, &gm, "");
    setcolor(GREEN);

    // Wait for Enter key press
    outtextxy(150, 100, "Welcome to our Tic Tac Toe");
    outtextxy(170, 140, "Please click enter button.");
    while(getch() != 13);

    controlPanals();

    while(1)
    {
        if(kbhit())
        {
            int keyb = getch();
            printf("Key::: %d", keyb);
            if(keyb == 13)      // start game
            {
                inputPlayerName(firstPlayer, secondPlayer,i, j);

                cleardevice();
                outtextxy(120, 70, "Player One: ");
                outtextxy(210, 70, firstPlayer);
                outtextxy(120, 100, "Player Two: ");
                outtextxy(210, 100, secondPlayer);
                // board show
                int mouseClick = 0;
                int mouseX, mouseY;
               /* while(!kbhit())
                {


                    if(ismouseclick(WM_LBUTTONDOWN))
                    {
                        getmouseclick(WM_LBUTTONDOWN, mouseX, mouseY);
                        mouseClick = 1;
                        printf("mouse click: %d \n", mouseClick);
                       // circle(mouseX, mouseY, 10);
                        clearmouseclick(WM_LBUTTONDOWN);
                    }

                }

                printf("\n\nMouse click::: %d \n\n", mouseClick);

                int result = handleClick(mouseX, mouseY);
                printf("Result :: %d ", result);

                if(result != -1)
                {
                    if(a[0][0] == " ")
                    {
                        a[0][0] = "X";
                    }
                }
*/
                board(x, y);

            }
            else if(keyb == 99 || keyb == 68) // control
            {
                cleardevice();
                outtextxy(200, 100, "How to Play.");
                if(kbhit())
                {
                    char ctr = getch();
                    if(ctr == 98)
                    {
                        controlPanals();
                    }

                }
            }
            else if(keyb == 27)  // exit
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
    outtextxy(300, 30, "TIC TAC TOE");
    line(300,50, 380, 50);
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

void startGame()
{

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
