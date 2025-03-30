#include <stdio.h>
#include <graphics.h>


void drawRectangle(int x1, int y1, int x2, int y2) {
    line(x1, y1, x2, y1);  // Top side
    line(x2, y1, x2, y2);  // Right side
    line(x2, y2, x1, y2);  // Bottom side
    line(x1, y2, x1, y1);  // Left side
}

void boundaryFill4(int x, int y, int fillColor, int boundaryColor) {
    if (getpixel(x, y) != boundaryColor && getpixel(x, y) != fillColor) {
        putpixel(x, y, fillColor);

        boundaryFill4(x + 1, y, fillColor, boundaryColor);     // Right
        boundaryFill4(x - 1, y, fillColor, boundaryColor);     // Left
        boundaryFill4(x, y + 1, fillColor, boundaryColor);     // Down
        boundaryFill4(x, y - 1, fillColor, boundaryColor);     // Up
    }
}

int main() {
    int x1, y1, x2, y2;
    printf("Enter the coordinates of the top-left corner of the rectangle (x1 y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the coordinates of the bottom-right corner of the rectangle (x2 y2): ");
    scanf("%d %d", &x2, &y2);

    int fillColor, boundaryColor;
    printf("Enter the fill color (choose from 0-15): ");
    scanf("%d", &fillColor);
    printf("Enter the boundary color (choose from 0-15): ");
    scanf("%d", &boundaryColor);

    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    drawRectangle(x1, y1, x2, y2);

    boundaryFill4((x1 + x2) / 2, (y1 + y2) / 2, fillColor, boundaryColor);

    getch();
    closegraph();
    return 0;
}

