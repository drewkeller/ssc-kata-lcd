#include "common.h"
#include "Renderer.h"
#include "SevenSegmentRenderer.h"
#include "NineSegmentRenderer.h"
#include <Windows.h>

int main(int argc, char* argv[])
{
    // see https://stackoverflow.com/questions/45575863/how-to-print-utf-8-strings-to-stdcout-on-windows
    SetConsoleOutputCP(CP_UTF8);
    setvbuf(stdout, nullptr, _IOFBF, 1000);

    std::string testString = "0123456789";

    // Renderer<0> renderer;
    // renderer.RenderString(testString);

    NineSegmentRenderer nineSegmentsRenderer;
    nineSegmentsRenderer.RenderString(testString);
    nineSegmentsRenderer.SetScale(1, 2).RenderString(testString);
    nineSegmentsRenderer.SetScale(2, 2).RenderString(testString);

    SevenSegmentRenderer sevenSegmentsRenderer;
    sevenSegmentsRenderer.RenderString(testString);
    sevenSegmentsRenderer.SetScale(2, 1).RenderString(testString);
    sevenSegmentsRenderer.SetScale(3, 1).RenderString(testString);
    sevenSegmentsRenderer.SetScale(1, 2).RenderString(testString);
    sevenSegmentsRenderer.SetScale(1, 3).RenderString(testString);
    sevenSegmentsRenderer.SetScale(5, 3).RenderString(testString);

    sevenSegmentsRenderer.SetScale(1, 1).RenderString("hello, world");
    nineSegmentsRenderer.SetScale(1, 1).RenderString("hello, world");

    return 0;
}
