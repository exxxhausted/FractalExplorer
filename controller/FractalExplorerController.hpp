#ifndef FRACTALEXPLORERCONTROLLER_HPP
#define FRACTALEXPLORERCONTROLLER_HPP

#include "../model/fractals/IFractal.hpp"
#include "../model/fractals/MandelbrotFractal.hpp"
#include "../model/render/Camera.hpp"
#include "../model/render/IColorScheme.hpp"
#include "../model/render/GrayScaleColorScheme.hpp"
#include "../model/render/Renderer.hpp"

#include <memory>

#include <QObject>
#include <QImage>

namespace fe::controller {

class FractalExplorerController : public QObject {
    Q_OBJECT
public:

    FractalExplorerController(QObject* parent = nullptr,
                              std::unique_ptr<model::fractals::IFractal> frac = std::make_unique<model::fractals::MandelbrotFractal>(),
                              std::unique_ptr<model::render::IColorScheme> cs = std::make_unique<model::render::GrayScaleColorScheme>());

    // Будут заменены на слоты
    [[deprecated]]void set_max_iterations(std::size_t iters);
    [[deprecated]]std::size_t max_iterations() const;
    [[deprecated]]void set_fractal(std::unique_ptr<model::fractals::IFractal> fractal);

public slots:

    void zoom(const model::ScreenPoint& mouse, double factor);
    void pan(int dx, int dy);
    void resize(const model::ScreenResolution& res);
    void reset();
    void coords(const model::ScreenPoint& pos);

signals:

    void imageReady(const QImage&);
    void coordsReady(const std::complex<double>&);

private:

    void render();

    std::unique_ptr<model::fractals::IFractal> fractal_;
    std::unique_ptr<model::render::IColorScheme> color_scheme_;
    model::render::Camera camera_{};
    model::render::Renderer renderer_{};
    std::size_t max_iters_ = 250;

};

} // namespace fe::controller

#endif // FRACTALEXPLORERCONTROLLER_HPP
