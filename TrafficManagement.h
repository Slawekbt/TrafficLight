#ifndef TRAFFICMANAGEMENT_H
#define TRAFFICMANAGEMENT_H

#include <iostream>
#include <string>  // stoi () facility
#include <cstdlib> // for system("CLS") facility

#include "TrafficLogicNode.h"

using namespace std;

class TrafficManagement /* z uzyciem zmiennych static ? */
{
private:
    int number_of_cycles;

    /* inside functions -- non-callable by user */
    void lights_coordinates();
    void primitive_counter(int* LDVAL); // counts down to 0 starting with loaded-value LDVAl
    void gotoxy(const int x, const int y);
    void road_sketch();
    void run();
    

public:
    
    TrafficLogicNode Node_2 = TrafficLogicNode( 20, 10 ); // Cross Road
    TrafficLogicNode Node_1 = TrafficLogicNode( 30, 20 ); // Main Road


    TrafficManagement();

    void context_menu();

    ~TrafficManagement();

};

#endif