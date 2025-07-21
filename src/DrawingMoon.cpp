#include "panic.h"
#include <DrawingMoon/DrawingMoon.h>
#include <iostream>

#define USE_GLFW3 1

#if USE_GLFW3
#include <GLFW/glfw3.h>
#endif

#if USE_GLFW3
namespace DrawingMoon::glfw3 {

GLFWwindow* main_window = nullptr;

struct GLFW_WindowEventHandler {
    static void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
        glViewport(0, 0, width, height);
    }
};

bool __init() {
    RUNTIME_ASSERT(main_window == nullptr, "");

    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return false;
    }

    // Configure GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // Create a windowed mode window and its OpenGL context
    main_window = glfwCreateWindow(800, 600, "", nullptr, nullptr);
    if (!main_window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return false;
    }

    glfwSetFramebufferSizeCallback(main_window, GLFW_WindowEventHandler::framebuffer_size_callback);

    // Make the window's context current
    glfwMakeContextCurrent(main_window);

    glfwSwapInterval(1);

    return true;
}

void shutdown() {
    if (main_window) {
        glfwDestroyWindow(main_window);
        main_window = nullptr;
    }
    glfwTerminate();
}

bool should_exit() { return glfwWindowShouldClose(main_window); }

void poll_events() { glfwPollEvents(); }

void swap_buffers() { glfwSwapBuffers(main_window); }

}
#endif

namespace DrawingMoon {

bool __init() {
#if USE_GLFW3
    return glfw3::__init();
#else
    return false;
#endif
}

void init() {
    bool init_succ = __init();
    if (!init_succ) {
        panic();
    }
}

void shutdown() {
#if USE_GLFW3
    return glfw3::shutdown();
#endif
}

bool should_exit() {
#if USE_GLFW3
    return glfw3::should_exit();
#else
    return true;
#endif
}

void poll_events() {
#if USE_GLFW3
    return glfw3::poll_events();
#else
    return true;
#endif
}

void clear() {
#if USE_GLFW3
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
#endif
}

void swap_buffers() {
#if USE_GLFW3
    glfw3::swap_buffers();
#endif
}

// int run() { return 0; }
}
