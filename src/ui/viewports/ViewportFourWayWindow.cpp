#include <QBoxLayout>
#include <QSplitter>

#include "ui/viewports/Viewport3DWindow.hpp"
#include "ui/viewports/ViewportFourWayWindow.hpp"

ViewportFourWayWindow::ViewportFourWayWindow(QWidget* parent)
	: QWidget(parent)
{
	_topSplitter = new QSplitter();
	_bottomSplitter = new QSplitter();
	_verticalSplitter = new QSplitter();

	_view3D = new Viewport3DWindow();
	_viewTop = new Viewport3DWindow();
	_viewFront = new Viewport3DWindow();
	_viewSide = new Viewport3DWindow();

	_view3D->SetButtonText("camera");
	_viewTop->SetButtonText("top (x/y)");
	_viewFront->SetButtonText("front (y/z)");
	_viewSide->SetButtonText("side (x/z)");

	_verticalSplitter->setOrientation(Qt::Vertical);

	_verticalSplitter->addWidget(_topSplitter);
	_verticalSplitter->addWidget(_bottomSplitter);

	_topSplitter->addWidget(_view3D->GetContainer());
	_topSplitter->addWidget(_viewTop->GetContainer());
	
	_bottomSplitter->addWidget(_viewFront->GetContainer());
	_bottomSplitter->addWidget(_viewSide->GetContainer());

	auto layout = new QHBoxLayout();

	setLayout(layout);

	layout->addWidget(_verticalSplitter);

	setMinimumSize(600, 400);

	connect(_topSplitter, &QSplitter::splitterMoved, this, [this]
		{
			_bottomSplitter->setSizes(_topSplitter->sizes());
		});

	connect(_bottomSplitter, &QSplitter::splitterMoved, this, [this]
		{
			_topSplitter->setSizes(_bottomSplitter->sizes());
		});
}

ViewportFourWayWindow::~ViewportFourWayWindow() = default;
