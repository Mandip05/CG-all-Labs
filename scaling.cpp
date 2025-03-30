#include <graphics.h>
#include <stdio.h>

void drawPolygon(int x[], int y[], int n, int color, char label[]) {
    setcolor(color);
    for (int i = 0; i < n - 1; i++) {
        line(x[i], y[i], x[i + 1], y[i + 1]);
    }
    line(x[n - 1], y[n - 1], x[0], y[0]);
    outtextxy(x[0], y[0] - 10, label);
}

void scale2D(int x[], int y[], int n, float sx, float sy) {
    for (int i = 0; i < n; i++) {
        x[i] = x[i] * sx;
        y[i] = y[i] * sy;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x[] = {100, 200, 200, 100};
    int y[] = {100, 100, 200, 200};
    int n = 4;
    int x_scaled[4], y_scaled[4];
    float sx, sy;

    printf("Enter scaling factors (sx sy): ");
    scanf("%f %f", &sx, &sy);

    for (int i = 0; i < n; i++) {
        x_scaled[i] = x[i];
        y_scaled[i] = y[i];
    }

    drawPolygon(x, y, n, WHITE, (char *)"Original");
    scale2D(x_scaled, y_scaled, n, sx, sy);
    drawPolygon(x_scaled, y_scaled, n, WHITE, (char *)"Scaled");

    getch();
    closegraph();
    return 0;
}

