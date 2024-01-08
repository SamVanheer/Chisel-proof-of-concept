#pragma once

#include <QWidget>

class QSplitter;
class Viewport3DWindow;

class ViewportFourWayWindow final : public QWidget
{
public:
	explicit ViewportFourWayWindow(QWidget* parent = nullptr);
	~ViewportFourWayWindow();

private:
	QSplitter* _topSplitter;
	QSplitter* _bottomSplitter;
	QSplitter* _verticalSplitter;

	Viewport3DWindow* _view3D;
	Viewport3DWindow* _viewTop;
	Viewport3DWindow* _viewFront;
	Viewport3DWindow* _viewSide;
};
