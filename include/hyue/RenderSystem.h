#pragma once

#include <memory>

#include <hyue/RenderSystemDesc.h>
#include <hyue/export.h>
#include <hyue/type_alias.h>

namespace hyue {

class RenderSystem;
using RenderSystemPtr = UniquePtr<RenderSystem>;

class SwapChainDesc;
class SwapChain;

struct RendererInfo;
struct RenderingCapabilities;

class HYUE_API RenderSystem {
public:
    static RenderSystemPtr load(const String &renderer_name);
    static RenderSystemPtr load(const RenderSystemDesc&);

    virtual ~RenderSystem();

    SwapChain* create_swap_chain(const SwapChainDesc& swap_chain_desc);

    const RendererInfo& get_renderer_info();

protected:
    RenderSystem();

    virtual bool query_renderer_details(
        RendererInfo* out_info
        , RenderingCapabilities* out_caps
    ) = 0;

private:
    struct PImpl;
    struct PImpl * pimpl_;
};

}