#pragma once

#include "Renderer.h"

constexpr int NINE_SEGMENTS_COUNT = 9;

using NineSegmentGlyph = SegmentsGlyph<NINE_SEGMENTS_COUNT>;

class NineSegmentRenderer : public Renderer<NINE_SEGMENTS_COUNT>
{
    public:
    NineSegmentRenderer();
    virtual void RenderCharacterRow(char ch, int rowIndex) override;
    void RenderLeftColumnSpace();
    void RenderMiddleColumnSpace();
    void RenderRightColumnSpace();
};
