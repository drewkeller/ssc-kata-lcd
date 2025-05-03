#include "Renderer.h"

map<char, Character> CharacterLookup = {
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

void Renderer::RenderString(string inputString)
{
    const string& spacer = "   "; // need some space between characters for readability
    
    cout << "Rendering: '" << inputString << "'" << endl;
    for(int row = 0; row < CHARACTER_ROW_COUNT; ++row)
    {
        for(int pos = 0; pos < inputString.length(); ++pos)
        {
            char ch = inputString[pos];
            Character character = CharacterLookup.at(ch);
            cout << character.RowData[row];
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
