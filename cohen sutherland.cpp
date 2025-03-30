#include <stdio.h>
#include <graphics.h>

#define INSIDE 0    // 0000
#define LEFT 1      // 0001
#define RIGHT 2     // 0010
#define BOTTOM 4    // 0100
#define TOP 8       // 1000

float x_min, y_min, x_max, y_max; // Clipping window coordinates

int computeCode(float x, float y) {
    int code = INSIDE;

    if (x < x_min)
        code |= LEFT;
    else if (x > x_max)
        code |= RIGHT;
    if (y < y_min)
        code |= BOTTOM;
    else if (y > y_max)
        code |= TOP;

    return code;
}

void cohenSutherlandClip(float x1, float y1, float x2, float y2) {
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
    int accept = 0;

    while (1) {
        if ((code1 == 0) && (code2 == 0)) {
            accept = 1;
            break;
        } else if (code1 & code2) {
            break;
        } else {
            int code_out;
            float x, y;

            if (code1 != 0)
                code_out = code1;
            else
                code_out = code2;

            if (code_out & TOP) {
                x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
                y = y_max;
            } else if (code_out & BOTTOM) {
                x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
                y = y_min;
            } else if (code_out & RIGHT) {
                y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
                x = x_max;
            } else if (code_out & LEFT) {
                y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
                x = x_min;
            }

            if (code_out == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }

    if (accept) {
        setcolor(WHITE);
        line(x1, y1, x2, y2);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    printf("Enter the coordinates of the clipping window (x_min, y_min, x_max, y_max): ");
    scanf("%f %f %f %f", &x_min, &y_min, &x_max, &y_max);

    rectangle(x_min, y_min, x_max, y_max);

    float x1, y1, x2, y2;
    printf("Enter the endpoints of the line (x1, y1, x2, y2): ");
    scanf("%f %f %f %f", &x1, &y1, &x2, &y2);

    setcolor(WHITE);
    line(x1, y1, x2, y2);

    getch();
    cleardevice();

    rectangle(x_min, y_min, x_max, y_max);
    cohenSutherlandClip(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}

