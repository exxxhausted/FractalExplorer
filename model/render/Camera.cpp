#include "Camera.hpp"

namespace fe::model::render {

Camera::Camera(const ScreenResolution& resolution,
               const std::complex<double> center,
               double scale) :
    resolution_(resolution),
    center_(center),
    scale_(scale) {}

std::complex<double> Camera::map(const ScreenPoint& point) const {
    long long dx = static_cast<long long>(point.x) - static_cast<long long>(resolution_.width) / 2;
    long long dy = static_cast<long long>(point.y) - static_cast<long long>(resolution_.height) / 2;

    double re = center_.real() + dx * scale_;
    double im = center_.imag() - dy * scale_;

    return std::complex<double>(re, im);
}

void Camera::set_resolution(const ScreenResolution& res) noexcept { resolution_ = res; }
ScreenResolution Camera::resolution() const noexcept { return resolution_; }

void Camera::set_center(const std::complex<double>& center) noexcept { center_ = center; }
std::complex<double> Camera::center() const noexcept { return center_; }

void Camera::set_scale(double scale) noexcept { scale_ = scale; }
double Camera::scale() const noexcept { return scale_; }

}
