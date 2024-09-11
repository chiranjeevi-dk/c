#include <stdio.h>

struct Point {
    int x;
    int y;
};

int main() {
    struct Point p = {.y = 5, .x = 10};  // Designated initializer
    printf("x: %d, y: %d\n", p.x, p.y);
    return 0;
}
