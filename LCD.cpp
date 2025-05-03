// setup: https://code.visualstudio.com/docs/cpp/config-msvc

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Renderer
{
public:
    void RenderString(string inputString);
};
void Renderer::RenderString(string inputString)
{
    cout << inputString << endl;
}


int main(int argc, char* argv[])
{
    Renderer renderer;
    renderer.RenderString("0");
    return 0;
}
