#pragma once

#include <hyue/RenderSystem.h>

namespace hyue {

class RenderSystemGL : public RenderSystem {
public:
    RenderSystemGL(const RenderSystemDesc&);

protected:
    bool query_renderer_details(
        RendererInfo* out_info
        , RenderingCapabilities* out_caps
    ) override;
};

}