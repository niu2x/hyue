#pragma once

#include <hyue/type_alias.h>

namespace hyue {

class GLContext {
public:
    virtual ~GLContext() = default;

    static UniquePtr<GLContext> create();
protected:
    GLContext();

private:

};

}