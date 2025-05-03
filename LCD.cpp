// setup: https://code.visualstudio.com/docs/cpp/config-msvc

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

typedef unsigned char uchar;

constexpr int CHARACTER_ROW_COUNT = 5;
constexpr int CHARACTERS_IN_ROW_COUNT = 6;

struct Character
{
    string RowData[CHARACTER_ROW_COUNT];
};

map<char, Character> CharacterLookup = {
    //        ROW1      ROW2      ROW3      ROW4       ROW5
    //        ------    ------    ------    ------     ----
    { '0', { " ---- ", "|    |", "|    |", "|    |", " ---- "} },
    { '1', { "      ", "     |", "     |", "     |", "      "} },
    { '2', { " ---- ", "     |", " ---- ", "|     ", " ---- "} },
    { '3', { " ---- ", "     |", " ---- ", "     |", " ---- "} },
    { '4', { "      ", "     |", " ---- ", "     |", "     |"} },
};

class Renderer
{
public:
    void RenderString(string inputString);
};
void Renderer::RenderString(string inputString)
{
    cout << inputString << endl;
    for(int row = 0; row < CHARACTER_ROW_COUNT; ++row)
    {
        for(int pos = 0; pos < inputString.length(); ++pos)
        {
            char ch = inputString[pos];
            Character character = CharacterLookup.at(ch);
            cout << character.RowData[row];
            cout << "  "; // need some space between characters for readability
        }
        cout << endl;
    }
}


int main(int argc, char* argv[])
{
    Renderer renderer;
    renderer.RenderString("012");
    //renderer.RenderString("1");
    //renderer.RenderString("2");
    return 0;
}
