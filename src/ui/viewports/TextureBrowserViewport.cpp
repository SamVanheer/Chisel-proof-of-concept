#include <QOpenGLFunctions>

#include "ui/viewports/TextureBrowserViewport.hpp"

void TextureBrowserViewport::paintGL()
{
	QOpenGLFunctions* gl = QOpenGLContext::currentContext()->functions();

	gl->glClearColor(0.f, 0.f, 0.f, 1.f);
	gl->glClear(GL_COLOR_BUFFER_BIT);

	gl->glViewport(0, 0, width(), height());
}
