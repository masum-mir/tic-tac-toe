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
int boardXYcoordinate(int x, int y);  // board click cursor
int controlPanalsXYcordinate(int x, int y);     // control click cursor
int controlPanals();   // control panals
void inputPlayerName(char firstPlayer[], char secondPlayer[]);    // player input
void mouseEvent();
int lastMenuXYcordinate(int x, int y);  // main menu mouse click event
void mainSystem(int x, int y, int i, int j);    // main system start
void boardSystem(int x, int y, char *a[ROW][COL], char firstPlayer[], char secondPlayer[], int i, int j);   // main baord control
int gameDraw(char *a[ROW][COL]);        // game draw
void menuPage(); // menu
void playerNameShow(); // player name show
void finalMenu(char firstPlayer[], char secondPlayer[], int result); // last menu page
void finalMenuMouseclickEvent(int x, int y, char *a[ROW][COL], char firstPlayer[], char secondPlayer[], int i, int j);

void drawButton(int left, int top, int right, int bottom)
{
    setcolor(LIGHTMAGENTA);
    rectangle(left, top, right, bottom);
    setcolor(WHITE);
}

void printText(int x, int y, char *str)
{
    outtextxy(x, y, str);
}

void clearMyDevice()
{
    cleardevice();
}

int currentPlayer = 1;

int main()
{
    int gd = DETECT, gm, x = 210, y = 150, i=0, j=0;

    initgraph(&gd, &gm, "");
    setbkcolor(COLOR(10,6,33));
    clearMyDevice();

    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
    // printText(160, 200, "Made with");

    printText(160, 200, "Made with");
    for (int i = 0; i < 400; i += 5)
    {
        setcolor(COLOR(255 - i, i, 0));
        printText(330, 240, "Believers.");
        delay(20);
    }
    Sleep(10);

    clearMyDevice();
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    printText(170, 380, "LOADING PLEASE WAIT."); // loading page

    delay(1000);        // 1.5 sec sleep

    homePage(x, y);         // welcome page

    while(getch() != 13);   // enter click then next page

    mainSystem(x,y,i,j);

    getch();
    closegraph();
    return 0;
}

// home page
void homePage(int x, int y)
{
    clearMyDevice();
    settextstyle(EUROPEAN_FONT,HORIZ_DIR, 1.5);
    settextstyle(1,HORIZ_DIR,7);
    setcolor(LIGHTBLUE);
    printText(x-60,y-60,"TIC");
    setcolor(LIGHTRED);
    printText(x,y,"TAC");
    setcolor(LIGHTMAGENTA);
    printText(x+70,y+60,"TOE");
    setcolor(WHITE);
    settextstyle(EUROPEAN_FONT,HORIZ_DIR, 1);
    settextstyle(1,HORIZ_DIR,1);
    printText(200, 300, "Please click ");
    setcolor(RED);
    printText(347, 300, "Enter ");
    setcolor(WHITE);
    printText(418, 300, "button.");
}

// main system
void mainSystem(int x, int y, int i, int j)
{

    char *a[ROW][COL] = {" ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "};
    char firstPlayer[20], secondPlayer[20];
    printf("len::: %d \n", strlen(firstPlayer));
    //char* firstPlayer = (char)*malloc(10);
    //char* secondPlayer = (char)*malloc(10);
    //int currentPlayercurrentPlayer = 1, mouseX, mouseY;

    while(1)
    {
        menuPage();    // menu
        int r = controlPanals();    //
        // if(kbhit())
        if(r!=-1)
        {

            //int keyb = getch();
            //if(keyb == 13)      // start game

            if(r==1)        // start game
            {
                // playerNameShow();
                inputPlayerName(firstPlayer, secondPlayer);     // input player name
                //clearmouseclick(WM_LBUTTONDOWN); // remove auto set value but face some problem
                boardSystem(x, y, a, firstPlayer, secondPlayer, i, j);

            }
            // else if(keyb == 99 || keyb == 68) // controls
            else if(r==2)
            {
                printf("Main System 2");
                clearMyDevice();
                //printText(80, 50, "Back");
                printText(80, 50, "Back");
                printText(200, 100, "How to Play Game!");
                getch();
                /* if(kbhit())
                 {
                     char ctr = getch();
                     if(ctr == 98)
                     {
                         controlPanals();
                     }
                 }
                 */
            }
            //else if(keyb == 27)  // exit
            else
            {
                closegraph();
                exit(0);
            }
        }

    }
}

