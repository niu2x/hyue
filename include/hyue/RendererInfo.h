#pragma once

#include <string>
#include <vector>

#include <hyue/type_alias.h>

namespace hyue {

struct RendererInfo {
    String renderer_name;

    String device_name;

    String vendor_name;

    String shading_language_name;

    std::vector<String> extension_names;
};

}