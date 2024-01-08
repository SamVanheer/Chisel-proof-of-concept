target_sources(Chisel
	PRIVATE
		MainWindow.cpp
		MainWindow.hpp
		MainWindow.ui)

add_subdirectory(dialogs)
add_subdirectory(dockpanels)
add_subdirectory(optionsdialog)
add_subdirectory(viewports)
