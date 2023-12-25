#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <time.h>
#define ROW 4
#define COL 4
#define X 180
#define Y 150

void drawBoard(char *a[ROW][COL]); // drawing board normal ..!
void board(char *board[ROW][COL], char nameF[], char nameS[]); // drawing board graphics ..!
int gameWin(char *arr[ROW][COL], int player);  // game win logic ..!
void currentTime();  // current time display ..!
void homePage(); // first home page ..!
int boardXYcoordinate(int x, int y);  // board click cursor ..!
int controlPanalsXYcordinate(int x, int y);     // control click cursor ..!
int controlPanals();   // control panals ..!
void inputPlayerName(char firstPlayer[], char secondPlayer[], char *a[ROW][COL],int m,int n);    // player input ..!
void mouseEvent();
int lastMenuXYcordinate(int x, int y);  // main menu mouse click event ..!
void mainSystem(int i, int j);    // main system start ..!
void boardSystem(char *a[ROW][COL], char firstPlayer[], char secondPlayer[], int i, int j);   // main baord control ..!
int gameDraw(char *a[ROW][COL]);        // game draw ..!
void menuPage(); // menu ..!
void playerNameShow(); // player name show ..!
void finalMenu(char firstPlayer[], char secondPlayer[], int result); // last menu page ..!
void finalMenuMouseclickEvent(char *a[ROW][COL], char firstPlayer[], char secondPlayer[], int i, int j);
void inputPlayerNameShow(char firstPlayer[], char secondPlayer[]);  // input player name show ..!
int playButton(); // play button mouse click event ..!
int playButtonXYcordinate(int x,int y);
int backButton();   // back button mouse click event ..!
int backButtonXYcordinate(int x,int y);

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
    int gd = DETECT, gm, x = X, y = Y, i=0, j=0;

    initgraph(&gd, &gm, "");
    setbkcolor(COLOR(10,6,33));
    clearMyDevice();

    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);

    printText(X-20, Y+50, "Made with");
    for (int i = 0; i < 400; i += 5)
    {
        setcolor(COLOR(255 - i, i, 0));
        printText(X+150, Y+90, "Believers.");
        delay(50);
    }

    clearMyDevice();
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    printText(X-10, Y+220, "LOADING PLEASE WAIT..."); // loading page ..!

    delay(1000);        // 1 sec sleep ..!

    homePage();         // welcome page ..!

    while(getch() != 13);

    mainSystem(i,j);    // main menu ..!

    getch();
    closegraph();
    return 0;
}

// home page ..!
void homePage()
{
    clearMyDevice();
    settextstyle(EUROPEAN_FONT,HORIZ_DIR, 1.5);
    settextstyle(1,HORIZ_DIR,7);
    setcolor(LIGHTBLUE);
    printText(X-60,Y-60,"TIC");
    setcolor(LIGHTRED);
    printText(X,Y,"TAC");
    setcolor(LIGHTMAGENTA);
    printText(X+70,Y+60,"TOE");
    setcolor(WHITE);
    settextstyle(EUROPEAN_FONT,HORIZ_DIR, 1);
    settextstyle(1,HORIZ_DIR,1);
    printText(X+20, Y+150, "Please click ");
    setcolor(RED);
    printText(X+167, Y+150, "Enter ");
    setcolor(WHITE);
    printText(X+238, Y+150, "button.");
}

