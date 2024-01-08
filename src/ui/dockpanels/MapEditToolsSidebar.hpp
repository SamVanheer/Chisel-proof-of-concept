#pragma once

#include <memory>

#include <QList>
#include <QWidget>

class FaceEditDialog;
class QToolButton;
class Ui_MapEditToolsSidebar;

class MapEditToolsSidebar final : public QWidget
{
public:
	explicit MapEditToolsSidebar(QWidget* parent = nullptr);
	~MapEditToolsSidebar();

private slots:
	void OnToolClicked();

private:
	void DepressToolButtons(QToolButton* activator);

private:
	std::unique_ptr<Ui_MapEditToolsSidebar> _ui;

	QList<QToolButton*> _toolButtons;

	FaceEditDialog* _faceEditDialog{};

	bool _depressingButtons{ false };
};
