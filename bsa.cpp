 #include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void bresenhamLine(int x1, int y1, int x2, int y2) {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL); // Use NULL for the path in Dev-C++

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int p;
    int twoDy = 2 * dy;
    int twoDyMinusDx = 2 * (dy - dx);
    int x, y, xEnd;
    int stepY = (y2 > y1) ? 1 : -1;  // Determine step for y-direction based on slope.

    if (dx > dy) {  // Slope between 0 and 1
        p = 2 * dy - dx;
        if (x1 > x2) {
            x = x2;
            y = y2;
            xEnd = x1;
        } else {
            x = x1;
            y = y1;
            xEnd = x2;
        }
        putpixel(x, y, WHITE);
        while (x < xEnd) {
            x++;
            if (p < 0) {
                p += twoDy;
            } else {
                y += stepY;
                p += twoDyMinusDx;
            }
            putpixel(x, y, WHITE);
        }
    } else {  // Slope greater than 1
        int twoDx = 2 * dx;
        int twoDxMinusDy = 2 * (dx - dy);
        p = 2 * dx - dy;

        if (y1 > y2) {
            x = x2;
            y = y2;
            xEnd = y1;
        } else {
            x = x1;
            y = y1;
            xEnd = y2;
        }
        putpixel(x, y, WHITE);
        while (y < xEnd) {
            y++;
            if (p < 0) {
                p += twoDx;
            } else {
                x += (x2 > x1) ? 1 : -1;
                p += twoDxMinusDy;
            }
            putpixel(x, y, WHITE);
        }
    }

    getch();
    closegraph();
}

int main() {
    int x1, y1, x2, y2;
    printf("Enter coordinates (x1, y1) and (x2, y2) for line drawing: \n");
    printf("x1: ");
    scanf("%d", &x1);
    printf("y1: ");
    scanf("%d", &y1);
    printf("x2: ");
    scanf("%d", &x2);
    printf("y2: ");
    scanf("%d", &y2);

    bresenhamLine(x1, y1, x2, y2);

    return 0;
}

