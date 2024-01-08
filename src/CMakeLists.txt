if (MSVC)
	target_sources(Chisel PRIVATE chisel.rc version.rc)
endif()

target_sources(Chisel
	PRIVATE
		Main.cpp)

add_subdirectory(application)
add_subdirectory(ui)
