#pragma once

#include <DrawingMoon/api.h>

namespace DrawingMoon {

// enum class GraphicAPI {
//     OpenGL,
//     Metal,
//     Vulkan,
// };

// enum class WindowSystemType {
//     GLFW3,
//     Qt5,
// };

// struct InitParam {
//     GraphicAPI graphic_api;
//     WindowSystemType window_system_type;
// };

DRAW_MOON_API void init();
DRAW_MOON_API void shutdown();
DRAW_MOON_API bool should_exit();
DRAW_MOON_API void poll_events();

DRAW_MOON_API void clear();
DRAW_MOON_API void swap_buffers();
//
// DRAWING_MOON_API int run();
}