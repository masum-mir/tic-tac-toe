#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <time.h>
#define ROW 4
#define COL 4

void drawBoard(char *a[ROW][COL]); // drawing board normal
void board(int x, int y, char *board[ROW][COL], char nameF[], char nameS[]); // drawing board graphics
int gameWin(char *arr[ROW][COL], int player);  // game win logic
void currentTime();  // current time display
void homePage(int x, int y); // first home page
int handleClick(int x, int y);  // board click cursor
int controlPanalsXYcordinate(int x, int y);     // control click cursor
void controlPanals();   // control panals
void inputPlayerName(char firstPlayer[], char secondPlayer[]);    // player input
void mouseEvent();

int xy;

int main()
{
    int gd = DETECT, gm, x = 210, y = 150, i=0, j=0;
    char firstPlayer[20], secondPlayer[20];
    //char* firstPlayer = (char)*malloc(10);
    //char* secondPlayer = (char)*malloc(10);
    int currentPlayer = 1, mouseX, mouseY;

    char *a[ROW][COL] = {" ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "};


    initgraph(&gd, &gm, "");

    homePage(x, y);

    while(getch() != 13);

    controlPanals();

    while(1)
    {

        int mouseClick = 0;
        int mouseXX, mouseYY;
        while (!mouseClick)
        {
            if (ismouseclick(WM_LBUTTONDOWN))
            {
                getmouseclick(WM_LBUTTONDOWN, mouseXX, mouseYY);
                mouseClick = 1;
                printf("mouse click: %d \n", mouseClick);
            }
        }

        // dynamic mouse cursor
        /*
                int* mousePtr;
                mousePtr = mouseclickEvent();
                printf("\n\nXX : %d, YY : %d\n\n", (int)mousePtr[1], (int)mousePtr[2]);
                free(mousePtr);
        */

        int r = controlPanalsXYcordinate(mouseXX, mouseYY);
        printf("\n Option selected first :: %d \n\n", r);

        // if(kbhit())
        if(r!=-1)
        {

            //int keyb = getch();
            //if(keyb == 13)      // start game

            if(r==1)
            {
                printf("\nR IS ::: %d\n", r);
                inputPlayerName(firstPlayer, secondPlayer);

                //while(!kbhit())
                while(1)
                {
                    // board show
                    cleardevice();
                    board(x, y, a, firstPlayer, secondPlayer);

                    // mouse click event
                    int mouseClick = 0;
                    int mouseX, mouseY;
                    while(!mouseClick)
                    {
                        if(ismouseclick(WM_LBUTTONDOWN))
                        {
                            getmouseclick(WM_LBUTTONDOWN, mouseX, mouseY);
                            mouseClick = 1;
                        }
                    }

                    // board handle in mouse click
                    int result = handleClick(mouseX, mouseY);
                    //printf("Result :: %d ", result);

                    if(result != -1)
                    {
                        int row = result / ROW;  // row position
                        int col = result % COL;  // col position
                        //printf("\n\nRow :: %d Col:: %d\n\n", row,col);
                        //   char ch2 = (result == 1) ? "X" : "O";
                        //printf("\n\n %c \n\n", a[row][col]);

                        if(a[row][col] == " ")
                        {
                            // char *c = (currentPlayer==1) ? 'X' : 'O';
                            // char *p = &c;
                            //  a[row][col] = (currentPlayer==1) ? 'X' : 'O';

                            //printf("\n\nCUrrent player :: X OR O\n\n");
                            if(currentPlayer == 1)
                            {
                                //printf("\n\nCurrent player :: X\n\n");
                                a[row][col] = "X";
                                //circle(mouseX, mouseY, 10);
                                //printf("\n\n %c \n\n", a[row][col]);
                                //currentPlayer = 2;
                            }
                            else
                            {
                                //printf("\n\nCurrent player :: O\n\n");
                                a[row][col] = "O";
                                // currentPlayer = 1;
                            }


                            int gameReturn = gameWin(a, currentPlayer);
                            printf("GAME RESURN ::: %d ", gameReturn);
                            if( gameReturn == 1)
                            {
                                printf("Player %c win", (currentPlayer == 1)? 'X' : 'O');
                                outtextxy(300, 450, "Player One Win!");
                                board(x, y, a, firstPlayer, secondPlayer);
                                break;
                            }
                            currentPlayer = 3-currentPlayer;        // current player first 1 then 2
                        }

                    }

                    clearmouseclick(WM_LBUTTONDOWN);                // mouse clear event

                }

            }
            // else if(keyb == 99 || keyb == 68) // controls
            else if(r==2)
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
            //else if(keyb == 27)  // exit
            else
            {
                exit(0);
            }
        }
        clearmouseclick(WM_LBUTTONDOWN);
    }


    getch();
    closegraph();
    return 0;
}

