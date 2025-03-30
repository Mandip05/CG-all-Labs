#include <graphics.h>
#include <stdio.h>

// Function for perspective projection
void perspectiveProjection(int x, int y, int z, int *px, int *py, float d) {
    *px = (int)(x / (1 + (float)z / d));
    *py = (int)(y / (1 + (float)z / d));
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int points[8][3];   // Stores user input (3D points)
    int projected[8][2]; // Stores 2D projected points

    float d = 200.0; // Distance from the viewer to the projection plane

    // Taking input from user
    printf("Enter 8 points (x y z) for a 3D rectangle (cuboid):\n");
    for (int i = 0; i < 8; i++) {
        printf("Point %d: ", i + 1);
        scanf("%d %d %d", &points[i][0], &points[i][1], &points[i][2]);

        // Apply perspective projection
        perspectiveProjection(points[i][0], points[i][1], points[i][2], &projected[i][0], &projected[i][1], d);

        // Adjusting coordinates to center the figure
        projected[i][0] += getmaxx() / 2;
        projected[i][1] += getmaxy() / 2;
    }

    // Draw front face
    line(projected[0][0], projected[0][1], projected[1][0], projected[1][1]);
    line(projected[1][0], projected[1][1], projected[2][0], projected[2][1]);
    line(projected[2][0], projected[2][1], projected[3][0], projected[3][1]);
    line(projected[3][0], projected[3][1], projected[0][0], projected[0][1]);

    // Draw back face
    line(projected[4][0], projected[4][1], projected[5][0], projected[5][1]);
    line(projected[5][0], projected[5][1], projected[6][0], projected[6][1]);
    line(projected[6][0], projected[6][1], projected[7][0], projected[7][1]);
    line(projected[7][0], projected[7][1], projected[4][0], projected[4][1]);

    // Connect front and back faces
    line(projected[0][0], projected[0][1], projected[4][0], projected[4][1]);
    line(projected[1][0], projected[1][1], projected[5][0], projected[5][1]);
    line(projected[2][0], projected[2][1], projected[6][0], projected[6][1]);
    line(projected[3][0], projected[3][1], projected[7][0], projected[7][1]);

    getch();
    closegraph();
    return 0;
}

