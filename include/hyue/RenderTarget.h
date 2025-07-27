#pragma once

#include <hyue/RenderSystemChild.h>
#include <hyue/geometry.h>

namespace hyue {

class HYUE_API RenderTarget : public RenderSystemChild {
public:
    virtual Extent2D get_resolution() const = 0;
    virtual uint32_t get_samples() const = 0;
    virtual uint32_t get_num_color_attachments() const = 0;
    virtual bool has_depth_attachment() const = 0;
    virtual bool has_stencil_attachment() const = 0;
};

}