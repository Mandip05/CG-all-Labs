#include<stdio.h>
#include<graphics.h>
#include<conio.h>

void WindowToViewport(float xw, float yw, float xw_min, float xw_max, float yw_min, float yw_max,
                      float xv_min, float xv_max, float yv_min, float yv_max, int *xv, int *yv) {
    *xv = (int)((xw - xw_min) * (xv_max - xv_min) / (xw_max - xw_min) + xv_min);
    *yv = (int)((yw - yw_min) * (yv_max - yv_min) / (yw_max - yw_min) + yv_min);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, ""); // Specify the path for older compilers

    float xw_min = 10, xw_max = 100;
    float yw_min = 10, yw_max = 100;
    float xv_min = 200, xv_max = 400;
    float yv_min = 200, yv_max = 400;

    int xv1, yv1, xv2, yv2;
    float xw1 = 10, yw1 = 30;
    float xw2 = 80, yw2 = 90;

    // Draw Window
    rectangle((int)xw_min, (int)yw_min, (int)xw_max, (int)yw_max);
    outtextxy((int)xw_min - 10, (int)yw_min - 10, "Window");

    // Convert window coordinates to viewport
    WindowToViewport(xw1, yw1, xw_min, xw_max, yw_min, yw_max, xv_min, xv_max, yv_min, yv_max, &xv1, &yv1);
    WindowToViewport(xw2, yw2, xw_min, xw_max, yw_min, yw_max, xv_min, xv_max, yv_min, yv_max, &xv2, &yv2);

    // Draw window line
    line((int)xw1, (int)yw1, (int)xw2, (int)yw2);

    // Draw Viewport
    rectangle((int)xv_min, (int)yv_min, (int)xv_max, (int)yv_max);
    outtextxy((int)xv_min - 10, (int)yv_min - 10, "Viewport");

    // Draw mapped line in viewport
    line(xv1, yv1, xv2, yv2);

    getch();
    closegraph();
    return 0;
}

