#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "../utils.hpp"

#include <complex>

namespace fe::model::render {

class Camera {
public:

    Camera(const ScreenResolution& resolution = {800, 600},
           const std::complex<double> center = {0, 0},
           double scale = 0.005);

    std::complex<double> map(const ScreenPoint& point) const;

    void set_resolution(const ScreenResolution&) noexcept;
    ScreenResolution resolution() const noexcept;

    void set_center(const std::complex<double>&) noexcept;
    std::complex<double> center() const noexcept;

    void set_scale(double) noexcept;
    double scale() const noexcept;

private:

    ScreenResolution resolution_;
    std::complex<double> center_;
    double scale_;

};

} // namespace fe::model::render

#endif // CAMERA_HPP
