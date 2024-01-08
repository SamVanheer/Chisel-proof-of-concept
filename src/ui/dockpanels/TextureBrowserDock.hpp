#pragma once

#include <memory>

#include <QWidget>

class Ui_TextureBrowserDock;

class TextureBrowserDock final : public QWidget
{
public:
	explicit TextureBrowserDock(QWidget* parent = nullptr);
	~TextureBrowserDock();

private:
	std::unique_ptr<Ui_TextureBrowserDock> _ui;
};
