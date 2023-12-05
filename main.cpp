#include <stdio.h>
#include <stdlib.h>
#include<graphics.h>

void board(int a[4][4]);

int main()
{

    int gd = DETECT, gm, x = 210, y = 150, i, j;


    char *a[4][4] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16"};


    //char *a[4][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

    initgraph(&gd, &gm, "");
    setcolor(WHITE);

    for(i=0; i<4; i++)
    {
        for (j=0; j<4; j++)
        {
            setfillstyle(SOLID_FILL, RED);

            rectangle(x,y,x+70,y+70);
            //settextstyle(0,0,2);
            // outtextxy(150, 100, a[i][j]);
         //   outtextxy(x + 15, y + 15, a[i][j]);
            // sprintf(*a, "%c", *a[i]);

            //  floodfill(x+1, y+1, BLACK);
            x += 70;
            // delay(30);
        }
        //outtextxy(150, 10, a[i][j]);
        x = 210;
        y = y+70;
        //  delay(30);
    }


    //  board(a);
    getch();
    return 0;
}

void board(int a[4][4])
{

    printf("__________________________\n");
    printf("|%d   | %d    | %d    | %d   |\n", a[0][0], a[0][1], a[0][2], a[0][3]);
    printf("|    |      |      |     |\n");
    printf("|____|______|______|_____|\n");
    printf("|%d   | %d    | %d    | %d   |\n", a[1][0], a[1][1], a[1][2], a[1][3]);
    printf("|    |      |      |     |\n");
    printf("|____|______|______|_____|\n");
    printf("|%d   | %d   | %d   | %d  |\n", a[2][0], a[2][1], a[2][2], a[2][3]);
    printf("|    |      |      |     |\n");
    printf("|____|______|______|_____|\n");
    printf("|%d  | %d   | %d   | %d  |\n", a[3][0], a[3][1], a[3][2], a[3][3]);
    printf("|    |      |      |     |\n");
    printf("|____|______|______|_____|\n");
}
