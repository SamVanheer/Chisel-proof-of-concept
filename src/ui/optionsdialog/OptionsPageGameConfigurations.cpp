#include "ui_OptionsPageGameConfigurations.h"

#include "ui/optionsdialog/OptionsPageGameConfigurations.hpp"

OptionsPageGameConfigurations::OptionsPageGameConfigurations(QWidget* parent)
	: QWidget(parent)
{
	_ui = std::make_unique<Ui_OptionsPageGameConfigurations>();

	_ui->setupUi(this);
}

OptionsPageGameConfigurations::~OptionsPageGameConfigurations() = default;
