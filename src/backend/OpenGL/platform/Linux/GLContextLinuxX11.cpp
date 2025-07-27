#include "GLContextLinuxX11.h"

namespace hyue {

UniquePtr<GLContext> GLContext::create() {
    return std::make_unique<GLContextLinuxX11>();
}

}