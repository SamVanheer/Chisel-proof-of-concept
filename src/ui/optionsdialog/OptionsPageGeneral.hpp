#pragma once

#include <memory>

#include <QWidget>

class Ui_OptionsPageGeneral;

class OptionsPageGeneral final : public QWidget
{
public:
	explicit OptionsPageGeneral(QWidget* parent = nullptr);
	~OptionsPageGeneral();

private:
	std::unique_ptr<Ui_OptionsPageGeneral> _ui;
};
