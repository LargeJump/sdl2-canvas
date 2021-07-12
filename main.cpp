#include <iostream>

#include "Canvas.h"
#include "Box.h"

//sample program


int main(int argc, char* args[]){
    using std::cout;

    Canvas canvas = Canvas(600, 600);
    Box box;
    Box box1;

    box.pos = {400, 1};
    box.v = { 3, 3};

    box1.pos = {300, 1};
    box1.v = { -5, 2};

    uint32_t t0 = 0;
    uint32_t t1 = 0;
    uint32_t t2 = 0;


    int frameCap = 30;

    int frame = 0;
    int spf = 1000 / frameCap; //sec per frame

    uint32_t dt = 0;
    bool keepAlive = true;
    while (keepAlive) {

        t0 = SDL_GetTicks();
        keepAlive = canvas.pollEvents();

        canvas.clearCanvas();

            box.collision();
            box1.collision();

            box.update();
            box1.update();

            canvas.drawRect(box.pos.x,box.pos.y, { 0xFF, 0x00, 0x00, 0x00 });

            canvas.drawRect(box1.pos.x,box1.pos.y, { 0xFF, 0x00, 0x00, 0x00 });

        canvas.renderCanvas();
        frame++;

        t1 = SDL_GetTicks();
        //fps limit to frame cap
        if( (dt=t1-t0) < spf ){
            SDL_Delay( spf - dt );
            // cout << "delay time : " << spf - dt << '\n';
        }

    }
    
    return 0;
}
