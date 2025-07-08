#pragma once

#include <DrawingMoon/api.h>

namespace DrawingMoon {

enum class GraphicAPI {
    OpenGL,
    OpenMetal,
    OpenVulkan,
};

enum class WindowSystem {
    GLFW3,
    QT5,
};

class DRAWING_MOON_API Root {
public:
    Root();
    ~Root();
};

// class DRAWING_MOON_API GraphicAPIContext {
// public:
//     GraphicAPIContext();
//     virtual ~GraphicAPIContext();
//     virtual void make_current() = 0;
// };

}