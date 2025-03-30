#include <stdio.h>
#include <graphics.h>

// Function to draw a rectangle
void drawRectangle(int x1, int y1, int x2, int y2) {
    line(x1, y1, x2, y1);  // Top side
    line(x2, y1, x2, y2);  // Right side
    line(x2, y2, x1, y2);  // Bottom side
    line(x1, y2, x1, y1);  // Left side
}

// Function for 8-connected Boundary Fill Algorithm
void boundaryFill8(int x, int y, int fillColor, int boundaryColor) {
    if (getpixel(x, y) != boundaryColor && getpixel(x, y) != fillColor) {
        putpixel(x, y, fillColor);

        // Recursive calls to fill adjacent pixels (8 directions)
        boundaryFill8(x + 1, y, fillColor, boundaryColor);     // Right
        boundaryFill8(x - 1, y, fillColor, boundaryColor);     // Left
        boundaryFill8(x, y + 1, fillColor, boundaryColor);     // Down
        boundaryFill8(x, y - 1, fillColor, boundaryColor);     // Up
        boundaryFill8(x + 1, y + 1, fillColor, boundaryColor); // Bottom-right
        boundaryFill8(x - 1, y - 1, fillColor, boundaryColor); // Top-left
        boundaryFill8(x - 1, y + 1, fillColor, boundaryColor); // Bottom-left
        boundaryFill8(x + 1, y - 1, fillColor, boundaryColor); // Top-right
    }
}

int main() {
    // Take user input for the rectangle coordinates first
    int x1, y1, x2, y2;
    printf("Enter the coordinates of the top-left corner of the rectangle (x1 y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the coordinates of the bottom-right corner of the rectangle (x2 y2): ");
    scanf("%d %d", &x2, &y2);

    // Take user input for fill and boundary colors
    int fillColor, boundaryColor;
    printf("Enter the fill color (choose from 0-15): ");
    scanf("%d", &fillColor);
    printf("Enter the boundary color (choose from 0-15): ");
    scanf("%d", &boundaryColor);

    // Initialize the graphics window after taking input
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Draw the rectangle
    drawRectangle(x1, y1, x2, y2);

    // Use the center of the rectangle as the seed point for flood fill
    boundaryFill8((x1 + x2) / 2, (y1 + y2) / 2, fillColor, boundaryColor);

    getch();
    closegraph();
    return 0;
}

