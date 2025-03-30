#include <graphics.h>
#include <stdio.h>

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int color, char *label) {
    setcolor(color);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
    outtextxy(x1 - 50, y1 - 10, label);
}

int main() {
    int gd = DETECT, gm;
    int x1 = 300, y1 = 100;
    int x2 = 150, y2 = 200;
    int x3 = 250, y3 = 300;
    int reflectionX;

    printf("Enter the x-coordinate for reflection: ");
    scanf("%d", &reflectionX);

    initgraph(&gd, &gm, "");

    cleardevice();

    drawTriangle(x1, y1, x2, y2, x3, y3, WHITE, "Original");

    // Apply reflection along the user-defined x-axis
    x1 = 2 * reflectionX - x1;
    x2 = 2 * reflectionX - x2;
    x3 = 2 * reflectionX - x3;

    drawTriangle(x1, y1, x2, y2, x3, y3, WHITE, "Reflected");

    getch();
    closegraph();

    return 0;
}