// main system ..!
void mainSystem(int i, int j)
{
    char *a[ROW][COL] = {" ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "};
    char firstPlayer[20], secondPlayer[20];
    //char* firstPlayer = (char)*malloc(10);
    //char* secondPlayer = (char)*malloc(10);
    int x = X, y = Y;
    while(1)
    {
        menuPage();    // menu ..!
        int r = controlPanals();

        if(r!=-1)
        {
            if(r==1)        // start game ..!
            {
                inputPlayerName(firstPlayer, secondPlayer,a,i,j);   // input player name ..!
            }

            else if(r==2)   // control game..!
            {
                clearMyDevice();

                settextstyle(EUROPEAN_FONT,HORIZ_DIR, 2.3);
                printText(200, 50, "How to Play Game!");
                line(200,70,440,70);
                settextstyle(EUROPEAN_FONT,HORIZ_DIR,1);
                outtextxy(15,78,"1.In This Game one player plays Against Another player.");
                outtextxy(15,108,"2.The Game is Played in a 4 X 4 Board(GRID).");
                outtextxy(15,138,"3.Each Game,The Players are Assigned Symbols To play");
                outtextxy(30,168,"('X' or 'O').");
                outtextxy(15,198,"4.Any Player Who Have 4 Same Symbols Together in any");
                outtextxy(30,228,"Direction(Diagonal,Horizontal,Vertical)Wins the Game.");
                outtextxy(15,258,"5.If The Board Gets Full With Symbols then the Game ");
                outtextxy(30,288,"is Draw.");
                settextstyle(EUROPEAN_FONT,HORIZ_DIR, 2.3);

                drawButton(270,325,350,358);
                printText(280, 330, "Back");
                while(1)
                {
                    int result= backButton();
                    if(result==1)
                    {
                        cleardevice();
                        mainSystem(i, j);
                        break;
                    }
                }
                getch();

            }
            else        // exit game..!
            {
                closegraph();
                exit(0);
            }
        }
    }
}

// menuPage ..!
void menuPage()
{
    settextstyle(EUROPEAN_FONT,HORIZ_DIR, 1);
    setcolor(WHITE);
    clearMyDevice();

    drawButton(X+80, Y-2, X+215, Y+35);
    printText(X+90, Y+5, "Start Game");

    drawButton(X+80, Y+38, X+215, Y+75);
    printText(X+105, Y+45, "Control");

    drawButton(X+80, Y+78, X+215, Y+115);
    printText(X+120, Y+85, "Exit");
}

// control panal func ..!
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

// input player name func ..!
void inputPlayerName(char firstPlayer[], char secondPlayer[],char *a[ROW][COL],int m,int n)
{
    clearMyDevice();
    playerNameShow();
    int checkPlayButton = 0;
    int i=0, j =0;

    while(1)
    {
        /*
        if(checkPlayButton == 0)
        {
            int result=playButton();
            if(result == 1)
            {
                setcolor(RED);
                printText(120, 100, "Please input name & enter!");
                setcolor(WHITE);
            }
        }
        */
        if(kbhit())
        {
            char ascii = getch();

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
                    inputPlayerNameShow(firstPlayer, secondPlayer);
                }
            }
            else
            {
                clearMyDevice();
                firstPlayer[i++] = ascii;       // store player name ..!
                firstPlayer[i]='\0';
                secondPlayer[0]='\0';
                inputPlayerNameShow(firstPlayer, secondPlayer);
            }
        }
    }

    while(1)
    {
        if(kbhit())
        {
            char ascii = getch();
            if(ascii==13)
            {
                if(j == 0)
                {
                    setcolor(RED);
                    printText(120, 100, "Please input second player name!");
                    setcolor(WHITE);
                    continue;
                }
                while(1)
                {
                    int result=playButton();
                    printf("check login button %d",result);
                    if(result==1)
                    {
                        boardSystem(a, firstPlayer, secondPlayer, m, n);
                        printf("check play system");
                    }
                }
            }
            else if(ascii == 8)
            {
                if (j > 0)
                {
                    j--;
                    secondPlayer[j] = '\0';
                    clearMyDevice();
                    inputPlayerNameShow(firstPlayer, secondPlayer);
                }
            }
            else
            {
                clearMyDevice();
                secondPlayer[j++] = ascii;       // store player name ..!
                secondPlayer[j]='\0';
                inputPlayerNameShow(firstPlayer, secondPlayer);
            }
        }
    }
}

void inputPlayerNameShow(char firstPlayer[], char secondPlayer[])
{
    printText(X+150, Y, firstPlayer);
    printText(X+150, Y+35, secondPlayer);
    playerNameShow();
}

