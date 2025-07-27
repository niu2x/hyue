#pragma once

#include <memory>
#include <string>

namespace hyue {

template <class T> 
using UniquePtr = std::unique_ptr<T>;

template <class T> 
using SharedPtr = std::shared_ptr<T>;

using String = std::string;

}