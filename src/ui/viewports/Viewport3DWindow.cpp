#include <QCursor>
#include <QOpenGLContext>
#include <QOpenGLFunctions>
#include <QPainter>
#include <QWidget>

#include "ui/viewports/Viewport3DWindow.hpp"

Viewport3DWindow::Viewport3DWindow()
	: QOpenGLWindow()
	, _container(QWidget::createWindowContainer(this))
	, _regularFont("Arial", 10)
	, _regularFontMetrics(_regularFont)
	, _boldFont("Arial", 10, QFont::Bold)
	, _boldFontMetrics(_boldFont)
{
	connect(this, &Viewport3DWindow::frameSwapped, this, qOverload<>(&Viewport3DWindow::update));
}

Viewport3DWindow::~Viewport3DWindow() = default;

void Viewport3DWindow::SetButtonText(const QString& text)
{
	_buttonText = text;
	_regularButtonTextSize = _regularFontMetrics.size(0, _buttonText);
	_boldButtonTextSize = _boldFontMetrics.size(0, _buttonText);
}

void Viewport3DWindow::initializeGL()
{
	QOpenGLFunctions* gl = QOpenGLContext::currentContext()->functions();

	gl->glClearColor(0.5f, 0.5f, 0.5f, 1.f);
}

void Viewport3DWindow::paintGL()
{
	QOpenGLFunctions* gl = QOpenGLContext::currentContext()->functions();

	gl->glClear(GL_COLOR_BUFFER_BIT);

	gl->glViewport(0, 0, width(), height());

	// TODO: this should be in a subclass

	QPainter painter{this};

	// Determine whether the user is mousing over right now.
	// Relying on events for this won't work because QWindow objects don't receive Leave events.
	QPointF pos = QCursor::pos();

	pos = mapFromGlobal(pos);

	const bool isMousedOver = pos.x() >= 0
		&& pos.y() >= 0
		&& pos.x() <= _boldButtonTextSize.width()
		&& pos.y() <= _boldButtonTextSize.height();

	const QFont& font = isMousedOver ? _boldFont : _regularFont;
	const QSizeF& size = isMousedOver ? _boldButtonTextSize : _regularButtonTextSize;

	painter.fillRect(0, 0, size.width(), size.height(), Qt::black);

	painter.setPen(Qt::white);
	painter.setFont(font);
	painter.drawText(0, 0, width(), height(), Qt::AlignLeft | Qt::AlignTop, _buttonText);
}
