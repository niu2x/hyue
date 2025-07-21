#pragma once

#include <iostream>

#define RUNTIME_ASSERT(cond, msg)                                                                  \
    if (!(cond)) {                                                                                 \
        std::cerr << (msg) << std::endl;                                                           \
        panic();                                                                                   \
    }

void panic();
