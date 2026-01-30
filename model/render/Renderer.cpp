#include "Renderer.hpp"

#include <QtConcurrent>

namespace fe::model::render {

std::vector<Tile> Renderer::makeTiles(const model::ScreenResolution& res, std::size_t tile_size) const {
    std::vector<Tile> tiles;
    for (std::size_t y = 0; y < res.height; y += tile_size) {
        for (std::size_t x = 0; x < res.width; x += tile_size) {
            tiles.push_back({
                x, y,
                std::min(tile_size, res.width - x),
                std::min(tile_size, res.height - y)
            });
        }
    }
    return tiles;
}

void Renderer::renderTile(model::render::Image& img,
                const Tile& tile,
                const model::render::Camera& camera,
                const model::fractals::IFractal& fractal,
                const model::render::IColorScheme& color_scheme,
                std::size_t max_iters) const
{
    for (std::size_t y = tile.y0; y < tile.y0 + tile.height; ++y) {
        for (std::size_t x = tile.x0; x < tile.x0 + tile.width; ++x) {
            auto c = camera.map({x, y});
            auto iter = fractal.escape_time(c, max_iters);
            auto color = color_scheme.interpret(iter, max_iters);
            img.set_color({x, y}, color);
        }
    }
}

Image Renderer::render(const fractals::IFractal& fractal,
                       const Camera& camera,
                       const IColorScheme& color_scheme,
                       std::size_t max_iters) const
{
    const auto res = camera.resolution();

    Image image(res);

    const std::size_t tileSize = 64;
    auto tiles = makeTiles(res, tileSize);

    QtConcurrent::blockingMap(tiles, [&](const Tile& tile) {
        renderTile(image, tile, camera, fractal, color_scheme, max_iters);
    });

    return image;
}

} // namespace fe::model::render