// void menuPage()
void menuPage()
{
    settextstyle(EUROPEAN_FONT,HORIZ_DIR, 1);
    setcolor(WHITE);
    clearMyDevice();

    // drawButton(210, 135, 345, 170);
    // printText(220, 140, "Start Game");

    // drawButton(210, 175, 345, 210);
    // printText(220, 180, "Control");

    // drawButton(210, 215, 345, 250);
    // printText(220, 220, "Exits");

    drawButton(260, 148, 395, 185);
    printText(270, 155, "Start Game");

    drawButton(260, 188, 395, 225);
    printText(285, 195, "Control");

    drawButton(260, 228, 395, 265);
    printText(300, 235, "Exit");
}

// 2nd page control panal func
int controlPanals()
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
    clearmouseclick(WM_LBUTTONDOWN);
    return r;
}

// player name display
void playerNameShow()
{
    printText(130, 150, "Player 1 name: ");
    printText(130, 185, "Player 2 name: ");

    drawButton(265, 245, 335, 280);
    printText(278, 252, "Play");
}

// input player name    func
void inputPlayerName(char firstPlayer[], char secondPlayer[])
{
    clearMyDevice();
    setcolor(WHITE);
    playerNameShow();

    int i=0, j =0;

    while(1)
    {
        if(kbhit())     // keyboard press
        {
            char ascii = getch();   // return ascii value
            //printf("Player One: %d\n", ascii);
            //printf("\nlength:: :%d", strlen(firstPlayer));
            /*
             if(strlen(firstPlayer) == 1)
             {
                 printf("Please input first name!");
                 printText(120, 100, "Please input first name!");
                 firstPlayer[i++] = ascii;
                 firstPlayer[i]=0;
                 printText(350, 150, firstPlayer);
                 //continue;
             }
            */
            if(ascii == 13)
            {
                if(i == 0)
                {
                    setcolor(RED);
                    printText(120, 100, "Please input first player name!");
                    setcolor(WHITE);
                    continue;
                }
                break;
            }
            else if(ascii == 8)
            {
                if (i > 0)
                {
                    i--;
                    firstPlayer[i] = '\0';

                    //memset(firstPlayer, '\0', sizeof(firstPlayer));
                    printf("\n\nLength:: %d\n\n", strlen(firstPlayer));
                    clearMyDevice();
                    printText(330, 150, firstPlayer);
                    playerNameShow();
                }
            }
            else
            {
                clearMyDevice();
                firstPlayer[i++] = ascii;       // store player name
                firstPlayer[i]=0;
                printText(330, 150, firstPlayer);       // player name show
                playerNameShow();
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
                if(j == 0)
                {
                    setcolor(RED);
                    printText(120, 100, "Please input second player name!");
                    setcolor(WHITE);
                    continue;
                }
                break;
            }
            else if(ascii == 8)
            {
                if (j > 0)
                {
                    j--;
                    secondPlayer[j] = '\0';
                    clearMyDevice();
                    printText(330, 150, firstPlayer);
                    printText(330, 185, secondPlayer);
                    playerNameShow();
                }
            }
            else
            {
                // second player name
                clearMyDevice();
                secondPlayer[j++] = ascii;
                secondPlayer[j]=0;
                printText(330, 150, firstPlayer);
                printText(330, 185, secondPlayer);
                playerNameShow();
            }
        }
    }
}

