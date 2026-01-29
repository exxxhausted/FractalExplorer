#include "JuliaFractal.hpp"

namespace fe::model::fractals {

JuliaFractal::JuliaFractal(const std::complex<double>& c) : c_(c) {}

std::optional<std::size_t> JuliaFractal::escape_time(const std::complex<double>& c, std::size_t max_iters) const {
    std::complex z = c;

    for(std::size_t i = 0; i < max_iters; ++i) {
        if (std::norm(z) > 4.0) return i;
        z = z * z + c_;
    }

    return std::nullopt;
}

void JuliaFractal::set_c(const std::complex<double>& c) noexcept { c_ = c; }

std::complex<double> JuliaFractal::c() const noexcept { return c_; }

}
