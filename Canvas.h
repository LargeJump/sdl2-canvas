#ifndef CANVAS_H
#define CANVAS_H

#include "Window.h"
#include <SDL2/SDL2_gfxPrimitives.h>

class Canvas : public Window {
public: 

    Canvas(int w, int h);

    void drawRect(int x, int y, int w, int h, SDL_Color color);
    void drawRect(int x, int y, SDL_Color color); //15x15 in size

    void drawPoint(int, int, SDL_Color);

    void drawLine(int x1, int y1, int x2, int y2);
    void drawLine(SDL_Point a, SDL_Point b, uint32_t color);

    void renderCanvas();
    void clearCanvas();

    ~Canvas();

private:

    SDL_Renderer *renderer = nullptr;
};

#endif