//main board
void boardSystem(int x, int y, char *a[ROW][COL], char firstPlayer[], char secondPlayer[], int i, int j)
{

//while(!kbhit())
    while(1)
    {
        // board show
        clearMyDevice();
        board(x, y, a, firstPlayer, secondPlayer);  // board show
        printf("\n\n\nCheck \n\n");
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
        int result = boardXYcoordinate(mouseX, mouseY);         // return mouse xy coordinate

        if(result != -1)
        {
            int row = result / ROW;  // row position
            int col = result % COL;  // col position

            if(a[row][col] == " ")      //check row & col empty
            {
                printf("\n\nArray value:: %c\n\n", a[row][col]);
                if(currentPlayer == 1)
                {
                    a[row][col] = "X";
                }
                else
                {
                    a[row][col] = "O";
                }

                int gameResult;

                gameResult = gameWin(a, currentPlayer);

                if( gameResult == 1)
                {
                    clearMyDevice();
                    board(x, y, a, firstPlayer, secondPlayer);  // board show
                    Sleep(1000);
                    finalMenu(firstPlayer, secondPlayer, gameResult);
                    finalMenuMouseclickEvent(x, y, a, firstPlayer, secondPlayer, i, j);
                }

                gameResult = gameDraw(a);
                if(gameResult == 1)
                {
                    clearMyDevice();
                    board(x, y, a, firstPlayer, secondPlayer);  // board show
                    Sleep(1000);
                    finalMenu(firstPlayer, secondPlayer, gameResult+1);
                    finalMenuMouseclickEvent(x, y, a, firstPlayer, secondPlayer, i, j);
                    getch();
                }
                currentPlayer = 3-currentPlayer;       // current player first 1 then 2
            }
        }
        clearmouseclick(WM_LBUTTONDOWN);            // mouse clear event
    }
}

// board drawing func
void board(int x, int y, char *board[ROW][COL], char nameFP[], char nameSP[])
{
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);

    setcolor(LIGHTBLUE);
    printText(280,30,"TIC");
    setcolor(LIGHTRED);
    printText(330,30,"TAC");
    setcolor(LIGHTMAGENTA);
    printText(390,30,"TOE");

    line(280,50, 440, 50);
    setcolor(WHITE);

    printText(210, 70, nameFP);
    setcolor(LIGHTMAGENTA);
    printText(340, 70, "vs");
    setcolor(WHITE);
    printText(415, 70, nameSP);
    setcolor(LIGHTMAGENTA);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            //setfillstyle(SOLID_FILL, RED);
            rectangle(x, y, x + 70, y + 70);            // board create
            setcolor(WHITE);
            printText(x + 15, y + 15, board[i][j]);
            setcolor(LIGHTMAGENTA);
            x += 70;
        }
        x = 210;
        y = y + 70;
    }
    //  rectangle(150, 30, 200, 150);
    //currentTime();
}

//current time show func
void currentTime()
{
    while (1)
    {
        // clearMyDevice();
        time_t cTime;
        struct tm *localTime;
        cTime = time(NULL);
        localTime = localtime(&cTime);
        char timestr[10],AM[]="AM",PM[]="PM";

        sprintf(timestr,"%02d:%02d:%02d",localTime->tm_hour,localTime->tm_min, localTime->tm_sec);
        printText(500, 50,timestr);
        delay(1000);

    }

}

// game draw
int gameDraw(char *a[ROW][COL])
{
    printf("Hello game draw");
    for(int i=0; i<ROW; i++)
    {
        for(int j=0; j<COL; j++)
        {
            if(*a[i][j] == ' ')
            {
                //&& *a[i][j] != "X" && *a[i][j] != "O"
                return 0;
            }
        }
    }
    return 1;
}

// game win check func
int gameWin(char *arr[ROW][COL], int player)
{
    printf("\n\nCurrent player:: %d\n\n", player);
    char value;
    if(player==1)
    {
        value = 'X';
        printf("\n\n Player One : %c", value);
    }
    else
    {
        value = 'O';
        printf("\n\n Player TWO : %c", value);
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
            printf("Row or COl");
            return 1;
        }

        if((*arr[0][0]==*ptr && *arr[1][1]==*ptr && *arr[2][2]==*ptr && *arr[3][3]==*ptr ) ||
                (*arr[0][3]==*ptr && *arr[1][2]==*ptr && *arr[2][1]==*ptr && *arr[3][0]==*ptr )
          )
        {
            printf("Digonal");
            return 1;
        }

    }

    return 0;
}

/*
char* playerName(int i, int ascii)
{
    int *ptr[10];

    ptr[i++] = ascii;
    firstPlayer[i]=0;

    return
}
*/



int lastMenuXYcordinate(int x, int y)
{
    printf("\n\nFirst row : %d , col : %d\n\n", x,y);

    if((x>=240 && x<=380) && (y>=230 && y<=265))
    {
        return 1;
    }
    if((x>=240 && x<=380) && (y>=270 && y<=300))
    {
        return 2;
    }
    if((x>=240 && x<=380) && (y>=305 && y<=335))
    {
        return 3;
    }
    return -1;
}

