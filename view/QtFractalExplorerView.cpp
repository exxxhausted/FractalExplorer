#include "QtFractalExplorerView.hpp"

#include <QPainter>
#include <QMouseEvent>
#include <QWheelEvent>

namespace fe::view {

QtFractalExplorerView::QtFractalExplorerView(QWidget* parent)
    : QWidget(parent)
{
    setFocusPolicy(Qt::StrongFocus);
    setMouseTracking(true);
}

void QtFractalExplorerView::setImage(const fe::model::render::Image& img) {
    const auto res = img.resolution();

    image_ = QImage(
        img.data(),
        int(res.width),
        int(res.height),
        QImage::Format_RGB888
        );

    update();
}

void QtFractalExplorerView::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    painter.drawImage(0, 0, image_);
}

void QtFractalExplorerView::wheelEvent(QWheelEvent* event) {
    const double factor = event->angleDelta().y() > 0 ? 1.1 : 0.9;
    emit zoomRequested({static_cast<std::size_t>(event->position().x()),
                        static_cast<std::size_t>(event->position().y()) }, factor);
}

void QtFractalExplorerView::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        last_mouse_pos_ = event->pos();
        dragging_ = true;
    }
}

void QtFractalExplorerView::mouseMoveEvent(QMouseEvent* event) {
    if(dragging_) {
        const QPointF delta = event->pos() - last_mouse_pos_;
        emit panRequested(delta.x(), delta.y());
        last_mouse_pos_ = event->pos();
    }
}

void QtFractalExplorerView::resizeEvent(QResizeEvent* event) {
    emit resizeRequested({static_cast<std::size_t>(event->size().width()),
                          static_cast<std::size_t>(event->size().height())});
}

void QtFractalExplorerView::mouseReleaseEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        dragging_ = false;
    }
}

void QtFractalExplorerView::keyPressEvent(QKeyEvent* event) {
    if (event->key() == Qt::Key_Escape) {
        emit resetRequested();
    } else {
        QWidget::keyPressEvent(event);
    }
}

} // namespace fe::view
