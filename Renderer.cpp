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
: Renderer<0>(DummySegmentsCharacterMap, BASE_HEIGHT, BASE_WIDTH, DummySymbolsMap)
{
}

template<int N>
Renderer<N>::Renderer(const std::map<char,SegmentsGlyph<N>>& characterMap, const int height, const int width, const SymbolsMap & symbolsMap)
: Height(height)
, Width(width)
, Symbols(symbolsMap)
{
}

template<int N>
void Renderer<N>::RenderSegment(SegmentsGlyph<N> character, int segment)
{
    if(character.Segments[segment] == 0)
    {
        std::cout << Symbols.at(segment).NonprintedCharacters;
    } 
    else if(character.Segments[segment] == 1)
    {                    
        std::cout << Symbols.at(segment).PrintedCharacters;
    }
}

template<int N>
void Renderer<N>::RenderString(const string& inputString)
{
    const string& spacer = "   "; // need some space between characters for readability
    
    cout << "Rendering: '" << inputString << "'" << endl;
    for(int row = 0; row < Height; ++row)
    {
        for(int pos = 0; pos < inputString.length(); ++pos)
        {
            char ch = inputString[pos];
            RenderCharacterRow(ch, row);
            cout << spacer;
        }
        cout << endl;
    }

    RenderDebugLine(inputString, Width, spacer.length());
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
        for(int space = 0; space < characterWidth - 1; ++space)
        {
            cout << " ";
        }
        
        cout << inputString[pos];

        // print space between rendered characters
        for(int space = 0; space < spacerWidth; ++space)
        {
            cout << " ";
        }
    }
    cout << endl;
}

template class Renderer<0>;
template class Renderer<9>;
