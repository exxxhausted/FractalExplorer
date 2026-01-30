#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <QImage>

#include "../fractals/IFractal.hpp"
#include "Camera.hpp"
#include "IColorScheme.hpp"

namespace fe::model::render {

struct Tile {
    std::size_t x0, y0;
    std::size_t width, height;
};

class Renderer {
public:
    std::vector<Tile> makeTiles(const model::ScreenResolution& res,
                                std::size_t tile_size) const;

    void renderTile(QImage& img,
                    const Tile& tile,
                    const model::render::Camera& camera,
                    const model::fractals::IFractal& fractal,
                    const model::render::IColorScheme& color_scheme,
                    std::size_t max_iters) const;

    QImage render(const fractals::IFractal& fractal,
                  const Camera& camera,
                  const IColorScheme& color_scheme,
                  std::size_t max_iters) const;
};

}

#endif // RENDERER_HPP
