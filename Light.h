#ifndef LIGHT_H
#define LIGHT_H

#include <iostream>
#include <Windows.h> // for Sleep(), gotoxy()

using namespace std;

class Light /* Virtual Class */
{
protected:

    bool state;          // 0 for Light OFF and 1 for Light ON

    struct coords
    {
        int x;         // x-axis coordinate on console screen
        int y;         // y-axis coordinate on console screen

    };
    struct coords position;

    string color;

public:

    Light();
    virtual  ~Light();

    void set_state(bool self_state);

    bool get_state(void) const;

    void set_coords(int self_x, int self_y);

    int get_coords_x(void) const;

    int get_coords_y(void) const;


    /* */
    /* GOTOXY and Console Handler functions, for changing light colors in console */
    /* */

    void gotoxy(const int x, const int y);

    void set_color(void);


    void clear_color(void);  // set color to white - light is OFF

    /* */

    virtual string get_color(void) const = 0; /* Pure virtual method */

};

#endif