#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <vector>
#include <cstdint>

#include "../utils.hpp"

namespace fe::model::render {

struct Color {
    std::uint8_t r, g, b;
};

class Image {
public:

    Image(const ScreenResolution&);

    void set_resolution(const ScreenResolution&);
    ScreenResolution resolution() const noexcept;

    void set_color(const ScreenPoint&, const Color&);
    Color color(const ScreenPoint&) const noexcept;

private:

    ScreenResolution resolution_;
    std::vector<Color> pixels_;

};

} // namespace fe::model::render

#endif // IMAGE_HPP
