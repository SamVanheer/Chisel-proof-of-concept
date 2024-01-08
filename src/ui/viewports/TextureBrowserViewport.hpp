#pragma once

#include "ui/viewports/Viewport3DWindow.hpp"

class TextureBrowserViewport : public Viewport3DWindow
{
protected:
	void paintGL() override;
};
