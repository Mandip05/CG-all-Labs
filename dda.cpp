#include <stdio.h>
#include <math.h>

void ddaLine(int x1, int y1, int x2, int y2) {
    // Calculate the differences
    int dx = x2 - x1;
    int dy = y2 - y1;

    // Determine the number of steps required
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    // Calculate the increments for each axis
    float x_increment = (float)dx / steps;
    float y_increment = (float)dy / steps;

    // Initialize starting point
    float x = x1;
    float y = y1;

    // Initialize the grid to store points
    char grid[20][20];
    int i, j;
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 20; j++) {
            grid[i][j] = '.'; // Empty points
        }
    }

    // Initialize previous point
    int prev_x = -1, prev_y = -1;

    printf("Plotting points:\n");
    // Iterate over the steps and plot the points
    for (int k = 0; k <= steps; k++) {
        // Calculate the current integer coordinates
        int rounded_x = (int)round(x);
        int rounded_y = (int)round(y);

        // Check if the current point is different from the previous point
        if (rounded_x != prev_x || rounded_y != prev_y) {
            // Set the point on the grid
            int plot_x = rounded_x;
            int plot_y = 20 - 1 - rounded_y;
            grid[plot_y][plot_x] = '*'; // Mark the point on the grid

            // Print the coordinates of the plotted point
            printf("(%d, %d)\n", rounded_x, rounded_y);

            // Update previous point
            prev_x = rounded_x;
            prev_y = rounded_y;
        }

        // Increment the x and y positions
        x += x_increment;
        y += y_increment;
    }

    // Print the grid with the line representation
    printf("\nLine representation:\n");
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 20; j++) {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int x1, y1, x2, y2;

    // Input line coordinates
    printf("Enter coordinates (x1, y1) and (x2, y2) for line drawing:\n");
    printf("(x1, y1): ");
    scanf("%d %d", &x1, &y1);
    printf("(x2, y2): ");
    scanf("%d %d", &x2, &y2);

    // Call the DDA line-drawing function
    ddaLine(x1, y1, x2, y2);
  
    return 0;
}


