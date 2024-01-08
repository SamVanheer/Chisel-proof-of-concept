#pragma once

#include <QDialog>

class Ui_TextureBrowserDialog;

class TextureBrowserDialog final : public QDialog
{
public:
	explicit TextureBrowserDialog(QWidget* parent = nullptr);
	~TextureBrowserDialog();

private:
	std::unique_ptr<Ui_TextureBrowserDialog> _ui;
};
