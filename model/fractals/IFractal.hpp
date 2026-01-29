#ifndef IFRACTAL_HPP
#define IFRACTAL_HPP

#include <optional>
#include <complex>

namespace fe::model::fractals {

class IFractal {
public:
    virtual ~IFractal() = default;

    virtual
    std::optional<std::size_t> escape_time(const std::complex<double>& c, std::size_t max_iter) const = 0;
};

} // namespace fe::model::fractals

#endif // IFRACTAL_HPP
