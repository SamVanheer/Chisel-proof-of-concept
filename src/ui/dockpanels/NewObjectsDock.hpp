#pragma once

#include <memory>

#include <QWidget>

class Ui_NewObjectsDock;

class NewObjectsDock final : public QWidget
{
public:
	explicit NewObjectsDock(QWidget* parent = nullptr);
	~NewObjectsDock();

private:
	std::unique_ptr<Ui_NewObjectsDock> _ui;
};
