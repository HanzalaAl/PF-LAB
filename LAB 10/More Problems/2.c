// 2. Define a structure to represent a point in 2D space with x and y coordinates. Implement
// functions to calculate the distance between two points and to check if a point lies within
// a specific rectangular boundary.

#include <stdio.h>
#include <math.h>

typedef struct {
    float x;
    float y;
} Point;

float calculateDistance(Point p1, Point p2);
int isPointInsideRectangle(Point p, Point topLeft, Point bottomRight);

int main() {
    Point p1, p2, topLeft, bottomRight, testPoint;
    
    printf("Enter coordinates of the first point (x y): ");
    scanf("%f %f", &p1.x, &p1.y);
    
    printf("Enter coordinates of the second point (x y): ");
    scanf("%f %f", &p2.x, &p2.y);

    float distance = calculateDistance(p1, p2);
    printf("Distance between the two points: %.2f\n", distance);

    printf("\nEnter coordinates of the top-left corner of the rectangle (x y): ");
    scanf("%f %f", &topLeft.x, &topLeft.y);

    printf("Enter coordinates of the bottom-right corner of the rectangle (x y): ");
    scanf("%f %f", &bottomRight.x, &bottomRight.y);

    printf("Enter coordinates of the point to check (x y): ");
    scanf("%f %f", &testPoint.x, &testPoint.y);

    if (isPointInsideRectangle(testPoint, topLeft, bottomRight)) {
        printf("The point lies within the rectangle.\n");
    } else {
        printf("The point does not lie within the rectangle.\n");
    }

    return 0;
}

float calculateDistance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

int isPointInsideRectangle(Point p, Point topLeft, Point bottomRight) {
    return (p.x >= topLeft.x && p.x <= bottomRight.x &&
            p.y <= topLeft.y && p.y >= bottomRight.y);
}
