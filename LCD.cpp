#include "common.h"
#include "Renderer.h"
#include "NineSegmentRenderer.h"
#include <Windows.h>

int main(int argc, char* argv[])
{
    // see https://stackoverflow.com/questions/45575863/how-to-print-utf-8-strings-to-stdcout-on-windows
    SetConsoleOutputCP(CP_UTF8);
    setvbuf(stdout, nullptr, _IOFBF, 1000);

    Renderer<0> renderer;
    renderer.RenderString("0123456789");

    NineSegmentRenderer segmentsRenderer;
    segmentsRenderer.RenderString("0123456789");

    return 0;
}
