#include "Simple_window.h"
#include "Graph.h"

int main()
{
    using namespace Graph_lib;

    Point tl{100,100};
    Simple_window win{tl,800,1000,"My window"};

    int x_size=800;
    int y_size=800;
    int x_grid=100;
    int y_grid=100;

    Lines grid;
    for (int x=x_grid; x<x_size;x+=x_grid)
    grid.add(Point{x,0},Point{x,y_size});
    for(int y=y_grid; y<y_size;y+=y_grid)
    grid.add(Point{0,y},Point{x_size,y});

    grid.set_color(Color::dark_blue);

    Vector_ref<Rectangle> dia;

    for(int i =0; i<8;++i){
            dia.push_back(new Rectangle(Point{i*100,i*100},100,100));
            dia[dia.size()-1].set_fill_color(Color::red);
            win.attach(dia[dia.size()-1]);
    }


    Image i1(Point{0,600},"kepecske.jpg");
    Image i2(Point{400,100},"kepecske.jpg");
    Image i3(Point{600,300},"kepecske.jpg");

    win.attach(i1);
    win.attach(i2);
    win.attach(i3);
    win.attach(grid);

    Image kavicska {Point{0,0}, "kepecske2.jpg"};
    win.attach(kavicska);
    win.wait_for_button();

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 7; ++j) {
            kavicska.move(100, 0);
            win.wait_for_button();
            win.label("Kavicska");
        }
        kavicska.move(-700, 100);
        win.wait_for_button();
    };

    win.wait_for_button();
}