/*
void warningMsg(char str[])
{
    setcolor(RED);
    char str2[20];
    sprintf(str2, "Please input %s name!", str);
    printText(120, 100, str2);
    setcolor(WHITE);
}
*/

// player name display ..!
void playerNameShow()
{
    printText(X-50, Y, "Player 1 name: ");
    printText(X-50, Y+35, "Player 2 name: ");
    drawButton(X+85, Y+95, X+155, Y+130);
    printText(X+98, Y+102, "Play");
}

//main board ..!
void boardSystem(char *a[ROW][COL], char firstPlayer[], char secondPlayer[], int i, int j)
{
    while(1)
    {
        clearMyDevice();
        board(a, firstPlayer, secondPlayer);  // board show ..!
        printf("\n\n\nCheck \n\n");

        int mouseClick = 0;
        int mouseX, mouseY;
        while(!mouseClick)       // mouse click event ..!
        {
            if(ismouseclick(WM_LBUTTONDOWN))
            {
                getmouseclick(WM_LBUTTONDOWN, mouseX, mouseY);
                mouseClick = 1;
            }
        }

        // board control in mouse click ..!
        int result = boardXYcoordinate(mouseX, mouseY);         // return mouse xy coordinate ..!

        if(result != -1)
        {
            int row = result / ROW;
            int col = result % COL;

            if(a[row][col] == " ")      //check row & col empty ..!
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
                    board(a, firstPlayer, secondPlayer);  // board show ..!
                    Sleep(1000);
                    finalMenu(firstPlayer, secondPlayer, gameResult);
                    finalMenuMouseclickEvent(a, firstPlayer, secondPlayer, i, j);
                }

                gameResult = gameDraw(a);
                if(gameResult == 1)
                {
                    clearMyDevice();
                    board(a, firstPlayer, secondPlayer);  // board show ..!
                    Sleep(1000);
                    finalMenu(firstPlayer, secondPlayer, gameResult+1);
                    finalMenuMouseclickEvent(a, firstPlayer, secondPlayer, i, j);
                    getch();
                }
                currentPlayer = 3-currentPlayer;       // current player first 1 then 2 ..!
            }
        }
        clearmouseclick(WM_LBUTTONDOWN);
    }
}

// board drawing func ..!
void board(char *board[ROW][COL], char nameFP[], char nameSP[])
{
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);

    setcolor(LIGHTBLUE);
    printText(X+60,Y-120,"TIC");
    setcolor(LIGHTRED);
    printText(X+110,Y-120,"TAC");
    setcolor(LIGHTMAGENTA);
    printText(X+170,Y-120,"TOE");

    line(X+60,Y-100, X+220, Y-100);
    setcolor(WHITE);

    printText(X+10, Y-70, nameFP);
    setcolor(LIGHTMAGENTA);
    printText(X+130, Y-70, "vs");
    setcolor(WHITE);
    printText(X+210, Y-70, nameSP);
    setcolor(LIGHTMAGENTA);

    int x = X, y = Y, rectWidth = 65, rectHeight = 65;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            rectangle(x, y, x + rectWidth, y + rectHeight);
            setcolor(WHITE);
            printText(x + 28, y + 28, board[i][j]);
            setcolor(LIGHTMAGENTA);
            x += rectWidth + 5;
        }
        x = X;
        y = y + rectHeight + 5;
    }
    //  rectangle(150, 30, 200, 150);
    //currentTime();
}

//current time show func ..!
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

// game draw check ..!
int gameDraw(char *a[ROW][COL])
{
    printf("Hello game draw");
    for(int i=0; i<ROW; i++)
    {
        for(int j=0; j<COL; j++)
        {
            if(*a[i][j] == ' ')
            {
                return 0;
            }
        }
    }
    return 1;
}

// game win check ..!
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

