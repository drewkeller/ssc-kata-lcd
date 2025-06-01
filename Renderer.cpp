#include "Renderer.h"
#include <iostream>

using namespace std;

map<char, BaseGlyphWithStrings> BaseCharacterMap = {
    //        ROW1      ROW2      ROW3      ROW4       ROW5
    //        ------    ------    ------    ------     ----
    { '0', { " ---- ", "|    |", "|    |", "|    |", " ---- "} },
    { '1', { "      ", "     |", "     |", "     |", "      "} },
    { '2', { " ---- ", "     |", " ---- ", "|     ", " ---- "} },
    { '3', { " ---- ", "     |", " ---- ", "     |", " ---- "} },
    { '4', { "      ", "|    |", " ---- ", "     |", "      "} },
    { '5', { " ---- ", "|     ", " ---- ", "     |", " ---- "} },
    { '6', { " ---- ", "|     ", " ---- ", "|    |", " ---- "} },
    { '7', { " ---- ", "     |", "     |", "     |", "      "} },
    { '8', { " ---- ", "|    |", " ---- ", "|    |", " ---- "} },
    { '9', { " ---- ", "|    |", " ---- ", "     |", " ---- "} },
};

map<char, SegmentsGlyph<0> > DummySegmentsCharacterMap = {
    { '0', { } },
};

SymbolsMap DummySymbolsMap = {
    { 0, { "", "" } },
};

template<>
Renderer<0>::Renderer()
: Renderer<0>(DummySegmentsCharacterMap, BASE_HEIGHT, BASE_WIDTH, BASE_SPACING, DummySymbolsMap)
{
}

template<int N>
Renderer<N>::Renderer(const std::map<char,SegmentsGlyph<N>>& characterMap, const int height, const int width, const int spacing, const SymbolsMap & symbolsMap)
: Name("")
, Height(height)
, Width(width)
, Spacing(spacing)
, Symbols(symbolsMap)
, ScaleX(1)
, ScaleY(1)
{
}

template<int N>
Renderer<N>& Renderer<N>::SetScale(int scaleX, int scaleY)
{
    if(scaleX > 0 && scaleX <= 10 ) {
        ScaleX = scaleX;
    }
    if(scaleX > 0 && scaleX <= 10 ) {
        ScaleY = scaleY;
    }
    return *this;
}

template<int N>
void Renderer<N>::RenderSegment(SegmentsGlyph<N> character, int segmentIndex)
{
    bool isSegmentOn = character.Segments[segmentIndex] == 1;
    SegmentSymbol segment = Symbols.at(segmentIndex);
    int charCounter = ScaleX - 2;

    std::string leftChar = isSegmentOn ? segment.PrintedCharacters : segment.NonprintedCharacters;
    std::string rightChar = isSegmentOn ? segment.PrintedCharacters : segment.NonprintedCharacters;
    std::string midChar = isSegmentOn ? segment.PrintedCharacters : segment.NonprintedCharacters;

    if(ScaleX > 1 && segment.SymbolPosition == RIGHT) {
        leftChar = segment.NonprintedCharacters;
        midChar = segment.NonprintedCharacters;
    }
    if(ScaleX > 1 && segment.SymbolPosition == LEFT) {
        rightChar = segment.NonprintedCharacters;
        midChar = segment.NonprintedCharacters;
    }

    // render leftmost position
    if(segment.SymbolPosition == LEFT)
    {
        std::cout << leftChar;
    }

    // render middle characters
    if(segment.SymbolPosition == TOP || segment.SymbolPosition == BOTTOM)
    {
        for(int midChars = 1; midChars <= ScaleX; midChars++)
        {
            std::cout << midChar;
        }
    }

    // render rightmost position
    if(segment.SymbolPosition == RIGHT)
    {
        std::cout << rightChar;
    }
}

template<int N>
void Renderer<N>::RenderString(const string& inputString)
{
    cout << "Rendering: '" << inputString << "' ";
    cout << "(" << Name << ") ";
    cout << "Scale: x=" << ScaleX << ", y=" << ScaleY << endl;
    
    for(int row = 0; row < Height; ++row)
    {
        for(int pos = 0; pos < inputString.length(); ++pos)
        {
            char ch = inputString[pos];
            RenderCharacterRow(ch, row);
            cout << string(Spacing, ' ');
        }
        cout << endl;
    }

    RenderDebugLine(inputString, Width, Spacing);
}

template<int N>
void Renderer<N>::RenderCharacterRow(char ch, int rowIndex)
{
    BaseGlyphWithStrings character = BaseCharacterMap.at(ch);
    cout << character.RowData[rowIndex];
}

template<int N>
void Renderer<N>::RenderDebugLine(const string& inputString, int characterWidth, int spacerWidth)
{
    // print the actual character below each rendered character (right aligned)
    for(int pos = 0; pos < inputString.length(); ++pos)
    {
        // print across character width, leaving one position for the actual character
        int width = (Width - 2) * ScaleX + 2;
        if(width > 0) cout << string(width - 1, ' ');
        
        cout << inputString[pos];

        // print space between rendered characters
        cout << string(spacerWidth, ' ');
    }
    cout << endl;
}

template class Renderer<0>;
template class Renderer<9>;
