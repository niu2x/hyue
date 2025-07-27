#pragma once

#include <hyue/RenderSystem.h>
#include "GLContextManager.h"

namespace hyue {

// class GLContext;

class RenderSystemGL : public RenderSystem {
public:
    RenderSystemGL(const RenderSystemDesc&);

protected:
    bool query_renderer_details(
        RendererInfo* out_info
        , RenderingCapabilities* out_caps
    ) override;

private:
    void create_gl_context_once();

    GLContextManager gl_context_manager_;
};

}