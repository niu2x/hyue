#pragma once

#include <hyue/type_alias.h>

namespace hyue {

class GLContext;

class GLContextManager {
public:
    SharedPtr<GLContext> alloc_context();
};

}