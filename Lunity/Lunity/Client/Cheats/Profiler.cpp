#include "pch.h"
#include "Profiler.h"
#include "../../SDK/DrawUtils.h"
#include <chrono>
#include <string>



using namespace std;
using namespace std::chrono;

static std::chrono::time_point<std::chrono::steady_clock> savedTime;
static std::chrono::time_point<std::chrono::steady_clock> lastSecond;

long longestFrame = 0;
long shortestFrame = 9999;

long frameCount = 0;
long actualFps = 0;
long lastFrameCount = 0;

Profiler::Profiler() : Cheat::Cheat("Profiler", "Other")
{
}

void Profiler::onEnable() {
	savedTime = high_resolution_clock::now();
	lastSecond = high_resolution_clock::now();
	longestFrame = 0;
	shortestFrame = 9999;
}

void Profiler::onPostRender() {
	if (enabled) {
		auto stop = high_resolution_clock::now();

		auto frameTime = duration_cast<microseconds>(stop - savedTime);

		auto lastSecTime = duration_cast<microseconds>(stop - lastSecond);

		if (lastSecTime.count() >= 1000000) {
			actualFps = frameCount - lastFrameCount;
			lastFrameCount = frameCount;
			lastSecond = high_resolution_clock::now();
		}

		GuiData* GuiData = LunMem::getClientInstance()->getGuiData();
		Vector2 ScreenRes = GuiData->ScaledResolution;

		long time = frameTime.count();

		if (longestFrame < time) {
			longestFrame = time;
		}
		if (shortestFrame > time) {
			shortestFrame = time;
		}

		string frameTimeStrUs = to_string(time) + string(" us/frame");
		float textSize = DrawUtils::getTextWidth(frameTimeStrUs, 1);
		DrawUtils::fillRectangle(Vector4(0, ScreenRes.y - 10, textSize, ScreenRes.y), Color(0, 0, 0, 1), 0.2f);
		DrawUtils::drawText(Vector2(0, ScreenRes.y - 10), &frameTimeStrUs, nullptr, 1);

		string frameTimeStrMs = to_string(time / 1000) + string(" ms/frame");
		textSize = DrawUtils::getTextWidth(frameTimeStrMs, 1);
		DrawUtils::fillRectangle(Vector4(0, ScreenRes.y - 20, textSize, ScreenRes.y-10), Color(0, 0, 0, 1), 0.2f);
		DrawUtils::drawText(Vector2(0, ScreenRes.y - 20), &frameTimeStrMs, nullptr, 1);

		string longestTimeStrUs = to_string(longestFrame) + string(" longest frame (us)");
		textSize = DrawUtils::getTextWidth(longestTimeStrUs, 1);
		DrawUtils::fillRectangle(Vector4(0, ScreenRes.y - 30, textSize, ScreenRes.y - 20), Color(0, 0, 0, 1), 0.2f);
		DrawUtils::drawText(Vector2(0, ScreenRes.y - 30), &longestTimeStrUs, nullptr, 1);

		string shortestFrameStrUs = to_string(shortestFrame) + string(" shortest frame (us)");
		textSize = DrawUtils::getTextWidth(shortestFrameStrUs, 1);
		DrawUtils::fillRectangle(Vector4(0, ScreenRes.y - 40, textSize, ScreenRes.y - 30), Color(0, 0, 0, 1), 0.2f);
		DrawUtils::drawText(Vector2(0, ScreenRes.y - 40), &shortestFrameStrUs, nullptr, 1);

		long timeMs = (time / 1000);
		string fpsStr;
		if (timeMs < 1) {
			fpsStr = "divide by 0 error";
		}
		else {
			fpsStr = to_string(1000 / timeMs) + string(" calculated fps");
		}
		textSize = DrawUtils::getTextWidth(fpsStr, 1);
		DrawUtils::fillRectangle(Vector4(0, ScreenRes.y - 50, textSize, ScreenRes.y - 40), Color(0, 0, 0, 1), 0.2f);
		DrawUtils::drawText(Vector2(0, ScreenRes.y - 50), &fpsStr, nullptr, 1);

		string actualFpsStr = to_string(actualFps) + string(" actual fps");
		textSize = DrawUtils::getTextWidth(actualFpsStr, 1);
		DrawUtils::fillRectangle(Vector4(0, ScreenRes.y - 60, textSize, ScreenRes.y - 50), Color(0, 0, 0, 1), 0.2f);
		DrawUtils::drawText(Vector2(0, ScreenRes.y - 60), &actualFpsStr, nullptr, 1);

		string frameCountStr = to_string(frameCount) + string(" frames");
		textSize = DrawUtils::getTextWidth(frameCountStr, 1);
		DrawUtils::fillRectangle(Vector4(0, ScreenRes.y - 70, textSize, ScreenRes.y - 60), Color(0, 0, 0, 1), 0.2f);
		DrawUtils::drawText(Vector2(0, ScreenRes.y - 70), &frameCountStr, nullptr, 1);

		frameCount++;

		savedTime = stop;
	}
}