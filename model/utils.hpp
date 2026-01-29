#ifndef UTILS_HPP
#define UTILS_HPP

#include <cstddef>

namespace fe::model {

struct ScreenResolution {
    std::size_t width;
    std::size_t height;
};

struct ScreenPoint {
    std::size_t x;
    std::size_t y;
};

} // namespace fe::model

#endif // UTILS_HPP
