#include "RenderSystemGL.h"

namespace hyue {

RenderSystemGL::RenderSystemGL(const RenderSystemDesc &desc) {}

bool RenderSystemGL::query_renderer_details(
    RendererInfo* out_info
    , RenderingCapabilities* out_caps
) {
    if (out_info != nullptr || out_caps != nullptr)
    {
        create_gl_context_once();
        // if (out_info != nullptr)
        //     gl_query_renderer_info(out_info);
        // if (out_caps != nullptr)
        //     gl_query_rendering_caps(out_caps);
    }
    return true;
}

}