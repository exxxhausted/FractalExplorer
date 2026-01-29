#ifndef QTFRACTALEXPLORERVIEW_HPP
#define QTFRACTALEXPLORERVIEW_HPP

#include <QWidget>

#include "../model/render/Image.hpp"

namespace fe::controller {
class FractalExplorerController;
}

namespace fe::view {
class QtFractalExplorerView final
    : public QWidget
{
    Q_OBJECT

public:

    explicit QtFractalExplorerView(QWidget* parent = nullptr);

signals:

    void zoomRequested(const model::ScreenPoint& mouse, double factor);
    void panRequested(int dx, int dy);
    void resizeRequested(const model::ScreenResolution& newRes);;
    void resetRequested();

public slots:

    void setImage(const model::render::Image&);

protected:

    // --- Qt events ---
    void paintEvent(QPaintEvent*) override;
    void wheelEvent(QWheelEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void resizeEvent(QResizeEvent* event) override;
    void mouseReleaseEvent(QMouseEvent*) override;
    void keyPressEvent(QKeyEvent* event) override;

private:

    QImage image_;
    QPointF last_mouse_pos_;
    bool dragging_ = false;

};

} // namespace fe::veiw

#endif // QTFRACTALEXPLORERVIEW_HPP
