#include "ui_TextureBrowserDialog.h"

#include "ui/dialogs/TextureBrowserDialog.hpp"
#include "ui/viewports/TextureBrowserViewport.hpp"

TextureBrowserDialog::TextureBrowserDialog(QWidget* parent)
	: QDialog(parent, Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint)
{
	_ui = std::make_unique<Ui_TextureBrowserDialog>();

	_ui->setupUi(this);

	auto viewport = new TextureBrowserViewport();

	_ui->ScrollArea->setWidget(viewport->GetContainer());
}

TextureBrowserDialog::~TextureBrowserDialog() = default;
