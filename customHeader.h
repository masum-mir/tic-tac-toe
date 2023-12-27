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