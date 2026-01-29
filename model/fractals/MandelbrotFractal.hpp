#ifndef MANDELBROTFRACTAL_HPP
#define MANDELBROTFRACTAL_HPP

#include "IFractal.hpp"

namespace fe::model::fractals {

class MandelbrotFractal : public IFractal {
public:

    std::optional<std::size_t> escape_time(const std::complex<double>& c, std::size_t max_iters) const override;

};

}
#endif // MANDELBROTFRACTAL_HPP
