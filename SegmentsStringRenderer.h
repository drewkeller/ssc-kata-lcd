#pragma once

#include "common.h"

constexpr int SEGMENTS_COUNT = 9;
struct SegmentsCharacter
{
    int Segments[SEGMENTS_COUNT];
};

struct SegmentCharacter
{
    string PrintedCharacters;
    string NonprintedCharacters;
};

class SegmentsStringRenderer
{
    public:
    void RenderString(string inputString);
    void RenderSegment(SegmentsCharacter character, int segment);
    void RenderLeftColumnSpace();
    void RenderMiddleColumnSpace();
    void RenderRightColumnSpace();
};
