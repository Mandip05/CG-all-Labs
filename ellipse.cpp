#include <stdio.h>
#include <graphics.h>

void drawEllipse(int xc, int yc, int rx, int ry) {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    float px, py, p1, p2, x, y;

    x = 0;
    y = ry;
    p1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
    px = 2 * ry * ry * x;
    py = 2 * rx * rx * y;

    while (px < py) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        if (p1 < 0) {
            x++;
            px = px + (2 * ry * ry);
            p1 = p1 + px + (ry * ry);
        } else {
            x++;
            y--;
            px = px + (2 * ry * ry);
            py = py - (2 * rx * rx);
            p1 = p1 + px - py + (ry * ry);
        }
    }

    p2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) + ((rx * rx) * ((y - 1) * (y - 1))) - (rx * rx * ry * ry);

    while (y >= 0) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        if (p2 > 0) {
            y--;
            py = py - (2 * rx * rx);
            p2 = p2 + (rx * rx) - py;
        } else {
            y--;
            x++;
            px = px + (2 * ry * ry);
            py = py - (2 * rx * rx);
            p2 = p2 + px - py + (rx * rx);
        }
    }

    getch();
    closegraph();
}

int main() {
    int xc, yc, rx, ry;

    printf("Enter the coordinates of the center (xc, yc): ");
    scanf("%d %d", &xc, &yc);

    printf("Enter the x-radius (rx): ");
    scanf("%d", &rx);

    printf("Enter the y-radius (ry): ");
    scanf("%d", &ry);

    drawEllipse(xc, yc, rx, ry);

    return 0;
}

