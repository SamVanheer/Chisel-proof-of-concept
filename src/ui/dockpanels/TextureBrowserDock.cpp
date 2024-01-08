#include "ui_TextureBrowserDock.h"

#include "ui/dialogs/TextureBrowserDialog.hpp"
#include "ui/dockpanels/TextureBrowserDock.hpp"

TextureBrowserDock::TextureBrowserDock(QWidget* parent)
{
	_ui = std::make_unique<Ui_TextureBrowserDock>();

	_ui->setupUi(this);

	// Add inset border to match shaded border used in Hammer.
	_ui->TextureWidget->setStyleSheet(R"|(
border-style: inset;
border-width: 1px;
border-color: gray silver silver gray;
)|");

	connect(_ui->BrowseTexture, &QPushButton::clicked, this, [this]
		{
			TextureBrowserDialog dialog{this->topLevelWidget()};

			dialog.exec();
		});
}

TextureBrowserDock::~TextureBrowserDock() = default;
