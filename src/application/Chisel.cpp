#include <QApplication>
#include <QMessageBox>

#include "application/Chisel.hpp"

#include "ui/MainWindow.hpp"

Chisel::Chisel() = default;
Chisel::~Chisel() = default;

int Chisel::Run(int argc, char** argv)
{
	QApplication app{argc, argv};

	QMessageBox::critical(nullptr, "You must acknowledge this", R"(This is a proof-of-concept that is non-functional.

It exists purely to show that building a Qt-based user interface for Hammer is feasible, not as the start of development for a Hammer clone.)");

	auto mainWindow = new MainWindow();

	mainWindow->show();

	return app.exec();
}
