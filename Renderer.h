#pragma once

#include "common.h"
#include <map>
#include <string>

constexpr int BASE_HEIGHT = 5;
constexpr int BASE_WIDTH = 6;
constexpr int BASE_SPACING = 3;

struct BaseGlyphWithStrings
{
    std::string RowData[BASE_HEIGHT];
};

template <int N>
struct SegmentsGlyph
{
    int Segments[N];
};

enum SymbolPosition {
    TOP, LEFT, RIGHT, BOTTOM
};

struct SegmentSymbol
{
    std::string PrintedCharacters;
    std::string NonprintedCharacters;
    SymbolPosition SymbolPosition;
};

using SymbolsMap = std::map<int, SegmentSymbol>;

template <int N>
class Renderer
{
public:
    std::string Name;
    int Height;
    int Width;
    int Spacing;
    int ScaleX;
    int ScaleY;
    const std::map<char, SegmentsGlyph<N> > CharacterMap;
    const SymbolsMap& Symbols;
    Renderer();
    Renderer(const std::map<char, SegmentsGlyph<N> >& characterMap, const int height, const int width, const int spacing, const SymbolsMap& symbolsMap);
    virtual void RenderString(const std::string& inputString);
    virtual void RenderCharacterRow(char ch, int rowIndex, int scaledRowIndex);
    virtual void RenderLineEnd(int rowIndex, int scaledRowIndex);
    virtual void RenderDebugLine(const std::string& inputString, int characterWidth, int spacerWidth);

    Renderer<N>& SetScale(int scaleX, int scaleY);
    void RenderSegment(SegmentsGlyph<N> character, int segment, int scaledRowIndex);
};
