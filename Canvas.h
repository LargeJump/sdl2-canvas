#include "Window.h"

class Canvas : public Window {
public: 

    Canvas(int w, int h);

    void drawRect(int x, int y, int w, int h, SDL_Color color);
    void drawRect(int x, int y, SDL_Color color); //15x15 in size

    void drawPoint(int, int, SDL_Color);

    void renderCanvas();
    void clearCanvas();

    ~Canvas();

private:

    SDL_Renderer *renderer = nullptr;

};