#include "GLContextManager.h"
#include "GLContext.h"

namespace hyue {

std::shared_ptr<GLContext> GLContextManager::alloc_context() {

    auto c = GLContext::create();
    return c;
    
}

}