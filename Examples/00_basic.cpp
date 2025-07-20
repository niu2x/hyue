#include <DrawingMoon/DrawingMoon.h>
#include <stdlib.h>

int main() {
    DrawingMoon::InitParam init_param;

    init_param.window_system_type = DrawingMoon::WindowSystemType::Qt5;
    init_param.graphic_api = DrawingMoon::GraphicAPI::OpenGL;

    if (DrawingMoon::init(init_param)) {
        return DrawingMoon::run();
    }
    return EXIT_FAILURE;
}