#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>

class Window
{
public:
    Window(int width, int height);

    //return false if program should quit
    bool pollEvents();

    ~Window();

protected:
    SDL_Window *window = nullptr;

    int WINDOW_WIDTH;
    int WINDOW_HEIGHT;
};

#endif
