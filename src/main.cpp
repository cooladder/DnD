#include "window.h"


int main()
{
    Window& mainWin = Window::getInstance();
    return mainWin.run();
}
