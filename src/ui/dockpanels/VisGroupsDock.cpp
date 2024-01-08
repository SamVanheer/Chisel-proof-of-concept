#include "ui_VisGroupsDock.h"

#include "ui/dockpanels/VisGroupsDock.hpp"

VisGroupsDock::VisGroupsDock(QWidget* parent)
{
	_ui = std::make_unique<Ui_VisGroupsDock>();

	_ui->setupUi(this);
}

VisGroupsDock::~VisGroupsDock() = default;
