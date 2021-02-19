#include "TrafficManagement.h"

TrafficManagement :: TrafficManagement()
    {
        number_of_cycles = 2;
    }

TrafficManagement :: ~TrafficManagement()
    {

    }



void TrafficManagement :: primitive_counter(int* LDVAL) // counts down to 0 starting with loaded-value LDVAl
    {
        Sleep(1000); // wait 1 sec
        (*LDVAL)--;

    }

void TrafficManagement :: lights_coordinates()
    {
        Node_1.tl_1.set_coords_auto(37, 9);
        Node_2.ptl_1.set_coords_auto(22, 6);
        Node_2.ptl_2.set_coords_auto(50, 6);

        Node_1.tl_2.set_coords_auto(37, 27);
        Node_2.ptl_3.set_coords_auto(22, 29);
        Node_2.ptl_4.set_coords_auto(50, 29);

        Node_2.tl_1.set_coords_auto(22, 17);
        Node_1.ptl_1.set_coords_auto(17, 10);
        Node_1.ptl_2.set_coords_auto(17, 26);

        Node_2.tl_2.set_coords_auto(50, 17);
        Node_1.ptl_3.set_coords_auto(55, 10);
        Node_1.ptl_4.set_coords_auto(55, 26);


    }

void TrafficManagement :: gotoxy(const int x, const int y)
    {
        COORD coord = { x, y };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }

void TrafficManagement :: road_sketch()
    {
        for (int i = 0; i <= 24 * 3; i++)  // horizontal lines
        {
            if ((i > 24) && (i < 48))
            {
                continue;
            }

            else
            {
                gotoxy(i, 12);
                cout << "_";

                gotoxy(i, 24);
                cout << "_";
            }
        }


        for (int i = 0; i <= 12 * 3; i++) // vertical lines
        {
            if ((i > 12) && (i <= 24))
            {
                continue;
            }
            gotoxy(24, i);
            cout << "|";

            gotoxy(48, i);
            cout << "|";
        }
    }

void TrafficManagement :: context_menu()
{
    gotoxy(0, 0);
    cout << "Context menu of TrafficLight simulator\n";
    cout << "Provide\n commands, to see commands \n running-config, for current setup \n change-config, to adjust all parameters \n run, to start the programm \n";
    cout << " exit, to end program \n";
    string input_string = "";
    
    for ( ; ; )
    {
        cin >> input_string;

        if (input_string.compare("running-config") == 0 )
        {
            system("CLS");
            cout << "Current configuration \n";
            cout << " Main road \n";
            cout << " Car Traffic Light Green duration         = " << Node_1.get_traffic_green_timeout() << "sec \n";
            cout << " Pedestrian Traffic Light Green duration  = " << Node_1.get_pedestrian_green_timeout() << "sec \n\n";

            cout << " Cross road \n";
            cout << " Car Traffic Light Green duration         = " << Node_2.get_traffic_green_timeout() << "sec \n";
            cout << " Pedestrian Traffic Light Green duration  = " << Node_2.get_pedestrian_green_timeout() << "sec \n\n";

            cout << " Total time of one cycle                  = " << Node_1.get_traffic_green_timeout() + Node_2.get_traffic_green_timeout() << "sec \n";
            cout << " Number of cycles                         = " << number_of_cycles;
            cout << endl;
            input_string = "";

        }

        else if (input_string.compare("run") ==0 )
        {   
            system("CLS");
            run();
            input_string = "";
        }

        else if (input_string.compare("change-config") == 0)
        {
            system("CLS");
            string temporary_input = "";
            int converted_temporary_input = 0;
            cout << "Change MAIN ROAD Car Traffic Light Green duration, current state is         " << Node_1.get_traffic_green_timeout() << "sec \n";
            cin >> temporary_input;
            converted_temporary_input = stoi(temporary_input);
            if (converted_temporary_input < 5)
            {
                cout << "\nValue less than 6 may be too small for good simulation";
                converted_temporary_input = 30;
            }
            Node_1.set_traffic_green_timeout(converted_temporary_input);
            cout << "\nCurrent MAIN ROAD Car Traffic Light Green duration is                     " << Node_1.get_traffic_green_timeout() << " sec \n\n";

            cout << "Change MAIN ROAD Pedestrian Traffic Light Green duration, current state is  " << Node_1.get_pedestrian_green_timeout() << "sec \n";
            cin >> temporary_input;
            converted_temporary_input = stoi(temporary_input);
            if (converted_temporary_input > Node_1.get_traffic_green_timeout())
            {
                cout << "\nPedestrian Traffic Light Green cannot last more than Car Traffic Light Green at the same logic node";
                converted_temporary_input = Node_1.get_traffic_green_timeout() - 3;
            }
            Node_1.set_pedestrian_green_timeout(converted_temporary_input);
            cout << "\nCurrent MAIN ROAD Car Traffic Light Green duration is                    " << Node_1.get_pedestrian_green_timeout() << " sec \n\n";

            cout << "Change CROSS ROAD Car Traffic Light Green duration, current state is        " << Node_2.get_traffic_green_timeout() << "sec \n";
            cin >> temporary_input;
            converted_temporary_input = stoi(temporary_input);
            if (converted_temporary_input < 5)
            {
                cout << "\nValue less than 6 may be too small for good simulation";
                converted_temporary_input = 20;
            }
            Node_2.set_traffic_green_timeout(converted_temporary_input);
            cout << "\n Current CROSS ROAD Car Traffic Light Green duration is                   " << Node_2.get_traffic_green_timeout() << " sec \n\n";

            cout << "Change CROSS ROAD Pedestrian Traffic Light Green duration, current state is " << Node_2.get_pedestrian_green_timeout() << "sec \n";

            cin >> temporary_input;
            converted_temporary_input = stoi(temporary_input);

            if (converted_temporary_input > Node_2.get_traffic_green_timeout())
            {
                cout << "\nPedestrian Traffic Light Green cannot last more than Car Traffic Light Green at the same logic node";
                converted_temporary_input = Node_2.get_traffic_green_timeout() - 3;
            }

            Node_2.set_pedestrian_green_timeout(converted_temporary_input);
            cout << "\n Current CROSS ROAD Car Traffic Light Green duration is                   " << Node_2.get_pedestrian_green_timeout() << " sec \n\n";

            cout << " Current duration of a single cycle is                                      " << Node_1.get_traffic_green_timeout() + Node_2.get_traffic_green_timeout() << endl;
            cout << " Choose number of cycles [not less than 1]";
            cin >> temporary_input;
            converted_temporary_input = stoi(temporary_input);
            if (converted_temporary_input < 1)
            {
                cout << "Number of cycles cannot be less than 1, setting to defaults";
                converted_temporary_input = 1;
            }
            number_of_cycles = converted_temporary_input;
            cout << "Number of cycles set to                                                     " << number_of_cycles;

            cout << endl << endl;

            input_string = "";
        }

        else if (input_string.compare("commands") == 0)
        {
            cout << "Provide\n commands, to see commands \n running-config, for current setup \n change-config, to adjust all parameters \n run, to start the programm \n";
            cout << " exit, to end program \n";
            input_string = "";
        }
        
        else if (input_string.compare("exit") == 0)
        {
            cout << "Closing ... ";
            return;
        }
    }
}

