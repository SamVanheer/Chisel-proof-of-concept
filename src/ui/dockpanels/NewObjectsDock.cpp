#include "ui_NewObjectsDock.h"

#include "ui/dockpanels/NewObjectsDock.hpp"

NewObjectsDock::NewObjectsDock(QWidget* parent)
{
	_ui = std::make_unique<Ui_NewObjectsDock>();

	_ui->setupUi(this);
}

NewObjectsDock::~NewObjectsDock() = default;
