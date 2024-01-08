#include "ui_MapEditToolsSidebar.h"

#include "ui/dialogs/FaceEditDialog.hpp"
#include "ui/dockpanels/MapEditToolsSidebar.hpp"

MapEditToolsSidebar::MapEditToolsSidebar(QWidget* parent)
{
	_ui = std::make_unique<Ui_MapEditToolsSidebar>();

	_ui->setupUi(this);

	_toolButtons = this->findChildren<QToolButton*>();

	for (auto button : _toolButtons)
	{
		if (button == _ui->FaceEdit)
		{
			continue;
		}

		connect(button, &QToolButton::clicked, this, &MapEditToolsSidebar::OnToolClicked);
	}

	connect(_ui->FaceEdit, &QToolButton::clicked, this, [this](bool checked)
		{
			if (!_faceEditDialog)
			{
				_faceEditDialog = new FaceEditDialog(topLevelWidget());

				connect(_faceEditDialog, &FaceEditDialog::Closing, this, [this]
					{
						if (_ui->FaceEdit->isChecked())
						{
							_ui->FaceEdit->click();
						}
					});
			}

			_faceEditDialog->setVisible(checked);

			if (checked)
			{
				DepressToolButtons(_ui->FaceEdit);
			}
		});
}

MapEditToolsSidebar::~MapEditToolsSidebar() = default;

void MapEditToolsSidebar::OnToolClicked()
{
	if (_depressingButtons)
	{
		return;
	}

	auto activator = static_cast<QToolButton*>(sender());

	// Don't allow tools to be deselected.
	if (!activator->isChecked())
	{
		activator->setChecked(true);
		return;
	}

	DepressToolButtons(activator);
}

void MapEditToolsSidebar::DepressToolButtons(QToolButton* activator)
{
	_depressingButtons = true;

	for (auto button : _toolButtons)
	{
		if (button != activator && button->isChecked())
		{
			// Make sure to emit signals as well.
			button->click();
		}
	}

	_depressingButtons = false;
}
