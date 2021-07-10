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

    while (canvas.pollEvents())
    {
        t0 = SDL_GetTicks();

        // update ~ every frameCap fps 
        if( t0-t1 >= 1000 / frameCap){
            // cout << "t0 | t1 \t" << t0 << " | " << t1 << "\t" << total <<"\n";
            canvas.clearCanvas();

            box.update();
            canvas.drawRect(box.pos.x,box.pos.y, { 0xFF, 0x00, 0x00, 0x00 });

            canvas.renderCanvas();

            t1 = SDL_GetTicks();

            frame++;
                cout << (double)frame / (t0 / 1000.0f) << "\n";
        }
       

    }
    
    return 0;
}
