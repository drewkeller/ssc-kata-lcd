#pragma once

#include "common.h"
#include <string>

struct Character
{
    std::string RowData[CHARACTER_ROW_COUNT];
};

class Renderer
{
public:
    void RenderString(std::string inputString);
};
