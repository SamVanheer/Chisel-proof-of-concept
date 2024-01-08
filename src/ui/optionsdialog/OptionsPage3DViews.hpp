#pragma once

#include <memory>

#include <QWidget>

class Ui_OptionsPage3DViews;

class OptionsPage3DViews final : public QWidget
{
public:
	explicit OptionsPage3DViews(QWidget* parent = nullptr);
	~OptionsPage3DViews();

private:
	std::unique_ptr<Ui_OptionsPage3DViews> _ui;
};
