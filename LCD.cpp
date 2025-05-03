// setup: https://code.visualstudio.com/docs/cpp/config-msvc

#include "common.h"
#include "Renderer.h"
#include "SegmentsStringRenderer.h"
#include <Windows.h>

int main(int argc, char* argv[])
{
    // see https://stackoverflow.com/questions/45575863/how-to-print-utf-8-strings-to-stdcout-on-windows
    SetConsoleOutputCP(CP_UTF8);
    setvbuf(stdout, nullptr, _IOFBF, 1000);

    Renderer renderer;
    renderer.RenderString("0123456789");

    SegmentsStringRenderer segmentsRenderer;
    segmentsRenderer.RenderString("0123456789");

    return 0;
}