// home page
void homePage(int x, int y)
{
    setbkcolor(BLACK);
    cleardevice();
    settextstyle(EUROPEAN_FONT,HORIZ_DIR, 1.5);
    settextstyle(1,HORIZ_DIR,7);
    setcolor(LIGHTBLUE);
    outtextxy(x-60,y-60,"TIC");
    setcolor(LIGHTRED);
    outtextxy(x,y,"TAC");
    setcolor(LIGHTMAGENTA);
    outtextxy(x+70,y+60,"TOE");
    setcolor(WHITE);
    settextstyle(EUROPEAN_FONT,HORIZ_DIR, 1);
    settextstyle(1,HORIZ_DIR,1);
    outtextxy(200, 300, "Please click enter button.");  // press enter button

}

// board draw func
void board(int x, int y, char *board[ROW][COL], char nameF[], char nameS[])
{
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
    setcolor(LIGHTMAGENTA);
    outtextxy(280, 30, "TIC TAC TOE");
    line(280,50, 430, 50);

    outtextxy(100, 70, "Player One: ");
    outtextxy(240, 70, nameF);
    outtextxy(100, 100, "Player Two: ");
    outtextxy(240, 100, nameS);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            setfillstyle(SOLID_FILL, RED);
            rectangle(x, y, x + 70, y + 70);
            outtextxy(x + 15, y + 15, board[i][j]);

            x += 70;
        }
        x = 210;
        y = y + 70;
    }
    //currentTime();
}

//current time show func
void currentTime()
{
    while (1)
    {
        // cleardevice();
        time_t cTime;
        struct tm *localTime;
        cTime = time(NULL);
        localTime = localtime(&cTime);
        char timestr[10],AM[]="AM",PM[]="PM";
        if(localTime->tm_hour<12)
        {
            //  outtextxy(180,100,"AM");
        }
        else
        {
            //  outtextxy(180,100,"PM");
        }
        sprintf(timestr,"%02d:%02d:%02d",localTime->tm_hour,localTime->tm_min, localTime->tm_sec);
        outtextxy(500, 50,timestr);
        delay(1000);
    }

}

// game win check func
int gameWin(char *arr[ROW][COL], int player)
{
    printf("\n\nCurrent player:: %d\n\n", player);
    char value;
    if(player==1)
    {
        value = 'X';
    }
    else
    {
        value = 'O';
    }
    char *ptr = &value;
    printf("Check the game win");
    printf("\n\nTHE GEME WIN SLOT PTR:::: %c\n", *ptr );
    printf("\n\nTHE GEME WIN SLOT:::: %c\n", *arr[0][0] );
    for(int i=0; i<4; i++)
    {
        if((*arr[i][0]== *ptr && *arr[i][1]== *ptr && *arr[i][2]== *ptr && *arr[i][3]== *ptr ) ||
                (*arr[0][i]== *ptr && *arr[1][i]== *ptr && *arr[2][i]== *ptr && *arr[3][i]== *ptr )
          )
        {
            return 1;
        }

        if((*arr[0][0]==*ptr && *arr[1][1]==*ptr && *arr[2][2]==*ptr && *arr[3][3]==*ptr ) ||
                (*arr[0][3]==*ptr && *arr[1][2]==*ptr && *arr[2][1]==*ptr && *arr[3][0]==*ptr )
          )
        {
            return 1;
        }

    }
    return 0;

}

// 2nd page control panal func
void controlPanals()
{
    settextstyle(EUROPEAN_FONT,HORIZ_DIR, 1);
    setcolor(WHITE);
    cleardevice();
    outtextxy(220, 140, "Start Game");
    outtextxy(220, 170, "Control");
    outtextxy(220, 200, "Exits");
    /*
        while(1)
        {

            int mouseClick = 0;
            int mouseXX, mouseYY;
            while(!mouseClick)
            {
                if(ismouseclick(WM_LBUTTONDOWN))
                {
                    getmouseclick(WM_LBUTTONDOWN, mouseXX, mouseYY);
                    mouseClick = 1;
                    printf("mouse click: %d \n", mouseClick);
                    //    circle(mouseX, mouseY, 10);

                }
            }

            int r = controlPanalsXYcordinate(mouseXX, mouseYY);
            printf("\n Option first :: %d \n\n", r);
            if(r!= - 1)
            {
                if(r==1)
                {
                    xy = 13;
                }
                else if(r==2)
                {
                    xy = 66;
                    outtextxy(220, 120, "Control");
                }
                else
                {
                    xy = 33;
                    outtextxy(220, 140, "Exits");
                }
            }

            clearmouseclick(WM_LBUTTONDOWN);

        }
        */
}

