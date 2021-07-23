#include "Canvas.h"

#include <SDL2/SDL2_gfxPrimitives.h>
#include <iostream>

Canvas::Canvas(int w, int h): Window(w,h){
    renderer = SDL_CreateRenderer( Window::window, -1, SDL_RENDERER_ACCELERATED );

    clearCanvas();
    renderCanvas();
}

void Canvas::drawRect(int x, int y, int w, int h, SDL_Color color) {
    SDL_Rect rect = {x, y, w, h};

    SDL_SetRenderDrawColor( renderer, color.r, color.g, color.b, color.a );
    SDL_RenderFillRect( renderer, &rect );

}

void Canvas::drawRect(int x, int y, SDL_Color color) {
    SDL_Rect rect = { x, y,15,15};

    SDL_SetRenderDrawColor( renderer, color.r, color.g, color.b, color.a );
    SDL_RenderFillRect( renderer, &rect );

}

void Canvas::drawPoint(int x, int y, SDL_Color color){

    SDL_SetRenderDrawColor( renderer, color.r, color.g, color.b, color.a );
    SDL_RenderDrawPoint( renderer, x, y);

}

void Canvas::renderCanvas() {
    SDL_RenderPresent( renderer );
}

void Canvas::clearCanvas() {
    //set renderer clear to black screen (0, 0, 0)
    SDL_SetRenderDrawColor( renderer, 0x0, 0x0, 0x0, 0xFF );
    SDL_RenderClear( renderer );

}

void Canvas::drawLine(int x1, int y1, int x2, int y2){
    lineColor( renderer, x1, y1, x2, y2, 0xFFFFFFFF );
}

Canvas::~Canvas(){

    SDL_DestroyRenderer( renderer );
    renderer = nullptr;

}