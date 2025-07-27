#include <hyue/RenderSystem.h>
#include <hyue/RendererInfo.h>

#if defined(USE_OPENGL)
#include "backend/OpenGL/RenderSystemGL.h"
#endif

namespace hyue {

struct RenderSystem::PImpl
{
    std::string             name;
    bool                    has_info     = false;
    RendererInfo            info;
    // bool                    hasCaps     = false;
    // RenderingCapabilities   caps;
};



RenderSystemPtr RenderSystem::load(const RenderSystemDesc& desc) {

    RenderSystemPtr renderer;

#if defined(USE_OPENGL)
    if (desc.name == "OpenGL") {
        renderer = std::make_unique<RenderSystemGL>(desc);
    }
#endif

    return renderer;
}

RenderSystemPtr RenderSystem::load(const String &renderer_name) {
    RenderSystemDesc desc;
    desc.name = renderer_name;
    return load(desc);
}

RenderSystem::RenderSystem():pimpl_(new PImpl) { }

RenderSystem::~RenderSystem() { 
    delete pimpl_;
}

const RendererInfo& RenderSystem::get_renderer_info() {
    if(! pimpl_->has_info) {
        if(query_renderer_details(&pimpl_->info, nullptr)){
            pimpl_->has_info = true;
        }
    }
    return pimpl_->info;
}

}