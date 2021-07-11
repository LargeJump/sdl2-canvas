#include <iostream>

#include "Canvas.h"

//sample program

class Box{

private:
    typedef struct {
        int x;
        int y;
    } vec2;

public:
    Box(){};
    vec2 v = { 1, 1 };
    vec2 pos = { 1, 1 };

    void update(){
        pos.x += v.x;
        pos.y += v.y;
    };

};


int main(int argc, char* args[]){
    using std::cout;

    Canvas canvas = Canvas(600, 600);
    Box box;

    uint32_t t0 = 0;
    uint32_t t1 = 0;

    int frameCap = 60;

    int frame = 0;
    int spf = 1000 / frameCap; //sec per frame

    uint32_t dt = 0;
    while (canvas.pollEvents()) {

        t0 = SDL_GetTicks();

        canvas.clearCanvas();

            box.update();
            canvas.drawRect(box.pos.x,box.pos.y, { 0xFF, 0x00, 0x00, 0x00 });

        canvas.renderCanvas();
        frame++;

        t1 = SDL_GetTicks();
        //fps limit to frame cap
        if( (dt=t1-t0) < spf ){
            SDL_Delay( spf - dt );
        }

    }
    
    return 0;
}
