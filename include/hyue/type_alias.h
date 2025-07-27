#pragma once

#include <memory>
#include <string>

namespace hyue {

template <class T> using UniquePtr = std::unique_ptr<T>;

using String = std::string;

}