// board click event func ..!
int boardXYcoordinate(int x, int y)
{
    printf("\n\nX ::: %d \n\n, Y ::: %d \n", x, y);

    if ( (x > 179 && x <= 244) && (y > 140 && y<=205))
    {
        return 0;
    }
    if ( (x > 249 && x <= 314) && (y > 140 && y<=205))
    {
        return 1;
    }
    if ( (x > 319 && x <= 384) && (y > 140 && y<=205))
    {
        return 2;
    }
    if ( (x > 389 && x <= 454) && (y > 140 && y<=205))
    {
        return 3;
    }

    if ( (x > 179 && x <= 244) && (y > 210 && y<=275))
    {
        return 4;
    }

    if ( (x > 249 && x <= 314) && (y > 210 && y<=275))
    {
        return 5;
    }
    if ( (x > 319 && x <= 384) && (y > 210 && y<=275))
    {
        return 6;
    }
    if ( (x > 389 && x <= 454) && (y > 210 && y<=275))
    {
        return 7;
    }

    if ( (x > 179 && x <= 244) && (y > 280 && y<=345))
    {
        return 8;
    }
    if ( (x > 249 && x <= 314) && (y > 280 && y<=345))
    {
        return 9;
    }
    if ( (x > 319 && x <= 384) && (y > 280 && y<=345))
    {
        return 10;
    }
    if ( (x > 389 && x <= 454) && (y > 280 && y<=345))
    {
        return 11;
    }

    if ( (x > 179 && x <= 244) && (y > 350 && y<=415))
    {
        return 12;
    }
    if ( (x > 249 && x <= 314) && (y > 350 && y<=415))
    {
        return 13;
    }
    if ( (x > 319 && x <= 384) && (y > 350 && y<=415))
    {
        return 14;
    }
    if ( (x > 389 && x <= 454) && (y > 350 && y<=415))
    {
        return 15;
    }

    return -1;
}

// .. final menu show ..!
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

    drawButton(X+60, Y+80, X+200, Y+115);
    printText(X+75, Y+85, "Play Again");

    drawButton(X+60, Y+120, X+200, Y+150);
    printText(X+100, Y+125, "Menu");

    drawButton(X+60, Y+155, X+200, Y+185);
    printText(X+110, Y+160, "Exit");

    settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
    for (int i = 0; i < 500; i += 5)
    {
        setcolor(COLOR(255 - i, i, 0));
        printText(X, Y+30, str);
        delay(20);
    }

}

// final menu mouse event ..!
void finalMenuMouseclickEvent(char *a[ROW][COL], char firstPlayer[], char secondPlayer[], int i, int j)
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
                        a[i][j] = " ";              // clear memory ..!
                    }
                }
                boardSystem(a, firstPlayer, secondPlayer, i, j);
            }
            else if(r==2)
            {
                mainSystem(i,j);
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

// play button ..!
int playButton()
{
    printf("\n\n\nCheck \n\n");

    int playClick = 0;
    int playX, playY;
    while(!playClick)
    {
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN, playX, playY);
            playClick = 1;
        }
    }
    int r=playButtonXYcordinate(playX,playY);

    clearmouseclick(WM_LBUTTONDOWN);
    return r;
}

int playButtonXYcordinate(int x,int y)
{
    printf("playbutton x,y coordinate:%d %d",x,y);
    if((x>=265 && x<=335) && (y>=245 && y<=282))
    {
        return 1;
    }
    return -1;
}

int backButton()

{
    int buttonClick = 0;
    int buttonX, buttonY;
    while (!buttonClick)
    {
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN, buttonX, buttonY);
            buttonClick = 1;
            printf("mouse click: %d \n", buttonClick);
        }
    }
    int r=backButtonXYcordinate(buttonX,buttonY);
    printf("\n Option selected first :: %d \n\n", r);
    clearmouseclick(WM_LBUTTONDOWN);
    return r;
}

int backButtonXYcordinate(int x,int y)
{
    printf("backbutton x,y coordinate:%d %d",x,y);
    if(x>=269 && x<=350 && y>=326 && y<=356)
    {
        return 1;
    }
    return -1;
}

// mouse event func ..!
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
