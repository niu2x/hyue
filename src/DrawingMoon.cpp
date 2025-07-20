#include <DrawingMoon/DrawingMoon.h>

namespace DrawingMoon {

extern bool init_glfw3();
extern bool init_qt5();

bool init_window_system(WindowSystemType type) {
    switch (type) {
        case WindowSystemType::GLFW3: {
            return init_glfw3();
        }
        case WindowSystemType::Qt5: {
            return init_qt5();
        }
    }
    return false;
}

bool init(const InitParam& param) {
    bool init_succ = init_window_system(param.window_system_type);
    return init_succ;
}

int run() { return 0; }
}
