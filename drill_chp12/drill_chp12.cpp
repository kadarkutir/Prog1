#include "Simple_window.h"
#include "Graph.h"

int main()
{
    using namespace Graph_lib;

    Point tl{100,100};
    Simple_window win{tl,600,400,"My window"};

    Axis xa {Axis::x,Point{100,300},280,10,"x axis"};
    xa.set_color(Color::dark_yellow);

    Axis ya {Axis::y, Point{100,300}, 280, 10, "y axis"};
    ya.set_color(Color::magenta);
    ya.label.set_color(Color::cyan);

    Function sine {sin,0,100,Point{100,150},1000,50,50};
    sine.set_color(Color::dark_red);
    
    Polygon poly;
    poly.add(Point{100,200});
    poly.add(Point{150,100});
    poly.add(Point{200,200});
    poly.set_color(Color::blue);
    poly.set_style(Line_style::dash);

    Rectangle r {Point{400,300}, 200, 100};
    r.set_color(Color::green);
    r.set_fill_color(Color::dark_cyan);

    Text t {Point{410,350}, "Hello, graphical world!"};
    t.set_color(Color::magenta);
    t.set_font(Font::times_bold);
    t.set_font_size(12);

    Image ii {Point{0,20},"kep.jpg"};

    Circle c {Point{100,300},50};
    c.set_color(Color::blue);
    c.set_fill_color(Color::red);
    Mark m {Point{100,300},'x'};

    
    win.attach(ii);
    win.attach(c);
    win.attach(m);
    win.attach(r);
    win.attach(t);
    win.attach(poly);
    win.attach(sine);
    win.attach(ya);
    win.attach(xa);
    win.wait_for_button();    
}