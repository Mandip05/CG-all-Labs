#include <graphics.h>
#include <stdio.h>

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int color, char *label) {  // Changed to const char*
    setcolor(color);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
    outtextxy(x1, y1 - 10, label);
}

int main() {
    int gd = DETECT, gm;
    int x1 = 200, y1 = 100;
    int x2 = 150, y2 = 200;
    int x3 = 250, y3 = 200;
    int Tx, Ty;

    // Get translation values from the user
    printf("Enter translation vector (Tx Ty): ");
    scanf("%d %d", &Tx, &Ty);

    // Initialize graphics mode
    initgraph(&gd, &gm, "");

    cleardevice();

    // Draw original triangle (White)
    drawTriangle(x1, y1, x2, y2, x3, y3, WHITE, "Original");

    // Apply translation
    x1 += Tx; y1 += Ty;
    x2 += Tx; y2 += Ty;
    x3 += Tx; y3 += Ty;

    // Draw translated triangle (Red)
    drawTriangle(x1, y1, x2, y2, x3, y3, WHITE, "Translated");

    getch(); // Wait for user input
    closegraph(); // Close graphics mode

    return 0;
}

