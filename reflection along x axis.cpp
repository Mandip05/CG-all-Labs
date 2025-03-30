#include <stdio.h>
#include <graphics.h>

// Function to draw a triangle
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

// Function to perform reflection along the x-axis
void reflectAlongX(int *x1, int *y1, int *x2, int *y2, int *x3, int *y3) {
    // Reflection along the x-axis: y = -y
    *y1 = -*y1;
    *y2 = -*y2;
    *y3 = -*y3;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Input the coordinates of the triangle from the user
    int x1, y1, x2, y2, x3, y3;
    printf("Enter the coordinates of the first vertex (x1 y1): ");
    scanf("%d %d", &x1, &y1);

    printf("Enter the coordinates of the second vertex (x2 y2): ");
    scanf("%d %d", &x2, &y2);

    printf("Enter the coordinates of the third vertex (x3 y3): ");
    scanf("%d %d", &x3, &y3);

    // Draw the original triangle
    setcolor(BLUE);  // Set color for original triangle
    drawTriangle(x1, y1, x2, y2, x3, y3);
    
    // Wait a while before showing the reflected triangle
    delay(1000); // Delay to show the original triangle for a second

    // Perform the reflection along the x-axis
    reflectAlongX(&x1, &y1, &x2, &y2, &x3, &y3);

    // Draw the reflected triangle
    setcolor(GREEN);  // Set color for reflected triangle
    drawTriangle(x1, y1, x2, y2, x3, y3);

    // Wait for a key press before closing the graphics window
    getch();
    closegraph();

    return 0;
}

