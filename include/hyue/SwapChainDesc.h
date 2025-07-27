#pragma once

#include <cstdint>

#include <hyue/geometry.h>

namespace hyue {

struct SwapChainDesc {
    Extent2D    resolution;
    int         color_bits      = 32;
    int         stencil_bits    = 8;
    uint32_t    samples         = 1;
    uint32_t    swap_buffers    = 2;
    bool        fullscreen      = false;
    bool        resizable       = false;
};

}