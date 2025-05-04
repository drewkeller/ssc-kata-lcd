#include "SevenSegmentRenderer.h"
#include <iostream>
#include <map>

using namespace std;

constexpr int SEVEN_SEG_RENDERER_HEIGHT = 3;
constexpr int SEVEN_SEG_RENDERER_WIDTH = 3;
constexpr int SEVEN_SEG_SPACING = 0;

map<char, SevenSegmentGlyph> SevenSegmentsCharacterMap = {
    //       ------- SEGMENTS --------
    //       0  1  2  3  4  5  6
    { '0', { 1, 1, 1, 0, 1, 1, 1 } },
    { '1', { 0, 0, 1, 0, 0, 1, 0 } },
    { '2', { 1, 0, 1, 1, 1, 0, 1 } },
    { '3', { 1, 0, 1, 1, 0, 1, 1 } },
    { '4', { 0, 1, 1, 1, 0, 1, 0 } },
    { '5', { 1, 1, 0, 1, 0, 1, 1 } },
    { '6', { 1, 1, 0, 1, 1, 1, 1 } },
    { '7', { 1, 0, 1, 0, 0, 1, 0 } },
    { '8', { 1, 1, 1, 1, 1, 1, 1 } },
    { '9', { 1, 1, 1, 1, 0, 1, 1 } },
};

SymbolsMap SevenSegmentSymbolsMap = {
    { 0, { " _ ", "   " } },
    { 1, { "|", " " } }, 
    { 2, { "|", " " } }, 
    { 3, { "_", " " } },
    { 4, { "|", " " } }, 
    { 5, { "|", " " } }, 
    { 6, { "_", " " } },
};

SevenSegmentRenderer::SevenSegmentRenderer()
: Renderer(SevenSegmentsCharacterMap, SEVEN_SEG_RENDERER_HEIGHT, SEVEN_SEG_RENDERER_WIDTH, SEVEN_SEG_SPACING, SevenSegmentSymbolsMap)
{}

void SevenSegmentRenderer::RenderCharacterRow(char ch, int rowIndex)
{
    SevenSegmentGlyph character = SevenSegmentsCharacterMap.at(ch);
    if(rowIndex == 0)
    {
        RenderSegment(character, 0);
    }
    else if (rowIndex == 1) {
        RenderSegment(character, 1);
        RenderSegment(character, 3);
        RenderSegment(character, 2);
    }
    else if (rowIndex == 2)
    {
        RenderSegment(character, 4);
        RenderSegment(character, 6);
        RenderSegment(character, 5);
    }
}

