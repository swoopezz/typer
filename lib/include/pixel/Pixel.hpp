#pragma once

namespace tui {
struct Pixel {
	char pixelContent = ' ';
	bool isBold   = 0;
	bool isItal   = 0;
	bool isInvert = 0;
	bool isUnderl = 0;

	Pixel() = default;
	Pixel(const char content) : pixelContent(content) {}	
};
} // namespace
