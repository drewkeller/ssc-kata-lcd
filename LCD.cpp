// setup: https://code.visualstudio.com/docs/cpp/config-msvc

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <Windows.h>

using namespace std;

typedef unsigned char uchar;

constexpr int CHARACTER_ROW_COUNT = 5;
constexpr int CHARACTERS_IN_ROW_COUNT = 6;

struct Character
{
    string RowData[CHARACTER_ROW_COUNT];
};

// using unicode one-eighth blocks: https://www.unicode.org/charts/PDF/U2580.pdf
map<char, Character> CharacterLookup = {
    //        ROW1      ROW2      ROW3      ROW4       ROW5
    //        ------    ------    ------    ------     ----
    { '0', { " ▁▁▁▁ ", "▕    ▏", "▕    ▏", "▕    ▏", " ▔▔▔▔ "} },
    { '1', { "      ", "     ▏", "     ▏", "     ▏", "      "} },
    { '2', { " ▁▁▁▁ ", "     ▏", " ▬▬▬▬ ", "▕     ", " ▔▔▔▔ "} },
    { '3', { " ▁▁▁▁ ", "     ▏", " ▬▬▬▬ ", "     ▏", " ▔▔▔▔ "} },
    { '4', { "      ", "▕    ▏", " ▬▬▬▬ ", "     ▏", "      "} },
    { '5', { " ▁▁▁▁ ", "▕     ", " ▬▬▬▬ ", "     ▏", " ▔▔▔▔ "} },
    { '6', { " ▁▁▁▁ ", "▕     ", " ▬▬▬▬ ", "▕    ▏", " ▔▔▔▔ "} },
    { '7', { " ▁▁▁▁ ", "     ▏", "     ▏", "     ▏", "      "} },
    { '8', { " ▁▁▁▁ ", "▕    ▏", " ▬▬▬▬ ", "▕    ▏", " ▔▔▔▔ "} },
    { '9', { " ▁▁▁▁ ", "▕    ▏", " ▬▬▬▬ ", "     ▏", "      "} },
};

class Renderer
{
public:
    void RenderString(string inputString);
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
}


int main(int argc, char* argv[])
{
    // see https://stackoverflow.com/questions/45575863/how-to-print-utf-8-strings-to-stdcout-on-windows
    SetConsoleOutputCP(CP_UTF8);
    setvbuf(stdout, nullptr, _IOFBF, 1000);

    Renderer renderer;
    renderer.RenderString("0123456789");
    //renderer.RenderString("1");
    //renderer.RenderString("2");
    return 0;
}
