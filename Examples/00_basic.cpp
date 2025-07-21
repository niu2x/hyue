#include <DrawingMoon/DrawingMoon.h>
#include <stdlib.h>

int main() {
    DrawingMoon::init();

    while (!DrawingMoon::should_exit()) {
        DrawingMoon::clear();
        DrawingMoon::swap_buffers();

        DrawingMoon::poll_events();
    }

    DrawingMoon::shutdown();
    return EXIT_FAILURE;
}