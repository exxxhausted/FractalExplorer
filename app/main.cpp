#include <QApplication>
#include <QMainWindow>

#include "QtFractalExplorerView.hpp"
#include "FractalExplorerController.hpp"
//#include "../model/fractals/JuliaFractal.hpp"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    QMainWindow mainWindow;

    auto* view       = new fe::view::QtFractalExplorerView(&mainWindow);
    auto* controller = new fe::controller::FractalExplorerController(&mainWindow);

    QObject::connect(view,       &fe::view::QtFractalExplorerView::zoomRequested,
                     controller, &fe::controller::FractalExplorerController::zoom);

    QObject::connect(view,       &fe::view::QtFractalExplorerView::panRequested,
                     controller, &fe::controller::FractalExplorerController::pan);

    QObject::connect(view,       &fe::view::QtFractalExplorerView::resizeRequested,
                     controller, &fe::controller::FractalExplorerController::resize);

    QObject::connect(view,       &fe::view::QtFractalExplorerView::resetRequested,
                     controller, &fe::controller::FractalExplorerController::reset);

    QObject::connect(controller, &fe::controller::FractalExplorerController::imageReady,
                     view,       &fe::view::QtFractalExplorerView::setImage);

    mainWindow.resize(800, 600);
    mainWindow.setCentralWidget(view);
    mainWindow.show();

    return app.exec();
}
