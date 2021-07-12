class Box{

private:
    typedef struct {
        int x;
        int y;
    } vec2;

public:
    Box(){};
    vec2 v = { 3, 5 };
    vec2 pos = { 50, 1 };

    void update(){
        pos.x += v.x;
        pos.y += v.y;
    };

    bool collision(){
        if(pos.x < 0 || pos.x + 15 > 600){
            v.x *= -1;
        };
        if(pos.y < 0 || pos.y + 15 > 600){
            v.y *= -1;
        };

        return false;
    };


};

