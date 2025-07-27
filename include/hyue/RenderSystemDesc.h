#pragma once

#include <hyue/export.h>
#include <hyue/geometry.h>
#include <hyue/type_alias.h>

namespace hyue {

struct HYUE_API RenderSystemDesc {
    String name;
    Extent2D resolution;
};

}