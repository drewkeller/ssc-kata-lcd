#include "SegmentsStringRenderer.h"

map<char, SegmentsCharacter> SegmentsCharacterLookup = {
    //       ------- SEGMENTS --------
    //       0  1  2  3  4  5  6  7  8
    { '0', { 1, 1, 1, 1, 0, 1, 1, 1, 1 } },
    { '1', { 0, 0, 1, 0, 0, 1, 0, 1, 0 } },
    { '2', { 1, 0, 1, 0, 1, 0, 1, 0, 1 } },
    { '3', { 1, 0, 1, 0, 1, 0, 0, 1, 1 } },
    { '4', { 0, 1, 1, 0, 1, 0, 0, 1, 0 } },
    { '5', { 1, 1, 0, 0, 1, 0, 0, 1, 1 } },
    { '6', { 1, 1, 0, 0, 1, 0, 1, 1, 1 } },
    { '7', { 1, 0, 1, 0, 0, 1, 0, 1, 0 } },
    { '8', { 1, 1, 1, 0, 1, 0, 1, 1, 1 } },
    { '9', { 1, 1, 1, 0, 1, 0, 0, 1, 1 } },
};

map<int, SegmentCharacter> SegmentCharacters = {
    { 0, { "----", "    " } },
    { 1, { "|", " " } }, 
    { 2, { "|", " " } },
    { 3, { "|", " " } }, 
    { 4, { "----", "    " } }, 
    { 5, { "|", " " } },
    { 6, { "|", " " } }, 
    { 7, { "|", " " } },
    { 8, { "----", "    " } },
};

void SegmentsStringRenderer::RenderSegment(SegmentsCharacter character, int segment)
{
    if(character.Segments[segment] == 0)
    {
        cout << SegmentCharacters[segment].NonprintedCharacters;
    } 
    else if(character.Segments[segment] == 1)
    {                    
        cout << SegmentCharacters[segment].PrintedCharacters;
    }
}

void SegmentsStringRenderer::RenderLeftColumnSpace()
{
    cout << " ";
}

void SegmentsStringRenderer::RenderMiddleColumnSpace()
{
    cout << "    ";
}

void SegmentsStringRenderer::RenderRightColumnSpace()
{
    cout << " ";
}

void SegmentsStringRenderer::RenderString(string inputString)
{
    const string& spacer = "   "; // need some space between characters for readability
    
    cout << "Rendering: '" << inputString << "'" << endl;
    for(int row = 0; row < CHARACTER_ROW_COUNT; ++row)
    {
        for(int pos = 0; pos < inputString.length(); ++pos)
        {
            char ch = inputString[pos];
            SegmentsCharacter character = SegmentsCharacterLookup.at(ch);
            if(row == 0)
            {
                RenderLeftColumnSpace();
                RenderSegment(character, 0);
                RenderRightColumnSpace();
            }
            else if (row == 1) {
                RenderSegment(character, 1);
                RenderMiddleColumnSpace();
                RenderSegment(character, 2);
            }
            else if (row == 2)
            {
                RenderSegment(character, 3);
                RenderSegment(character, 4);
                RenderSegment(character, 5);
            }
            else if (row == 3) {
                RenderSegment(character, 6);
                RenderMiddleColumnSpace();
                RenderSegment(character, 7);
            }
            else if(row == 4)
            {
                RenderLeftColumnSpace();
                RenderSegment(character, 8);
                RenderRightColumnSpace();
            }
            cout << spacer;
        }
        cout << endl;
    }

    // print the actual character below each rendered character (right aligned)
    for(int pos = 0; pos < inputString.length(); ++pos)
    {
        for(int space = 0; space < CHARACTERS_IN_ROW_COUNT - 1; ++space)
        {
            cout << " ";
        }
        cout << inputString[pos];
        cout << spacer;
    }
    cout << endl;
}

