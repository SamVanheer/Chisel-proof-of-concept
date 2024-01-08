#pragma once

#include <memory>

#include <QWidget>

class Ui_OptionsPageGameConfigurations;

class OptionsPageGameConfigurations final : public QWidget
{
public:
	explicit OptionsPageGameConfigurations(QWidget* parent = nullptr);
	~OptionsPageGameConfigurations();

private:
	std::unique_ptr<Ui_OptionsPageGameConfigurations> _ui;
};
