#include "Renderer.hpp"

#include <QtConcurrent>

namespace fe::model::render {

Image Renderer::render(const fractals::IFractal& fractal,
                       const Camera& camera,
                       const IColorScheme& color_scheme,
                       std::size_t max_iters) const
{
    Image image(camera.resolution());

    const std::size_t h = camera.resolution().height;
    const std::size_t w = camera.resolution().width;

    QVector<std::size_t> rows;
    rows.reserve(h);
    for (std::size_t y = 0; y < h; ++y) rows.push_back(y);

    QtConcurrent::blockingMap(rows, [&](std::size_t y) {
        for (std::size_t x = 0; x < w; ++x) {
            auto c = camera.map({x, y});
            auto iter = fractal.escape_time(c, max_iters);
            auto color = color_scheme.interpret(iter, max_iters);
            image.set_color({x, y}, color);
        }
    });

    return image;
}

} // namespace fe::model::render
