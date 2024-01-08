#pragma once

#include <QFont>
#include <QFontMetrics>
#include <QOpenGLWindow>
#include <QString>

class Viewport3DWindow : public QOpenGLWindow
{
public:
	explicit Viewport3DWindow();
	~Viewport3DWindow();

	QWidget* GetContainer() const { return _container; }

	void SetButtonText(const QString& text);

protected:
	void initializeGL() override;
	void paintGL() override;

private:
	QWidget* const _container;

	QFont _regularFont;
	QFontMetricsF _regularFontMetrics;

	QFont _boldFont;
	QFontMetricsF _boldFontMetrics;

	QString _buttonText;
	QSizeF _regularButtonTextSize{};
	QSizeF _boldButtonTextSize{};
};
