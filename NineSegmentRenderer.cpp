#include "NineSegmentRenderer.h"
#include <iostream>
#include <map>

using namespace std;

constexpr int NINE_SEG_RENDERER_HEIGHT = 5;
constexpr int NINE_SEG_RENDERER_WIDTH = 6;
constexpr int NINE_SEG_SPACING = 3;

map<char, NineSegmentGlyph> NineSegmentsCharacterMap = {
    //       ------- SEGMENTS --------
    //       0  1  2  3  4  5  6  7  8
    { '0', { 1, 1, 1, 1, 0, 1, 1, 1, 1 } },
    { '1', { 0, 0, 1, 0, 0, 1, 0, 1, 0 } },
    { '2', { 1, 0, 1, 0, 1, 0, 1, 0, 1 } },
    { '3', { 1, 0, 1, 0, 1, 0, 0, 1, 1 } },
    { '4', { 0, 1, 1, 0, 1, 0, 0, 1, 0 } },
    { '5', { 1, 1, 0, 0, 1, 0, 0, 1, 1 } },
    { '6', { 1, 1, 0, 0, 1, 0, 1, 1, 1 } },
    { '7', { 1, 0, 1, 0, 0, 1, 0, 1, 0 } },
    { '8', { 1, 1, 1, 0, 1, 0, 1, 1, 1 } },
    { '9', { 1, 1, 1, 0, 1, 0, 0, 1, 1 } },
};

SymbolsMap NineSegmentSymbolsMap = {
    { 0, { "----", "    ", TOP } },
    { 1, { "|",    " ",    LEFT } }, 
    { 2, { "|",    " ",    RIGHT } },
    { 3, { "|",    " ",    LEFT } }, 
    { 4, { "----", "    ", BOTTOM } }, 
    { 5, { "|",    " ",    RIGHT } },
    { 6, { "|",    " ",    LEFT } }, 
    { 7, { "|",    " ",    RIGHT } },
    { 8, { "----", "    ", BOTTOM } },
};

NineSegmentRenderer::NineSegmentRenderer()
: Renderer(NineSegmentsCharacterMap, NINE_SEG_RENDERER_HEIGHT, NINE_SEG_RENDERER_WIDTH, NINE_SEG_SPACING, NineSegmentSymbolsMap)
{
    Name = "NineSegment";
}

void NineSegmentRenderer::RenderLeftColumnSpace()
{
    cout << " ";
}

void NineSegmentRenderer::RenderMiddleColumnSpace()
{
    for(int posX = 1; posX <= ScaleX; posX++)
    {
        cout << "    ";
    }
}

void NineSegmentRenderer::RenderRightColumnSpace()
{
    cout << " ";
}

void NineSegmentRenderer::RenderCharacterRow(char ch, int rowIndex)
{
    NineSegmentGlyph character = NineSegmentsCharacterMap.at(ch);
    if(rowIndex == 0)
    {
        RenderLeftColumnSpace();
        RenderSegment(character, 0);
        RenderRightColumnSpace();
    }
    else if (rowIndex == 1) {
        RenderSegment(character, 1);
        RenderMiddleColumnSpace();
        RenderSegment(character, 2);
    }
    else if (rowIndex == 2)
    {
        RenderSegment(character, 3);
        RenderSegment(character, 4);
        RenderSegment(character, 5);
    }
    else if (rowIndex == 3) {
        RenderSegment(character, 6);
        RenderMiddleColumnSpace();
        RenderSegment(character, 7);
    }
    else if(rowIndex == 4)
    {
        RenderLeftColumnSpace();
        RenderSegment(character, 8);
        RenderRightColumnSpace();
    }
}

