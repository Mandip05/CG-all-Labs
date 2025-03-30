#include <graphics.h>
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

// Structure for a 3D point
typedef struct {
    float x, y, z;
} Point3D;

// Rectangle (cuboid) vertices
Point3D rect[8];

// Rotate around X-axis
void rotateX(Point3D *p, float angle) {
    float rad = angle * PI / 180.0;
    float y = p->y * cos(rad) - p->z * sin(rad);
    float z = p->y * sin(rad) + p->z * cos(rad);
    p->y = y;
    p->z = z;
}

// Rotate around Y-axis
void rotateY(Point3D *p, float angle) {
    float rad = angle * PI / 180.0;
    float x = p->x * cos(rad) + p->z * sin(rad);
    float z = -p->x * sin(rad) + p->z * cos(rad);
    p->x = x;
    p->z = z;
}

// Rotate around Z-axis
void rotateZ(Point3D *p, float angle) {
    float rad = angle * PI / 180.0;
    float x = p->x * cos(rad) - p->y * sin(rad);
    float y = p->x * sin(rad) + p->y * cos(rad);
    p->x = x;
    p->y = y;
}

// Function to draw a line between two 3D points
void drawLine(Point3D p1, Point3D p2) {
    int xc = getmaxx() / 2;
    int yc = getmaxy() / 2;
    line(xc + (int)p1.x, yc - (int)p1.y, xc + (int)p2.x, yc - (int)p2.y);
}

// Function to draw a rectangle (cuboid)
void drawRectangle() {
    int edges[12][2] = {
        {0, 1}, {1, 2}, {2, 3}, {3, 0},
        {4, 5}, {5, 6}, {6, 7}, {7, 4},
        {0, 4}, {1, 5}, {2, 6}, {3, 7}
    };

    for (int i = 0; i < 12; i++) {
        drawLine(rect[edges[i][0]], rect[edges[i][1]]);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    float width, height, depth, angleX, angleY, angleZ;

    // User input for rectangle dimensions
    printf("Enter rectangle width: ");
    scanf("%f", &width);
    printf("Enter rectangle height: ");
    scanf("%f", &height);
    printf("Enter rectangle depth: ");
    scanf("%f", &depth);

    // Define rectangle (cuboid) vertices
    rect[0] = (Point3D){-width / 2, -height / 2, -depth / 2};
    rect[1] = (Point3D){width / 2, -height / 2, -depth / 2};
    rect[2] = (Point3D){width / 2, height / 2, -depth / 2};
    rect[3] = (Point3D){-width / 2, height / 2, -depth / 2};
    rect[4] = (Point3D){-width / 2, -height / 2, depth / 2};
    rect[5] = (Point3D){width / 2, -height / 2, depth / 2};
    rect[6] = (Point3D){width / 2, height / 2, depth / 2};
    rect[7] = (Point3D){-width / 2, height / 2, depth / 2};

    // Display original rectangle
    cleardevice();
    setcolor(WHITE);
    outtextxy(50, 50, "Original Rectangle");
    drawRectangle();
    
    printf("Press any key to enter rotation angles...\n");
    getch(); // Wait for user input before rotation

    // User input for rotation angles
    printf("Enter rotation angles (X Y Z in degrees): ");
    scanf("%f %f %f", &angleX, &angleY, &angleZ);

    // Rotate each vertex
    for (int i = 0; i < 8; i++) {
        rotateX(&rect[i], angleX);
        rotateY(&rect[i], angleY);
        rotateZ(&rect[i], angleZ);
    }

    // Display rotated rectangle
    cleardevice();
    setcolor(WHITE);
    outtextxy(50, 50, "Rotated Rectangle");
    drawRectangle();

    printf("Rotation applied. Check the graphics window.\n");

    getch();  // Wait for key press before exiting
    closegraph();

    return 0;
}

