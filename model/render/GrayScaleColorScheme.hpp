#ifndef GRAYSCALECOLORSCHEME_HPP
#define GRAYSCALECOLORSCHEME_HPP

#include "IColorScheme.hpp"

namespace fe::model::render {

class GrayScaleColorScheme : public IColorScheme {
public:
    Color interpret(const std::optional<std::size_t>& res, std::size_t max_iters) const override;
};

} // namespace fe::model::render

#endif // GRAYSCALECOLORSCHEME_HPP
