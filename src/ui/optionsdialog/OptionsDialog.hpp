#pragma once

#include <memory>

#include <QDialog>

class Ui_OptionsDialog;

class OptionsDialog final : public QDialog
{
public:
	explicit OptionsDialog(QWidget* parent = nullptr);
	~OptionsDialog();

private:
	std::unique_ptr<Ui_OptionsDialog> _ui;
};
