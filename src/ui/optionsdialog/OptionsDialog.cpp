#include "ui_OptionsDialog.h"

#include "ui/optionsdialog/OptionsDialog.hpp"
#include "ui/optionsdialog/OptionsPage2DViews.hpp"
#include "ui/optionsdialog/OptionsPage3DViews.hpp"
#include "ui/optionsdialog/OptionsPageBuildPrograms.hpp"
#include "ui/optionsdialog/OptionsPageGameConfigurations.hpp"
#include "ui/optionsdialog/OptionsPageGeneral.hpp"
#include "ui/optionsdialog/OptionsPageTextures.hpp"

OptionsDialog::OptionsDialog(QWidget* parent)
	: QDialog(parent)
{
	_ui = std::make_unique<Ui_OptionsDialog>();

	_ui->setupUi(this);

	_ui->Tabs->addTab(new OptionsPageGeneral(), "General");
	_ui->Tabs->addTab(new OptionsPage2DViews(), "2D Views");
	_ui->Tabs->addTab(new OptionsPage3DViews(), "3D Views");
	_ui->Tabs->addTab(new OptionsPageTextures(), "Textures");
	_ui->Tabs->addTab(new OptionsPageGameConfigurations(), "Game Configurations");
	_ui->Tabs->addTab(new OptionsPageBuildPrograms(), "Build Programs");
}

OptionsDialog::~OptionsDialog() = default;
