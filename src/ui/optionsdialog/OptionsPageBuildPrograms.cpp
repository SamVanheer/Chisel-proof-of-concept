#include "ui_OptionsPageBuildPrograms.h"

#include "ui/optionsdialog/OptionsPageBuildPrograms.hpp"

OptionsPageBuildPrograms::OptionsPageBuildPrograms(QWidget* parent)
	: QWidget(parent)
{
	_ui = std::make_unique<Ui_OptionsPageBuildPrograms>();

	_ui->setupUi(this);
}

OptionsPageBuildPrograms::~OptionsPageBuildPrograms() = default;
