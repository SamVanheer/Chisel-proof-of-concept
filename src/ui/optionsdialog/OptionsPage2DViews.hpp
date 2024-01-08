#pragma once

#include <memory>

#include <QWidget>

class Ui_OptionsPage2DViews;

class OptionsPage2DViews final : public QWidget
{
public:
	explicit OptionsPage2DViews(QWidget* parent = nullptr);
	~OptionsPage2DViews();

private:
	std::unique_ptr<Ui_OptionsPage2DViews> _ui;
};
