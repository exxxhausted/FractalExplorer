#include "Image.hpp"

#include <stdexcept>

namespace fe::model::render {

Image::Image(const ScreenResolution& resolution) :
    resolution_(resolution),
    pixels_(resolution.height * resolution.width) {}


void Image::set_resolution(const ScreenResolution& res) {
    resolution_ = res;
    pixels_.resize(3 * res.height * res.width);
}

ScreenResolution Image::resolution() const noexcept { return resolution_; }

void Image::set_color(const ScreenPoint& point, const Color& color) {
    if(point.x > resolution_.width || point.y > resolution_.height) throw std::invalid_argument("Out of bounds!");
    pixels_[point.y * resolution_.width + point.x] = color;
}

Color Image::color(const ScreenPoint& point) const noexcept {
    return pixels_[point.y * resolution_.width + point.x];
}

}
