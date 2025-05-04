#pragma once

#include "common.h"
#include <map>
#include <string>

constexpr int BASE_HEIGHT = 5;
constexpr int BASE_WIDTH = 6;

struct BaseGlyphWithStrings
{
    std::string RowData[BASE_HEIGHT];
};

template <int N>
struct SegmentsGlyph
{
    int Segments[N];
};

struct SegmentSymbol
{
    std::string PrintedCharacters;
    std::string NonprintedCharacters;
};

using SymbolsMap = std::map<int, SegmentSymbol>;

template <int N>
class Renderer
{
public:
    int Height;
    int Width;
    const std::map<char, SegmentsGlyph<N> > CharacterMap;
    const SymbolsMap& Symbols;
    Renderer();
    Renderer(const std::map<char, SegmentsGlyph<N> >& characterMap, const int height, const int width, const SymbolsMap& symbolsMap);
    virtual void RenderString(const std::string& inputString);
    virtual void RenderCharacterRow(char ch, int rowIndex);
    virtual void RenderDebugLine(const std::string& inputString, int characterWidth, int spacerWidth);

    void RenderSegment(SegmentsGlyph<N> character, int segment);
};