// input player name    func
void inputPlayerName(char firstPlayer[], char secondPlayer[])
{
    cleardevice();
    // setcolor(BLACK);
    // setfillstyle(SOLID_FILL, RED);
    //  rectangle(30, 100, 100, 50);
    outtextxy(240, 230, "Enter");
    outtextxy(120, 150, "First Player Name: ");
    outtextxy(120, 180, "Second Player Name: ");
    int i=0, j =0;

    while(1)
    {
        if(kbhit())
        {
            char ascii = getch();
            printf("Player One: %d\n", ascii);
            if(strlen(firstPlayer) == 0)
            {
                printf("Please input first name!");
                outtextxy(120, 100, "Please input first name!");
                continue;
            }

            if(ascii == 13 && strlen(firstPlayer) != 0)
            {
                break;
            }
            else if(ascii == 8)
            {
                if (i > 0)
                {
                    i--;
                    firstPlayer[i] = '\0';
                    cleardevice();
                    outtextxy(350, 150, firstPlayer);
                    outtextxy(240, 230, "Enter");
                    outtextxy(120, 150, "First Player Name: ");
                    outtextxy(120, 180, "Second Player Name: ");
                }
            }
            else
            {
                //  first player name
                firstPlayer[i++] = ascii;
                firstPlayer[i]=0;
                outtextxy(350, 150, firstPlayer);
            }
        }

    }

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
            else if(ascii == 8)
            {
                if (j > 0)
                {
                    j--;
                    secondPlayer[j] = '\0';
                    cleardevice();
                    outtextxy(350, 150, firstPlayer);
                    outtextxy(350, 180, secondPlayer);
                    outtextxy(240, 230, "Enter");
                    outtextxy(120, 150, "First Player Name: ");
                    outtextxy(120, 180, "Second Player Name: ");
                }
            }
            else
            {
                // second player name
                secondPlayer[j++] = ascii;
                secondPlayer[j]=0;
                outtextxy(350, 180, secondPlayer);
            }
        }
    }
}


int controlPanalsXYcordinate(int x, int y)
{

    printf("\n\nFirst row : %d , col : %d\n\n", x,y);

    if((x>=220 && x<=335) && (y>=142 && y<=154))
    {
        return 1;
    }
    if((x>=220 && x<=266) && (y>=172 && y<=185))
    {

        return 2;
    }
    if((x>=220 && x<=255) && (y>=203 && y<=215))
    {

        return 3;
    }


    return -1;
}

// board click event func
int handleClick(int x, int y)
{
    printf("\n\nX ::: %d \n\n, Y ::: %d \n", x, y);

    if ( (x > 210 && x <= 280) && (y > 150 && y<=220)) return 0;
    if ( (x > 280 && x <= 350) && (y > 150 && y<=220)) return 1;
    if ( (x > 350 && x <= 420) && (y > 150 && y<=220)) return 2;
    if ( (x > 420 && x <= 490) && (y > 150 && y<=220)) return 3;

    if ( (x > 210 && x <= 280) && (y > 220 && y<=290)) return 4;
    if ( (x > 280 && x <= 350) && (y > 220 && y<=290)) return 5;
    if ( (x > 350 && x <= 420) && (y > 220 && y<=290)) return 6;
    if ( (x > 420 && x <= 490) && (y > 220 && y<=290)) return 7;

    if ( (x > 210 && x <= 280) && (y > 290 && y<=360)) return 8;
    if ( (x > 280 && x <= 350) && (y > 290 && y<=360)) return 9;
    if ( (x > 350 && x <= 420) && (y > 290 && y<=360)) return 10;
    if ( (x > 420 && x <= 490) && (y > 290 && y<=360)) return 11;

    if ( (x > 210 && x <= 280) && (y > 360 && y<=430)) return 12;
    if ( (x > 280 && x <= 350) && (y > 360 && y<=430)) return 13;
    if ( (x > 350 && x <= 420) && (y > 360 && y<=430)) return 14;
    if ( (x > 420 && x <= 490) && (y > 360 && y<=430)) return 15;

    return -1;
}

// mouse event func
int* mouseclickEvent()
{
    int n = 0;
    int mouseX, mouseY;
    int arr[10];

    while(!n)
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN, mouseX, mouseY);
            n = 1;
            printf("mouse click: %d \n", n);
        }
    }

    arr[0] = n;
    arr[1] = mouseX;
    arr[2] = mouseY;

    return arr;
}

void startGame()
{

}

// normal consol board func
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