void TrafficManagement :: run()
    {
        /* at the beginning traffic on the main road is ongoing */
        lights_coordinates();
        road_sketch();

        /* Write Green timeouts */

        gotoxy(60, 0);
        cout << "Main Road for Cars          " << Node_1.get_traffic_green_timeout() << "s\n";
        gotoxy(60, 1);
        cout << "Main Road for Pedestrians   " << Node_1.get_pedestrian_green_timeout() << "s\n";
        gotoxy(60, 2);
        cout << "Cross Road for Cars         " << Node_2.get_traffic_green_timeout() << "s\n";
        gotoxy(60, 3);
        cout << "Cross Road for Pedestrians  " << Node_2.get_pedestrian_green_timeout() << "s\n";
        gotoxy(60, 4);
        cout << "Number of cycles            " << number_of_cycles;

        int cycle_number = 1;
        gotoxy(0, 1);
        cout << "Cycle number " << cycle_number;

        Node_1.starting_state(1); // on
        Node_2.starting_state(0); // off

        int cycle_duration = Node_1.get_traffic_green_timeout() + Node_2.get_traffic_green_timeout();
        int cycle_countdown = cycle_duration;

        /* time stamps */
        int node_1_pedestrian_end = cycle_duration - Node_1.get_pedestrian_green_timeout(); // pedestrian traffic parallel to main road stops       (Node_1)
        int node_1_traffic_end = cycle_duration - Node_1.get_traffic_green_timeout();       // car traffic on the main road stops                   (Node_1)
                                                                                            // traffic for cars opens on the cross road             (Node_2)
                                                                                            // traffic for pedestrians opens parallel to cross road (Node_2)

        int node_2_pedestrian_end = node_1_traffic_end - Node_2.get_pedestrian_green_timeout(); // traffic for pedestrians closes
                                                                                                // traffic for cars will close when
                                                                                                // timer hits 0 value
                                                                                                // new cycle will start

        while (cycle_number <= number_of_cycles)
        {
            primitive_counter(&cycle_countdown);             // wait 1 sec, store result in cycle_duration

            if (cycle_countdown == node_1_pedestrian_end)
            {
                Node_1.ptl_Sequence_off();   // turn off all pedestrian lights on Node_1
            }

            else if (cycle_countdown == node_1_traffic_end)
            {
                Node_1.tl_Sequence_off(2);    // turn off all traffic lights on Node_1
                Node_2.tl_Sequence_on(2);     // turn on all traffic light on Node_2
                Node_2.ptl_Sequence_on();     // turn on all pedestrian light on Node_2
            }

            else if (cycle_countdown == node_2_pedestrian_end)
            {
                Node_2.ptl_Sequence_off();   // turn off all pedestrian lights on Node_2
            }

            else if (cycle_countdown == 0)   // if cycle finished
            {   
              
                Node_2.tl_Sequence_off(2); // turn off all traffic lights on Node_2
                cycle_countdown = cycle_duration; // reload cycle_duration

                Node_1.tl_Sequence_on(2); // turn on all traffic lights on Node_1
                Node_1.ptl_Sequence_on(); // turn on all pedestrian lights on Node_1
                
                gotoxy(0, 1);
                cycle_number++;
                cout << "Cycle number " << cycle_number;


            }

            else
            {
                gotoxy(0, 0);
                cout << "Countdown " << cycle_countdown << "[s]";
            }
        }

        gotoxy(0, 3);
    }