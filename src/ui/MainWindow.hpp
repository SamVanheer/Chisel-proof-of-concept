#pragma once

#include <memory>

#include <QMainWindow>

class QMdiArea;
class Ui_MainWindow;

class MainWindow final : public QMainWindow
{
public:
	explicit MainWindow();
	~MainWindow();

private slots:
	void OnNewFile();

private:
	std::unique_ptr<Ui_MainWindow> _ui;

	QMdiArea* _mdiArea{};
};
