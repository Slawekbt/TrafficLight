#ifndef TRAFFICLOGICNODE_H
#define TRAFFICLOGICNODE_H

#include <iostream>
#include "TrafficLight.h"
#include "PedestrianTrafficLight.h"

using namespace std;

class TrafficLogicNode
{
private:

    int traffic_green_timeout;    // given in seconds
    int pedestrian_green_timeout; // given in seconds

public:
    TrafficLight tl_1, tl_2;                                // the same logic road
    PedestrianTrafficLight ptl_1, ptl_2, ptl_3, ptl_4;      // the same logic road

    TrafficLogicNode( int self_tgt, int self_pgt);
    ~TrafficLogicNode();


    /* setters and getters */


    /* traffic light green timeout */
    void set_traffic_green_timeout(int self_tgt);

    int get_traffic_green_timeout(void) const;

    /* pedestrian traffic light green timeout */
    void set_pedestrian_green_timeout(int self_pgt);

    int get_pedestrian_green_timeout(void) const;


    /* */
    /* settings states functions */

    void starting_state(int state);

    void tl_set_state(int state);    // turn ON (1) or OFF (!1) all traffic lights in one logic node

    void ptl_Green_set(int state); // set state of GREEN in all pedestrian traffic lights in one logic node

    void ptl_Red_set(int state); // set state of RED in all pedestrian traffic light in one logic node

    void ptl_set_state(int state); // turn ON (1) or OFF (!1) all pedestrian traffic lights in one logic node

    /* */
    /* sequence functions - with delay */

    int tl_Sequence_on(int change_time); // in sec

    int tl_Sequence_off(int change_time); // change time do usuniecia

    void ptl_Sequence_on(void);

    int ptl_Sequence_off(void);  // blinking every 1 second

};

#endif
