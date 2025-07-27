#include <hyue/RenderSystem.h>
#include <hyue/RendererInfo.h>
#include <stdlib.h>

int main() {
    auto renderer = hyue::RenderSystem::load("OpenGL");
    auto renderer_info = renderer->get_renderer_info();
    return EXIT_FAILURE;
}