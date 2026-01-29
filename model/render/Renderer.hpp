#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "Image.hpp"

#include "../fractals/IFractal.hpp"
#include "Camera.hpp"
#include "IColorScheme.hpp"

namespace fe::model::render {

class Renderer {
public:
    Image render(const fractals::IFractal& fractal,
                 const Camera& camera,
                 const IColorScheme& color_scheme,
                 std::size_t max_iters) const;
};

}

#endif // RENDERER_HPP
