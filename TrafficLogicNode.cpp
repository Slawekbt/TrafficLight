#include "TrafficLogicNode.h"


TrafficLogicNode :: TrafficLogicNode( int self_tgt, int self_pgt)
    {
        traffic_green_timeout = self_tgt;
        pedestrian_green_timeout = self_pgt;

    }

TrafficLogicNode ::  ~TrafficLogicNode()
    {}


    /* setters and getters */


    /* traffic light green timeout */
void TrafficLogicNode :: set_traffic_green_timeout(int self_tgt)
    {
        traffic_green_timeout = self_tgt;
    }

int TrafficLogicNode :: get_traffic_green_timeout(void) const
    {
        return traffic_green_timeout;
    }

    /* pedestrian traffic light green timeout */
void TrafficLogicNode :: set_pedestrian_green_timeout(int self_pgt)
    {
        pedestrian_green_timeout = self_pgt;
    }

 int TrafficLogicNode :: get_pedestrian_green_timeout(void) const
    {
        return pedestrian_green_timeout;
    }


    /* */
    /* settings states functions */

void TrafficLogicNode :: starting_state(int state)
    {
        if (state == 1) // set ON all traffic lights (tl) and all pedestrian traffic lights (ptl) in one logic node
        {
            tl_set_state(1);
            ptl_set_state(1);
        }

        else
        {
            tl_set_state(0);
            ptl_set_state(0);
        }
    }

void TrafficLogicNode :: tl_set_state(int state)    // turn ON (1) or OFF (!1) all traffic lights in one logic node
    {
        if (state == 1)         // put in ON state, Green ON
        {
            tl_1.Green.set_state(1);
            tl_1.Yellow.set_state(0);
            tl_1.Red.set_state(0);

            tl_2.Green.set_state(1);
            tl_2.Yellow.set_state(0);
            tl_2.Red.set_state(0);

        }

        else                    // put in OFF state, Red ON
        {
            tl_1.Green.set_state(0);
            tl_1.Yellow.set_state(0);
            tl_1.Red.set_state(1);

            tl_2.Green.set_state(0);
            tl_2.Yellow.set_state(0);
            tl_2.Red.set_state(1);

        }


    }

void TrafficLogicNode :: ptl_Green_set(int state) // set state of GREEN in all pedestrian traffic lights in one logic node
    {
        ptl_1.Green.set_state(state);
        ptl_2.Green.set_state(state);
        ptl_3.Green.set_state(state);
        ptl_4.Green.set_state(state);

    }

void TrafficLogicNode :: ptl_Red_set(int state) // set state of RED in all pedestrian traffic light in one logic node
    {
        ptl_1.Red.set_state(state);
        ptl_2.Red.set_state(state);
        ptl_3.Red.set_state(state);
        ptl_4.Red.set_state(state);
    }

void TrafficLogicNode :: ptl_set_state(int state) // turn ON (1) or OFF (!1) all pedestrian traffic lights in one logic node
    {
        if (state == 1) // set all pedestrian traffic light in ON mode, Green ON, Red OFF
        {
            ptl_Green_set(1);
            ptl_Red_set(0);
        }

        else
        {
            ptl_Green_set(0);
            ptl_Red_set(1);
        }
    }

    /* */
    /* sequence functions - with delay */

int TrafficLogicNode :: tl_Sequence_on(int change_time) // in sec
    {
        tl_1.Yellow.set_state(1);
        tl_2.Yellow.set_state(1);
        Sleep(1000 * change_time);

        tl_1.Yellow.set_state(0);
        tl_2.Yellow.set_state(0);

        tl_1.Red.set_state(0);
        tl_2.Red.set_state(0);

        tl_1.Green.set_state(1);
        tl_2.Green.set_state(1);

        return change_time;
    }

int TrafficLogicNode :: tl_Sequence_off(int change_time) // change time do usuniecia
    {
        tl_1.Green.set_state(0);
        tl_2.Green.set_state(0);

        tl_1.Yellow.set_state(1);
        tl_2.Yellow.set_state(1);

        Sleep(1000 * change_time);

        tl_1.Yellow.set_state(0);
        tl_2.Yellow.set_state(0);

        tl_1.Red.set_state(1);
        tl_2.Red.set_state(1);

        Sleep(1000 * change_time);

        return 2 * change_time;
    }

void TrafficLogicNode :: ptl_Sequence_on(void)
    {
        ptl_Red_set(0);
        ptl_Green_set(1);
    }

int TrafficLogicNode :: ptl_Sequence_off(void)  // blinking every 1 second
    {
        for (int i = 0; i < 3; i++)
        {
            ptl_Green_set(0);
            Sleep(500);
            ptl_Green_set(1);
            Sleep(500);
        }

        ptl_Green_set(0);
        ptl_Red_set(1);

        return 3;
    }
