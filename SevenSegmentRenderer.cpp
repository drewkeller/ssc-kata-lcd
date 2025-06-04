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
    { ' ', { 0, 0, 0, 0, 0, 0, 0 } },
    { 'd', { 0, 0, 1, 1, 1, 1, 1 } },
    { 'e', { 1, 1, 0, 1, 1, 0, 1 } },
    { 'h', { 0, 1, 0, 1, 1, 1, 0 } },
    { 'l', { 0, 1, 0, 0, 1, 0, 1 } },
    { 'o', { 0, 0, 0, 1, 1, 1, 1 } },
    { 'r', { 0, 0, 0, 1, 1, 0, 0 } },
    { 'w', { 0, 0, 0, 0, 1, 1, 1 } },
    { '?', { 0, 0, 0, 1, 0, 0, 0 } }, // (dash) output this for unknown characters
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

void SevenSegmentRenderer::RenderCharacterRow(char ch, int rowIndex, int scaledRowIndex)
{
    SevenSegmentGlyph character = SevenSegmentsCharacterMap.at(ch);
    if(rowIndex == 0)
    {
        // only print for the top iteration of the top row
        // to avoid printing empty lines
        if(scaledRowIndex == 0)
        {
            RenderSegment(character, BLANK_SEGMENT, scaledRowIndex);
            RenderSegment(character, 0, scaledRowIndex);
            RenderSegment(character, BLANK_SEGMENT, scaledRowIndex);
            cout << string(Spacing, ' ');
        }
    }
    else if (rowIndex == 1) {        
        RenderSegment(character, 1, scaledRowIndex);
        RenderSegment(character, 3, scaledRowIndex);
        RenderSegment(character, 2, scaledRowIndex);
        cout << string(Spacing, ' ');
    }
    else if (rowIndex == 2)
    {
        RenderSegment(character, 4, scaledRowIndex);
        RenderSegment(character, 6, scaledRowIndex);
        RenderSegment(character, 5, scaledRowIndex);
        cout << string(Spacing, ' ');
    }
}

void SevenSegmentRenderer::RenderLineEnd(int rowIndex, int scaledRowIndex)
{
    // suppress newlines if we're on the top row, unless it's the top iteration of the top row
    if(rowIndex > 0 || scaledRowIndex == 0)
    {
        cout << endl;
    }
}
