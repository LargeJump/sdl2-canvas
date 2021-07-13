#include "Window.h"
#include <iostream>

using std::cout;

Window::Window(int width, int height) {
    cout << "Creating Window\n";

    if( SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0){
        cout << "SDL ERROR : \n" << SDL_GetError();
    }

    WINDOW_WIDTH  = width;
    WINDOW_HEIGHT = height;

    window = SDL_CreateWindow( "Canvas", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN );

    cout << "window created\n";
}

bool Window::pollEvents(){
    SDL_Event e;
    while(SDL_PollEvent(&e)){

        switch(e.type){
            case(SDL_QUIT): {
                return false;
            }
            //check events here
        }

    }
    return true; // window should not exit
}

Window::~Window() {
    SDL_DestroyWindow( window );
    window   = nullptr;

    //quit subsystems when window does not exist
    SDL_Quit();

    cout << "Exiting...\n";
}
