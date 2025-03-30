#include <stdio.h>   // For printf() and scanf()
#include <graphics.h> // For graphical functions

// Function to draw a simple car
void drawCar(int x, int y) {
    // Car body
    rectangle(x, y, x + 200, y + 50);           // Main body
    rectangle(x + 30, y - 30, x + 170, y);      // Top part

    // Wheels
    circle(x + 50, y + 60, 20);                 // Front wheel
    circle(x + 150, y + 60, 20);                // Rear wheel

    // Fill wheels
    setfillstyle(SOLID_FILL, WHITE);
    floodfill(x + 50, y + 60, WHITE);
    floodfill(x + 150, y + 60, WHITE);

    // Fill car body with color
    setfillstyle(SOLID_FILL, BLUE);
    floodfill(x + 1, y + 1, WHITE);

    // Fill top part of car
    setfillstyle(SOLID_FILL, BLACK);
    floodfill(x + 31, y - 1, WHITE);
}

int main() {
    

    int x, y;
    printf("Enter the top-left corner coordinates of the car (x y): ");
    scanf("%d %d", &x, &y);
    
    int gd = DETECT, gm;  // Graphics driver and mode
    initgraph(&gd, &gm, NULL);

    setcolor(WHITE);
    drawCar(x, y);

    getch(); // Wait for a key press
    closegraph(); // Close the graphics mode
    return 0;
}

