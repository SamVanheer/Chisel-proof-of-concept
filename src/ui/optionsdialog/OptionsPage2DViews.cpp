#include "ui_OptionsPage2DViews.h"

#include "ui/optionsdialog/OptionsPage2DViews.hpp"

OptionsPage2DViews::OptionsPage2DViews(QWidget* parent)
	: QWidget(parent)
{
	_ui = std::make_unique<Ui_OptionsPage2DViews>();

	_ui->setupUi(this);

	for (int size = 4; size <= 256; size <<= 1)
	{
		_ui->GridSize->addItem(QString::number(size), QVariant::fromValue(size));
	}

	_ui->GridSize->setCurrentIndex(4); // 64
}

OptionsPage2DViews::~OptionsPage2DViews() = default;
