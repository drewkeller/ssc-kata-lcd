#pragma once

#include "common.h"

struct Character
{
    string RowData[CHARACTER_ROW_COUNT];
};

class Renderer
{
public:
    void RenderString(string inputString);
};
