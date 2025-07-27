#pragma once

#include <map>
#include <memory>
#include <string>

#include <hyue/RenderTarget.h>
#include <hyue/SwapChainDesc.h>

namespace hyue {

class HYUE_API SwapChain : public RenderTarget {
public:
    ~SwapChain();

    Extent2D get_resolution() const;

    uint32_t get_num_color_attachments() const;

    bool has_depth_attachment() const;

    bool has_stencil_attachment() const;

    virtual bool is_presentable() const = 0;

    virtual void present() = 0;

    virtual std::uint32_t get_current_swap_index() const = 0;

    virtual std::uint32_t get_num_swap_buffers() const = 0;

    virtual Format get_color_format() const = 0;

    virtual Format get_depth_stencil_format() const = 0;

    bool resize_fuffers(const Extent2D& resolution, long flags = 0);

    virtual bool set_vsync_interval(std::uint32_t vsync_interval) = 0;

public:
    bool switch_fullscreen(bool enable);

    Surface* GetSurface() const;
};

}