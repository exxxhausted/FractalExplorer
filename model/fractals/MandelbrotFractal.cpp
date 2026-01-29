#include "MandelbrotFractal.hpp"

namespace fe::model::fractals {

std::optional<std::size_t> MandelbrotFractal::escape_time(const std::complex<double>& c, std::size_t max_iters) const {
    std::complex<double> z = 0;

    double x = c.real();
    double y = c.imag();

    double x_minus = x - 0.25;
    double q = x_minus * x_minus + y * y;
    if (q * (q + x_minus) < 0.25 * y * y) return std::nullopt;

    double x_plus = x + 1.0;
    if (x_plus * x_plus + y * y < 0.0625) return std::nullopt;

    for (std::size_t i = 0; i < max_iters; ++i) {
        if (std::norm(z) > 4.0) return i;
        z = z * z + c;
    }

    return std::nullopt;
}

} // namespace
