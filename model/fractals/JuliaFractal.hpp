#ifndef JULIAFRACTAL_HPP
#define JULIAFRACTAL_HPP

#include "IFractal.hpp"

namespace fe::model::fractals {

class JuliaFractal : public IFractal {
public:

    JuliaFractal(const std::complex<double>& c);

    std::optional<std::size_t> escape_time(const std::complex<double>& c, std::size_t max_iter) const override;

    void set_c(const std::complex<double>& c) noexcept;
    std::complex<double> c() const noexcept;

private:

    std::complex<double> c_;

};

}
#endif // JULIAFRACTAL_HPP
