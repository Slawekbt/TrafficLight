#include "Light.h"


  Light :: Light()
    {
        state = 0;
        color = "";
    }

     Light :: ~Light()
    {

    }

    void Light :: set_state(bool self_state)
    {
        state = self_state;
        if (state == 1)
            set_color();
        else if (state == 0)
            clear_color();
    }

    bool Light :: get_state(void) const
    {
        return state;
    }

    void  Light :: set_coords(int self_x, int self_y)
    {
        position.x = self_x;
        position.y = self_y;
    }

    int Light :: get_coords_x(void) const
    {
        return position.x;
    }

    int Light :: get_coords_y(void) const
    {
        return position.y;
    }

    /* */
    /* GOTOXY and Console Handler functions, for changing light colors in console */
    /* */

    void Light :: gotoxy(const int x, const int y)
    {
        COORD coord = { x, y };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }

    void Light :: set_color(void) // on the Screen
    {
        int color_number = 0;

        if (color == "red")
            color_number = 12;
        else if (color == "green")
            color_number = 10;
        else if (color == "yellow")
            color_number = 14;

        gotoxy(position.x, position.y);                                            // position of light in console
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
        cout << "*";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);               // return console to normal colors

    }

    void Light :: clear_color(void)  // set color to white - light is OFF
    {
        gotoxy(position.x, position.y);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        cout << "*";
    }

