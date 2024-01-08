#include <QDockWidget>
#include <QLabel>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QMessageBox>
#include <QToolBar>

#include "ui_MainWindow.h"

#include "ui/MainWindow.hpp"

#include "ui/dockpanels/MapEditToolsSidebar.hpp"
#include "ui/dockpanels/NewObjectsDock.hpp"
#include "ui/dockpanels/TextureBrowserDock.hpp"
#include "ui/dockpanels/VisGroupsDock.hpp"

#include "ui/optionsdialog/OptionsDialog.hpp"

#include "ui/viewports/ViewportFourWayWindow.hpp"

MainWindow::MainWindow()
{
	setAttribute(Qt::WidgetAttribute::WA_DeleteOnClose);

	setWindowIcon(QIcon{ ":/chisel.ico" });

	_ui = std::make_unique<Ui_MainWindow>();

	_ui->setupUi(this);

	auto editTools = new QDockWidget();

	editTools->setTitleBarWidget(new QWidget());
	editTools->setFeatures(QDockWidget::NoDockWidgetFeatures);
	editTools->setWidget(new MapEditToolsSidebar());

	addDockWidget(Qt::LeftDockWidgetArea, editTools);

	auto textureBrowserDock = new QDockWidget("Textures");

	textureBrowserDock->setWidget(new TextureBrowserDock());
	textureBrowserDock->setAllowedAreas(Qt::RightDockWidgetArea);

	addDockWidget(Qt::RightDockWidgetArea, textureBrowserDock);

	auto visGroupsDock = new QDockWidget("VisGroups");

	visGroupsDock->setWidget(new VisGroupsDock());
	visGroupsDock->setAllowedAreas(Qt::RightDockWidgetArea);

	addDockWidget(Qt::RightDockWidgetArea, visGroupsDock);

	auto newObjectsDock = new QDockWidget("New Objects");

	newObjectsDock->setWidget(new NewObjectsDock());
	newObjectsDock->setAllowedAreas(Qt::RightDockWidgetArea);

	addDockWidget(Qt::RightDockWidgetArea, newObjectsDock);

	QStatusBar* statusBar = this->statusBar();

	auto selectionLabel = new QLabel("no selection.");

	selectionLabel->setFixedWidth(200);

	selectionLabel->setStyleSheet(R"|(
border-style: inset;
border-width: 1px;
border-color: gray silver silver gray;
)|");

	statusBar->addPermanentWidget(selectionLabel);

	auto coordinatesLabel = new QLabel("@-1024, 512");

	coordinatesLabel->setFixedWidth(100);

	coordinatesLabel->setStyleSheet(R"|(
border-style: inset;
border-width: 1px;
border-color: gray silver silver gray;
)|");

	statusBar->addPermanentWidget(coordinatesLabel);

	auto sizeLabel = new QLabel("512w 384l 192h");

	sizeLabel->setFixedWidth(100);

	sizeLabel->setStyleSheet(R"|(
border-style: inset;
border-width: 1px;
border-color: gray silver silver gray;
)|");

	statusBar->addPermanentWidget(sizeLabel);

	auto zoomLabel = new QLabel("Zoom: 0.25");

	zoomLabel->setFixedWidth(75);

	zoomLabel->setStyleSheet(R"|(
border-style: inset;
border-width: 1px;
border-color: gray silver silver gray;
)|");

	statusBar->addPermanentWidget(zoomLabel);

	auto gridLabel = new QLabel("Snap: On Grid: 64");

	gridLabel->setFixedWidth(150);

	gridLabel->setStyleSheet(R"|(
border-style: inset;
border-width: 1px;
border-color: gray silver silver gray;
)|");

	statusBar->addPermanentWidget(gridLabel);

	_mdiArea = new QMdiArea();

	setCentralWidget(_mdiArea);

	connect(_ui->ActionNew, &QAction::triggered, this, &MainWindow::OnNewFile);

	connect(_ui->ActionOptions, &QAction::triggered, this, [this]
		{
			OptionsDialog options{ this };

			options.exec();
		});

	connect(_ui->ActionAboutQt, &QAction::triggered, this, [this]
		{
			QMessageBox::aboutQt(this);
		});
}

MainWindow::~MainWindow() = default;

void MainWindow::OnNewFile()
{
	auto viewport = new ViewportFourWayWindow();

	auto window = _mdiArea->addSubWindow(viewport);

	window->showMaximized();
}
