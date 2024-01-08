#include "ui_OptionsPage3DViews.h"

#include "ui/optionsdialog/OptionsPage3DViews.hpp"

OptionsPage3DViews::OptionsPage3DViews(QWidget* parent)
	: QWidget(parent)
{
	_ui = std::make_unique<Ui_OptionsPage3DViews>();

	_ui->setupUi(this);
}

OptionsPage3DViews::~OptionsPage3DViews() = default;
