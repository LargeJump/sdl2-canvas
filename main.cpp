#include <iostream>

#include "Canvas.h"


int main(int argc, char* args[]){
    using std::cout;

    Canvas canvas = Canvas(600, 600);

    while (canvas.pollEvents())
    {
        canvas.clearCanvas();

        canvas.drawRect(1,1, { 0xFF, 0x00, 0x00, 0x00});

        canvas.renderCanvas();
    }
    
    return 0;
}
