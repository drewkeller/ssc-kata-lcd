#pragma once

#include "Renderer.h"

constexpr int SEVEN_SEGMENTS_COUNT = 9;

using SevenSegmentGlyph = SegmentsGlyph<SEVEN_SEGMENTS_COUNT>;

class SevenSegmentRenderer : public Renderer<SEVEN_SEGMENTS_COUNT>
{
    public:
    SevenSegmentRenderer();
    virtual void RenderCharacterRow(char ch, int rowIndex) override;
};
