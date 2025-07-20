#pragma once

#include <DrawingMoon/api.h>

namespace DrawingMoon {

enum class GraphicAPI {
    OpenGL,
    Metal,
    Vulkan,
};

enum class WindowSystemType {
    GLFW3,
    Qt5,
};

struct InitParam {
    GraphicAPI graphic_api;
    WindowSystemType window_system_type;
};

DRAWING_MOON_API bool init(const InitParam& param);
DRAWING_MOON_API int run();
}