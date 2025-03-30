#include<stdio.h>
#include<conio.h>
#include<graphics.h>

int main(){
    int gd = DETECT, gm;
    float shx;
    initgraph(&gd, &gm, NULL);

    printf("Enter the shear factor shx along x-axis: ");
    scanf("%f", &shx);

    int x1 = 200, y1 = 100;
    int x2 = 300, y2 = 100;
    int x3 = 300, y3 = 200;
    int x4 = 200, y4 = 200;

    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x4, y4);
    line(x4, y4, x1, y1);

    printf("X-Shear\n");

    setcolor(WHITE);

    line(x1 + (y1 * shx), y1, x2 + (y2 * shx), y2);
    line(x2 + (y2 * shx), y2, x3 + (y3 * shx), y3);
    line(x3 + (y3 * shx), y3, x4 + (y4 * shx), y4);
    line(x4 + (y4 * shx), y4, x1 + (y1 * shx), y1);

    getch();
    closegraph();
    return 0;
}

