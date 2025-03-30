#include <stdio.h>
#include <graphics.h>
#include <conio.h>

int x1, x2, y1, y2, mx, my, depth;

void draw();
void trans();

int main() {
    int gd = DETECT, gm;
    
    // Initialize graphics mode
    initgraph(&gd, &gm, NULL);

    printf("Enter top-left coordinates (x1, y1): ");
    scanf("%d%d", &x1, &y1);
    printf("Enter bottom-right coordinates (x2, y2): ");
    scanf("%d%d", &x2, &y2);
    
    depth = (x2 - x1) / 4;  // Calculate depth for bar3d
    mx = (x1 + x2) / 2;
    my = (y1 + y2) / 2;

    draw();  // Draw the original object
    trans(); // Perform translation
    
    getch();
    closegraph();
    return 0;
}

void draw() {
    bar3d(x1, y1, x2, y2, depth, 1);
    outtextxy(x1 + 50, y1 - 15, "Object");
}

void trans() {
    int a1, a2, b1, b2, dep;
    int tx, ty;

    printf("Enter the translation distance (tx, ty): ");
    scanf("%d%d", &tx, &ty);

    // Compute translated coordinates
    a1 = x1 + tx;
    a2 = x2 + tx;
    b1 = y1 + ty;
    b2 = y2 + ty;
    dep = (a2 - a1) / 4;  // Maintain depth proportion

    bar3d(a1, b1, a2, b2, dep, 1);
    outtextxy(a1 + 50, b1 - 15, "Image");
}

