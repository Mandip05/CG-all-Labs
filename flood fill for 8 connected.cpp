#include <stdio.h>
#include <graphics.h>

// 8-connected flood fill algorithm
void floodFill8(int x, int y, int fillColor, int boundaryColor) {
    if (getpixel(x, y) != boundaryColor && getpixel(x, y) != fillColor) {
        putpixel(x, y, fillColor);  // Fill the current pixel

        // Recursively call for 8 directions (4 cardinal + 4 diagonal directions)
        floodFill8(x + 1, y, fillColor, boundaryColor);  // Right
        floodFill8(x - 1, y, fillColor, boundaryColor);  // Left
        floodFill8(x, y + 1, fillColor, boundaryColor);  // Down
        floodFill8(x, y - 1, fillColor, boundaryColor);  // Up

        floodFill8(x + 1, y + 1, fillColor, boundaryColor);  // Bottom-right diagonal
        floodFill8(x - 1, y - 1, fillColor, boundaryColor);  // Top-left diagonal
        floodFill8(x + 1, y - 1, fillColor, boundaryColor);  // Top-right diagonal
        floodFill8(x - 1, y + 1, fillColor, boundaryColor);  // Bottom-left diagonal
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "NULL");

    // Define polygon vertices
    int x1 = 50, y1 = 100;
    int x2 = 100, y2 = 200;
    int x3 = 200, y3 = 100;
    int x4 = 100, y4 = 200;

    // Draw the polygon (rectangle in this case)
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x4, y4);
    line(x4, y4, x1, y1);  // Close the polygon

    // Set fill and boundary colors
    int fillColor = YELLOW;
    int boundaryColor = WHITE;

    // Seed point inside the polygon (average of coordinates)
    floodFill8((x1 + x2 + x3 + x4) / 4, (y1 + y2 + y3 + y4) / 4, fillColor, boundaryColor);

    getch();
    closegraph();
    return 0;
}

