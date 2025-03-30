#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <conio.h>  // For kbhit()

#define M_PI 3.14159265358979323846

void wind(float x[7], float y[7]);

int main() {
    int gd = DETECT, gm;
    float x[7], y[7], maxx, maxy, xw1, yw1;
    float theta = 30;

    initgraph(&gd, &gm, "");  // Update path if needed

    maxx = getmaxx();
    maxy = getmaxy();

    // Windmill center
    x[0] = maxx / 2;
    y[0] = maxy / 2;

    // Slightly shorter blade coordinates
    x[1] = y[4] = x[2] = -100;  // Shortened Blade 1
    y[1] = y[5] = y[6] = 70;    // Shortened for Blade 3 visibility
    y[2] = 45;
    y[3] = -120;                // Shortened Blade 2
    x[3] = 0;
    x[4] = 30;
    x[5] = 100;                 // Shortened Blade 3
    x[6] = 80;

    // Convert degrees to radians for rotation
    theta = theta * M_PI / 180;

    // Rotation animation loop
    while (!kbhit()) {
        wind(x, y);  // Draw windmill

        // Rotation logic for all blades
        for (int i = 1; i <= 6; i++) {
            xw1 = cos(theta) * x[i] + sin(theta) * y[i];
            yw1 = -sin(theta) * x[i] + cos(theta) * y[i];
            x[i] = xw1;
            y[i] = yw1;
        }

        delay(50);       // Delay for smooth animation
        cleardevice();   // Clear screen for next frame
    }

    closegraph();
    return 0;
}

// Function to draw the windmill
void wind(float x[7], float y[7]) {
    // Windmill stand
    line(x[0], y[0], x[0] - 50, y[0] + 200);
    line(x[0], y[0], x[0] + 50, y[0] + 200);
    line(x[0] - 60, y[0] + 200, x[0] + 60, y[0] + 200);

    // Blade 1
    line(x[0], y[0], x[0] + x[1], y[0] - y[1]);
    line(x[0], y[0], x[0] + x[2], y[0] - y[2]);
    line(x[0] + x[1], y[0] - y[1], x[0] + x[2], y[0] - y[2]);

    // Blade 2
    line(x[0], y[0], x[0] + x[3], y[0] - y[3]);
    line(x[0], y[0], x[0] + x[4], y[0] - y[4]);
    line(x[0] + x[3], y[0] - y[3], x[0] + x[4], y[0] - y[4]);

    // Blade 3 (Adjusted for visibility)
    line(x[0], y[0], x[0] - x[5], y[0] - y[5]);
    line(x[0], y[0], x[0] - x[6], y[0] - y[6]);
    line(x[0] - x[5], y[0] - y[5], x[0] - x[6], y[0] - y[6]);
}

