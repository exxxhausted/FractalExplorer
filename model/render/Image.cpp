#include "Image.hpp"

#include <stdexcept>

namespace fe::model::render {

Image::Image(const ScreenResolution& resolution) :
    resolution_(resolution),
    pixels_(3 * resolution.height * resolution.width) {}

std::size_t Image::index(const ScreenPoint& p) const noexcept { return 3 * (p.y * resolution_.width + p.x); }

void Image::set_resolution(const ScreenResolution& res) {
    resolution_ = res;
    pixels_.resize(3 * res.height * res.width);
}

ScreenResolution Image::resolution() const noexcept { return resolution_; }

void Image::set_color(const ScreenPoint& point, const Color& color) {
    if(point.x > resolution_.width || point.y > resolution_.height) throw std::invalid_argument("Out of bounds!");
    const std::size_t i = index(point);
    pixels_[i + 0] = color.r;
    pixels_[i + 1] = color.g;
    pixels_[i + 2] = color.b;
}

Color Image::color(const ScreenPoint& point) const noexcept {
    const std::size_t i = index(point);
    return {
        pixels_[i + 0],
        pixels_[i + 1],
        pixels_[i + 2]
    };
}

}
