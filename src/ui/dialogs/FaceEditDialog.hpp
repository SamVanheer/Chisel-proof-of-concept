#pragma once

#include <QDialog>

class Ui_FaceEditDialog;

class FaceEditDialog final : public QDialog
{
	Q_OBJECT

public:
	explicit FaceEditDialog(QWidget* parent = nullptr);
	~FaceEditDialog();

signals:
	void Closing();

protected:
	void closeEvent(QCloseEvent*);

private:
	std::unique_ptr<Ui_FaceEditDialog> _ui;
};
