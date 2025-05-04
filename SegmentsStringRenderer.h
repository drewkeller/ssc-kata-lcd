#pragma once

#include "common.h"
#include <string>

constexpr int SEGMENTS_COUNT = 9;
struct SegmentsCharacter
{
    int Segments[SEGMENTS_COUNT];
};

struct SegmentCharacter
{
    std::string PrintedCharacters;
    std::string NonprintedCharacters;
};

class SegmentsStringRenderer
{
    public:
    void RenderString(std::string inputString);
    void RenderSegment(SegmentsCharacter character, int segment);
    void RenderLeftColumnSpace();
    void RenderMiddleColumnSpace();
    void RenderRightColumnSpace();
};
