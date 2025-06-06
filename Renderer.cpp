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
, ScaleX(1)
, ScaleY(1)
, CharacterMap(characterMap)
, Symbols(symbolsMap)
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
void Renderer<N>::RenderSegment(SegmentsGlyph<N> character, int segmentIndex, int scaledRowIndex)
{
    bool isSegmentOn = character.Segments[segmentIndex] == 1;
    SegmentSymbol segment = Symbols.at(segmentIndex);
    int charCounter = ScaleX - 2;

    std::string leftChar = isSegmentOn ? segment.PrintedCharacters : segment.NonprintedCharacters;
    std::string rightChar = isSegmentOn ? segment.PrintedCharacters : segment.NonprintedCharacters;
    std::string midChar = isSegmentOn ? segment.PrintedCharacters : segment.NonprintedCharacters;

    if(scaledRowIndex + 1 < ScaleY && segment.SymbolPosition == BOTTOM
        || scaledRowIndex > 0 && segment.SymbolPosition == TOP)
    {
        leftChar = segment.NonprintedCharacters;
        midChar = segment.NonprintedCharacters;
        rightChar = segment.NonprintedCharacters;
    }
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
    constexpr uchar UNKNOWN_CHAR_GLYPH = '?';

    cout << "Rendering: '" << inputString << "' ";
    cout << "(" << Name << ") ";
    cout << "Scale: x=" << ScaleX << ", y=" << ScaleY << endl;
    
    for(int row = 0; row < Height; ++row)
    {
        for(int scaledRowIndex = 0; scaledRowIndex < ScaleY; scaledRowIndex++)
        {
            for(int pos = 0; pos < inputString.length(); ++pos)
            {
                char ch = inputString[pos];
                if(CharacterMap.find(ch) != CharacterMap.end())
                {
                    RenderCharacterRow(ch, row, scaledRowIndex);
                }
                else
                {
                    RenderCharacterRow(UNKNOWN_CHAR_GLYPH, row, scaledRowIndex);
                }
            }
            RenderLineEnd(row, scaledRowIndex);
        }
    }

    RenderDebugLine(inputString, Width, Spacing);
}

template<int N>
void Renderer<N>::RenderCharacterRow(char ch, int rowIndex, int scaledRowIndex)
{
    BaseGlyphWithStrings character = BaseCharacterMap.at(ch);
    cout << character.RowData[rowIndex];
}

template<int N>
void Renderer<N>::RenderLineEnd(int rowIndex, int scaledRowIndex)
{
    cout << endl;
}

template<int N>
void Renderer<N>::RenderDebugLine(const string& inputString, int characterWidth, int spacerWidth)
{
    // print the actual character below each rendered character (right aligned)
    for(int pos = 0; pos < inputString.length(); ++pos)
    {
        // width = 1: "x"
        // width = 2: "x "
        // width = 3: " x "
        // width = 4: " x  "
        // width = 5: "  x  "
        int width = (Width - 2) * ScaleX + 2;

        cout << inputString[pos]; // uncomment to left-align

        int paddingLeft = (width - 1) / 2;
        if(paddingLeft > 0) cout << string(paddingLeft, ' ');

        //cout << inputString[pos]; // uncomment to center-align

        int paddingRight = width - 1 - paddingLeft;
        if(paddingRight > 0) cout << string(paddingRight, ' ');

        //cout << inputString[pos]; // uncomment to right-align
    }
    cout << endl << endl;
}

template class Renderer<0>;
template class Renderer<9>;
