#include "ui_OptionsPageTextures.h"

#include "ui/optionsdialog/OptionsPageTextures.hpp"

OptionsPageTextures::OptionsPageTextures(QWidget* parent)
	: QWidget(parent)
{
	_ui = std::make_unique<Ui_OptionsPageTextures>();

	_ui->setupUi(this);
}

OptionsPageTextures::~OptionsPageTextures() = default;
