#include <stdio.h>
#include <graphics.h>

// Function for flood fill algorithm (4-connected)
void floodFill4(int x, int y, int fillColor, int boundaryColor) {
    if (getpixel(x, y) != boundaryColor && getpixel(x, y) != fillColor) {
        putpixel(x, y, fillColor);
        floodFill4(x + 1, y, fillColor, boundaryColor);  // Right
        floodFill4(x - 1, y, fillColor, boundaryColor);  // Left
        floodFill4(x, y + 1, fillColor, boundaryColor);  // Down
        floodFill4(x, y - 1, fillColor, boundaryColor);  // Up
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "NULL");

    // Modified polygon coordinates
    int x1 = 200, y1 = 100;
    int x2 = 100, y2 = 200;
    int x3 = 150, y3 = 250;
    int x4 = 50, y4 = 200;
    int x5 = 50, y5 = 100;
    int x6 = 150, y6 = 50;

    // Draw the polygon (closed shape)
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x4, y4);
    line(x4, y4, x5, y5);
    line(x5, y5, x6, y6);
    line(x6, y6, x1, y1);  // Close the polygon

    // Set fill color and boundary color
    int fillColor = RED;
    int boundaryColor = WHITE;

    // Seed point inside the polygon (average of the coordinates)
    floodFill4((x1 + x2 + x3 + x4 + x5 + x6) / 6, (y1 + y2 + y3 + y4 + y5 + y6) / 6, fillColor, boundaryColor);

    getch();
    closegraph();
    return 0;
}

