#include "ui_OptionsPageGeneral.h"

#include "ui/optionsdialog/OptionsPageGeneral.hpp"

OptionsPageGeneral::OptionsPageGeneral(QWidget* parent)
	: QWidget(parent)
{
	_ui = std::make_unique<Ui_OptionsPageGeneral>();

	_ui->setupUi(this);
}

OptionsPageGeneral::~OptionsPageGeneral() = default;
