#pragma once

#include <memory>

#include <QWidget>

class Ui_OptionsPageTextures;

class OptionsPageTextures final : public QWidget
{
public:
	explicit OptionsPageTextures(QWidget* parent = nullptr);
	~OptionsPageTextures();

private:
	std::unique_ptr<Ui_OptionsPageTextures> _ui;
};
