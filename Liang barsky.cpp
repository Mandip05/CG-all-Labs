#include <stdio.h>
#include <graphics.h>

float x_min, y_min, x_max, y_max; // Clipping window coordinates

void liangBarsky(float x1, float y1, float x2, float y2) {
    float dx = x2 - x1, dy = y2 - y1;
    float p[4], q[4];
    float t1 = 0, t2 = 1; // Parametric values

    p[0] = -dx; q[0] = x1 - x_min;  // Left edge
    p[1] = dx;  q[1] = x_max - x1;  // Right edge
    p[2] = -dy; q[2] = y1 - y_min;  // Bottom edge
    p[3] = dy;  q[3] = y_max - y1;  // Top edge

    for (int i = 0; i < 4; i++) {
        if (p[i] == 0) {  // Line is parallel to clipping edge
            if (q[i] < 0) return; // Outside boundary
        } else {
            float t = q[i] / p[i];
            if (p[i] < 0) { // Entering condition
                if (t > t1) t1 = t;
            } else { // Exiting condition
                if (t < t2) t2 = t;
            }
        }
    }

    if (t1 > t2) return; // Line completely outside

    // Compute new clipped coordinates
    float new_x1 = x1 + t1 * dx;
    float new_y1 = y1 + t1 * dy;
    float new_x2 = x1 + t2 * dx;
    float new_y2 = y1 + t2 * dy;

    setcolor(WHITE);
    line(new_x1, new_y1, new_x2, new_y2);
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
    liangBarsky(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}

