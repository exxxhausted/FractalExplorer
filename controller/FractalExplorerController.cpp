#include "FractalExplorerController.hpp"

namespace fe::controller {

FractalExplorerController::FractalExplorerController(QObject* parent,
                                                     std::unique_ptr<model::fractals::IFractal> frac,
                                                     std::unique_ptr<model::render::IColorScheme> cs) :
    QObject(parent),
    fractal_(std::move(frac)),
    color_scheme_(std::move(cs)) {}

void FractalExplorerController::render() {
    emit imageReady(renderer_.render(*fractal_, camera_, *color_scheme_, max_iters_));
}

void FractalExplorerController::zoom(const model::ScreenPoint& mouse_position, double factor) {
    if(factor <= 0) throw std::invalid_argument("Invalid factor");

    auto before = camera_.map(mouse_position);

    camera_.set_scale(camera_.scale() / factor);

    auto after = camera_.map(mouse_position);

    camera_.set_center(camera_.center() - ( - before + after));

    render();
}

void FractalExplorerController::pan(int dx, int dy) {
    auto c = camera_.center();

    c -= std::complex<double>(
        static_cast<double>(dx) * camera_.scale(),
        static_cast<double>(-dy) * camera_.scale()
        );

    camera_.set_center(c);

    render();
}

void FractalExplorerController::resize(const model::ScreenResolution& res) {
    camera_.set_resolution(res);
    render();
}

void FractalExplorerController::reset() {
    camera_ = model::render::Camera{camera_.resolution()};
    render();
}

void FractalExplorerController::coords(const model::ScreenPoint& pos) {
    emit coordsReady(camera_.map(pos));
}

void FractalExplorerController::set_max_iterations(std::size_t iters) { max_iters_ = iters; }

std::size_t FractalExplorerController::max_iterations() const { return max_iters_; }

void FractalExplorerController::set_fractal(std::unique_ptr<model::fractals::IFractal> fractal) { fractal_ = std::move(fractal); }


} // namespace fe::controller
