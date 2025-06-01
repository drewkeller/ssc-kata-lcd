#include "SevenSegmentRenderer.h"
#include <iostream>
#include <map>

using namespace std;

constexpr int SEVEN_SEG_RENDERER_HEIGHT = 3;
constexpr int SEVEN_SEG_RENDERER_WIDTH = 3;
constexpr int SEVEN_SEG_SPACING = 0;
constexpr int BLANK_SEGMENT = 0xFF;

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

constexpr bool H = true;  // Horizontal
constexpr bool V = false; // Vertical: !IsHorizontal
SymbolsMap SevenSegmentSymbolsMap = {
    { BLANK_SEGMENT, { " ", " ", LEFT }},
    { 0, { "_", " ", TOP } },
    { 1, { "|", " ", LEFT } }, 
    { 2, { "|", " ", RIGHT } }, 
    { 3, { "_", " ", BOTTOM } },
    { 4, { "|", " ", LEFT } }, 
    { 5, { "|", " ", RIGHT } }, 
    { 6, { "_", " ", BOTTOM } },
};

SevenSegmentRenderer::SevenSegmentRenderer()
: Renderer(SevenSegmentsCharacterMap, SEVEN_SEG_RENDERER_HEIGHT, SEVEN_SEG_RENDERER_WIDTH, SEVEN_SEG_SPACING, SevenSegmentSymbolsMap)
{
    Name = "SevenSegment";
}

void SevenSegmentRenderer::RenderCharacterRow(char ch, int rowIndex)
{
    SevenSegmentGlyph character = SevenSegmentsCharacterMap.at(ch);
    if(rowIndex == 0)
    {
        RenderSegment(character, BLANK_SEGMENT);
        RenderSegment(character, 0);
        RenderSegment(character, BLANK_SEGMENT);
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

