#include<stdio.h>
#include<conio.h>
#include<graphics.h>

int main(){
    int gd = DETECT, gm;
    float shy;
    initgraph(&gd, &gm, NULL);

    printf("Enter the shear factor shy along y-axis: ");
    scanf("%f", &shy);

    int x1 = 200, y1 = 100;
    int x2 = 300, y2 = 100;
    int x3 = 300, y3 = 200;
    int x4 = 200, y4 = 200;

    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x4, y4);
    line(x4, y4, x1, y1);

    printf("Y-Shear\n");

    setcolor(WHITE);

    line(x1, y1 + (x1 * shy), x2, y2 + (x2 * shy));
    line(x2, y2 + (x2 * shy), x3, y3 + (x3 * shy));
    line(x3, y3 + (x3 * shy), x4, y4 + (x4 * shy));
    line(x4, y4 + (x4 * shy), x1, y1 + (x1 * shy));

    getch();
    closegraph();
    return 0;
}

