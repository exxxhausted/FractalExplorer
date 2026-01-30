#include "QtFractalExplorerView.hpp"

#include <QPainter>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QDebug>
#include <QtConcurrent>

namespace fe::view {

QtFractalExplorerView::QtFractalExplorerView(QWidget* parent)
    : QWidget(parent)
{
    setFocusPolicy(Qt::StrongFocus);
    setMouseTracking(true);

    coords_label_ptr_ = new QLabel(this);
    coords_label_ptr_->setText("Re: 0\nIm: 0");

    coords_label_ptr_->setStyleSheet(
        "QLabel {"
        "  background-color: rgba(0, 0, 0, 160);"
        "  color: white;"
        "  padding: 4px 6px;"
        "  border-radius: 4px;"
        "}"
        );

    coords_label_ptr_->adjustSize();

    coords_label_ptr_->move(
        (width()  - coords_label_ptr_->width()) / 2,
        height() - coords_label_ptr_->height()
        );
}

void QtFractalExplorerView::setImage(const QImage& img) {
    image_ = img;
    update();
}

void QtFractalExplorerView::showCoords(const std::complex<double>& coords) {
    coords_label_ptr_->setText(QString("Re: %1\nIm: %2").arg(coords.real()).arg(coords.imag()));
    coords_label_ptr_->adjustSize();
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
    emit coordsRequested({ static_cast<std::size_t>(event->pos().x()),
                           static_cast<std::size_t>(event->pos().y()) });

    if(dragging_) {
        const QPointF delta = event->pos() - last_mouse_pos_;
        emit panRequested(delta.x(), delta.y());
        last_mouse_pos_ = event->pos();
    }
}

void QtFractalExplorerView::resizeEvent(QResizeEvent* event) {

    coords_label_ptr_->move(
        (width()  - coords_label_ptr_->width()) / 2,
        height() - coords_label_ptr_->height()
        );

    emit resizeRequested({
        static_cast<std::size_t>(width()),
        static_cast<std::size_t>(height())
    });
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
