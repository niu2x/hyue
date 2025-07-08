#pragma once

#include <DrawingMoon/api.h>

namespace DrawingMoon {

enum class GraphicAPI {
    OpenGL,
    OpenMetal,
    OpenVulkan,
};

// class DRAWING_MOON_API GraphicAPIContext {
// public:
//     GraphicAPIContext();
//     virtual ~GraphicAPIContext();
//     virtual void make_current() = 0;
// };

}