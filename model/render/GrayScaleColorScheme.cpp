#include "GrayScaleColorScheme.hpp"

namespace fe::model::render {

QRgb GrayScaleColorScheme::interpret(const std::optional<std::size_t>& res, std::size_t max_iters) const {
    if (res == std::nullopt) return qRgb(255, 255, 255);

    std::uint8_t v = static_cast<std::uint8_t>( 255.0 * (*res) / max_iters );

    return qRgb(v, v, v);
}

} // namespace fe::model::render
