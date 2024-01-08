#pragma once

#include <memory>

#include <QWidget>

class Ui_VisGroupsDock;

class VisGroupsDock final : public QWidget
{
public:
	explicit VisGroupsDock(QWidget* parent = nullptr);
	~VisGroupsDock();

private:
	std::unique_ptr<Ui_VisGroupsDock> _ui;
};