int controlPanalsXYcordinate(int x, int y)
{
    printf("\n\nFirst row : %d , col : %d\n\n", x,y);

    if((x>=260 && x<=395) && (y>=148 && y<=185))
    {
        return 1;
    }
    if((x>=260 && x<=395) && (y>=188 && y<=225))
    {
        return 2;
    }
    if((x>=260 && x<=395) && (y>=228 && y<=265))
    {
        return 3;
    }

    return -1;
}

// board click event func
int boardXYcoordinate(int x, int y)
{
    printf("\n\nX ::: %d \n\n, Y ::: %d \n", x, y);

    if ( (x > 210 && x <= 280) && (y > 150 && y<=220))
    {
        return 0;
    }
    if ( (x > 280 && x <= 350) && (y > 150 && y<=220))
    {
        return 1;
    }
    if ( (x > 350 && x <= 420) && (y > 150 && y<=220))
    {
        return 2;
    }
    if ( (x > 420 && x <= 490) && (y > 150 && y<=220))
    {
        return 3;
    }

    if ( (x > 210 && x <= 280) && (y > 220 && y<=290))
    {
        return 4;
    }
    if ( (x > 280 && x <= 350) && (y > 220 && y<=290))
    {
        return 5;
    }
    if ( (x > 350 && x <= 420) && (y > 220 && y<=290))
    {
        return 6;
    }
    if ( (x > 420 && x <= 490) && (y > 220 && y<=290))
    {
        return 7;
    }

    if ( (x > 210 && x <= 280) && (y > 290 && y<=360))
    {
        return 8;
    }
    if ( (x > 280 && x <= 350) && (y > 290 && y<=360))
    {
        return 9;
    }
    if ( (x > 350 && x <= 420) && (y > 290 && y<=360))
    {
        return 10;
    }
    if ( (x > 420 && x <= 490) && (y > 290 && y<=360))
    {
        return 11;
    }

    if ( (x > 210 && x <= 280) && (y > 360 && y<=430))
    {
        return 12;
    }
    if ( (x > 280 && x <= 350) && (y > 360 && y<=430))
    {
        return 13;
    }
    if ( (x > 350 && x <= 420) && (y > 360 && y<=430))
    {
        return 14;
    }
    if ( (x > 420 && x <= 490) && (y > 360 && y<=430))
    {
        return 15;
    }

    return -1;
}

// final menu show
void finalMenu(char firstPlayer[], char secondPlayer[], int result)
{
    clearMyDevice();
    char str[30];

    if(result == 1)
    {
        sprintf(str,"%s is won!", (currentPlayer == 1)? firstPlayer : secondPlayer);
    }
    else
    {
        sprintf(str,"Game is draw!");
    }

    drawButton(240, 230, 380, 265);
    printText(255, 235, "Play Again");

    drawButton(240, 270, 380, 300);
    printText(280, 275, "Menu");

    drawButton(240, 305, 380, 335);
    printText(290, 310, "Exit");

    settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
    for (int i = 0; i < 500; i += 5)
    {
        setcolor(COLOR(255 - i, i, 0));
        printText(180, 180, str);
        delay(20);
    }

    // printText(230, 180, str);

}

// final menu mouse event
void finalMenuMouseclickEvent(int x, int y, char *a[ROW][COL], char firstPlayer[], char secondPlayer[], int i, int j)
{
    while(1)
    {
        int menuClick = 0;
        int menuXX, menuYY;
        while (!menuClick)
        {
            if (ismouseclick(WM_LBUTTONDOWN))
            {
                getmouseclick(WM_LBUTTONDOWN, menuXX, menuYY);
                menuClick = 1;
            }
        }

        int r = lastMenuXYcordinate(menuXX, menuYY);
        if(r!=-1)
        {
            if(r==1)
            {
                for(int i=0; i<ROW; i++)
                {
                    for(int j=0; j<COL; j++)
                    {
                        a[i][j] = " ";              // clear memory
                    }
                }
                boardSystem(x, y, a, firstPlayer, secondPlayer, i, j);
            }
            else if(r==2)
            {
                mainSystem(x,y,i,j);
            }
            else
            {
                closegraph();
                exit(0);
            }
        }

        clearmouseclick(WM_LBUTTONDOWN);

    }
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
