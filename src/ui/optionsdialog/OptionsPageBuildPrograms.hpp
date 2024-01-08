#pragma once

#include <memory>

#include <QWidget>

class Ui_OptionsPageBuildPrograms;

class OptionsPageBuildPrograms final : public QWidget
{
public:
	explicit OptionsPageBuildPrograms(QWidget* parent = nullptr);
	~OptionsPageBuildPrograms();

private:
	std::unique_ptr<Ui_OptionsPageBuildPrograms> _ui;
};
