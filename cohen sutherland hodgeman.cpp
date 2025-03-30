#include <stdio.h>
#include <graphics.h>

#define MAX_POINTS 20

float x_min, y_min, x_max, y_max;

typedef struct {
    float x, y;
} Point;

// Function to check if a point is inside the clipping boundary
int inside(Point p, int edge) {
    switch (edge) {
        case 0: return p.x >= x_min; // Left
        case 1: return p.x <= x_max; // Right
        case 2: return p.y >= y_min; // Bottom
        case 3: return p.y <= y_max; // Top
    }
    return 0;
}

// Function to find the intersection point of a line with a clipping boundary
Point intersect(Point p1, Point p2, int edge) {
    Point p;
    float m;

    if (p1.x != p2.x) m = (p2.y - p1.y) / (p2.x - p1.x);

    switch (edge) {
        case 0: // Left
            p.x = x_min;
            p.y = p1.y + m * (x_min - p1.x);
            break;
        case 1: // Right
            p.x = x_max;
            p.y = p1.y + m * (x_max - p1.x);
            break;
        case 2: // Bottom
            p.y = y_min;
            p.x = p1.x + (y_min - p1.y) / m;
            break;
        case 3: // Top
            p.y = y_max;
            p.x = p1.x + (y_max - p1.y) / m;
            break;
    }
    return p;
}

// Function to clip the polygon using the Sutherland-Hodgman algorithm
void sutherlandHodgman(Point in[], int inCount) {
    Point out[MAX_POINTS];
    int outCount;
    
    for (int edge = 0; edge < 4; edge++) {
        outCount = 0;
        for (int i = 0; i < inCount; i++) {
            Point p1 = in[i];
            Point p2 = in[(i + 1) % inCount]; // Next point

            int inside1 = inside(p1, edge);
            int inside2 = inside(p2, edge);

            if (inside1 && inside2) {
                out[outCount++] = p2; // Both points inside
            } else if (inside1 && !inside2) {
                out[outCount++] = intersect(p1, p2, edge); // Exiting
            } else if (!inside1 && inside2) {
                out[outCount++] = intersect(p1, p2, edge); // Entering
                out[outCount++] = p2;
            }
        }
        inCount = outCount;
        for (int i = 0; i < inCount; i++) in[i] = out[i];
    }

    setcolor(RED);
    for (int i = 0; i < inCount; i++) {
        line(in[i].x, in[i].y, in[(i + 1) % inCount].x, in[(i + 1) % inCount].y);
    }
}

int main() {
    int n;
    
    // Get input BEFORE calling initgraph()
    printf("Enter the coordinates of the clipping window (x_min, y_min, x_max, y_max): ");
    scanf("%f %f %f %f", &x_min, &y_min, &x_max, &y_max);

    printf("Enter the number of vertices in the polygon: ");
    scanf("%d", &n);

    Point poly[MAX_POINTS];
    printf("Enter the coordinates of the polygon vertices (x y):\n");
    for (int i = 0; i < n; i++) {
        scanf("%f %f", &poly[i].x, &poly[i].y);
    }

    // Initialize graphics AFTER input
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Draw clipping rectangle
    rectangle(x_min, y_min, x_max, y_max);

    // Draw original polygon
    setcolor(WHITE);
    for (int i = 0; i < n; i++) {
        line(poly[i].x, poly[i].y, poly[(i + 1) % n].x, poly[(i + 1) % n].y);
    }

    getch();
    cleardevice();

    // Redraw clipping window
    rectangle(x_min, y_min, x_max, y_max);
    sutherlandHodgman(poly, n);

    getch();
    closegraph();
    return 0;
}

