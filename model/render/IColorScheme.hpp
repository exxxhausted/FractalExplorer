#ifndef ICOLORSCHEME_HPP
#define ICOLORSCHEME_HPP

#include <optional>

#include <QRgb>

namespace fe::model::render {

class IColorScheme {
public:
    virtual ~IColorScheme() = default;
    virtual QRgb interpret(const std::optional<std::size_t>& res, std::size_t max_iters) const = 0;
};

} // namespace fe::model::render

#endif // ICOLORSCHEME_HPP
