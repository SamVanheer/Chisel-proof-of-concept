#include "ui_FaceEditDialog.h"

#include "ui/dialogs/FaceEditDialog.hpp"

FaceEditDialog::FaceEditDialog(QWidget* parent)
	: QDialog(parent)
{
	_ui = std::make_unique<Ui_FaceEditDialog>();

	_ui->setupUi(this);

	// Add inset border to match shaded border used in Hammer.
	_ui->TextureWidget->setStyleSheet(R"|(
border-style: inset;
border-width: 1px;
border-color: gray silver silver gray;
)|");
}

FaceEditDialog::~FaceEditDialog() = default;

void FaceEditDialog::closeEvent(QCloseEvent*)
{
	emit Closing();
}
