#include <stdio.h>

#define WITH_ENGINE_TEMP_CONTROLLER 1 
/*to control the engine code lines*/
/*declaring and initializing the variables*/
char traffic_light_color = 'g';
int room_temp = 30;
int engine_temp = 90;
int AC_state = 0;
int engine_state = 0;
int vehicle_speed = 65;

void set_3(void);   /*the menu of the 3 options*/
void set_4(void);   /*the menu of the 4 options*/



void v_speed(void)
/*takes traffic color as an input from the user and changes the speed*/
{
    printf("Enter the required color: \n");
    fflush(stdout);
    scanf(" %c",&traffic_light_color);
    switch(traffic_light_color){
        case 'g':
        case 'G':
            vehicle_speed = 100;
            break;

        case 'o':
        case 'O':
            vehicle_speed = 30;
            break;

        case 'r':
        case 'R':
            vehicle_speed = 0;
            break;

        default:printf("not a valid input\n");
    }
}


void r_temp(void)
/*takes the room temperature as an input from the user and depending on it decides whether to
turn the AC on or off*/
{
    printf("Enter the required room temperature: \n");
    fflush(stdout);
    scanf(" %d",&room_temp);
    if(room_temp < 10 || room_temp > 30){
        AC_state = 1;
        room_temp = 20;
    }
    else {AC_state = 0;}
}

#if(WITH_ENGINE_TEMP_CONTROLLER == 1)
void e_temp(void)
/*takes the engine temperature as an input from the user and depending on it decides whether to
turn the engine temperature controller on or off*/
{
    printf("Enter the required engine temperature: \n");
    fflush(stdout);
    scanf(" %d",&engine_temp);
    if(engine_temp < 100 || engine_temp > 150){
        engine_state = 1;
        engine_temp = 125;
    }
    else{engine_state = 0;}
}
#endif


void states(void)
/*prints the states of the engine*/
{
    printf("\nEngine is ON\n");
    if(AC_state == 1)
    printf("AC is ON\n");
    else
    printf("AC is OFF\n");
    printf("Vehicle Speed: %d Km/Hr \n",vehicle_speed);
    printf("Room Temperature: %d C \n",room_temp);
    #if(WITH_ENGINE_TEMP_CONTROLLER == 1)
    if(engine_state == 1)
    printf("Engine Temperature Controller State is ON\n");
    else
    printf("Engine Temperature Controller State is OFF\n");
    printf("Engine Temperature: %d C \n\n",engine_temp);
    #else
    printf("\n");
    #endif
}


void set_3(void)
/*shows 3 options to the user to choose one from*/
{
    while(1){
    char ch;
    printf("a. Turn on the vehicle engine\n");
    fflush(stdout);
    printf("b. Turn off the vehicle engine\n");
    fflush(stdout);
    printf("c. Quit the system\n\n");
    fflush(stdout);
    scanf(" %c",&ch);
    switch(ch){
        case 'c':
        printf("Quit the system\n");
        return;
        break;

        case 'b':
        break;

        case 'a':
        set_4();
        return;
        break;

    }
    }
}


void set_4()
/*shows 4 options to the user to choose one from*/
{
     while(1){
    char ch;
    printf("a. Turn off the engine\n");
    fflush(stdout);
    printf("b. Set the traffic light color\n");
    fflush(stdout);
    printf("c. Set the room temperature (Temperature Sensor)\n");
    fflush(stdout);
    #if(WITH_ENGINE_TEMP_CONTROLLER == 1)
    printf("d. Set the engine temperature (Engine Temperature Sensor)\n\n");
    fflush(stdout);
    #else
    printf("\n");
    fflush(stdout);
    #endif
    scanf(" %c",&ch);
    if(ch == 'a'){
        set_3();
        return;}

    else if(ch == 'b'){
        v_speed();
        if(vehicle_speed == 30){
            if(AC_state == 0)
            AC_state = 1;
            room_temp = room_temp*1.25 + 1;
            #if(WITH_ENGINE_TEMP_CONTROLLER == 1)
            if(engine_state == "OFF")
            engine_state = "ON";
            engine_temp = engine_temp*1.25 +1;
            #endif
        }
        states();}

    else if(ch == 'c'){
        r_temp();
        states();}

    else if(ch == 'd'){
        #if(WITH_ENGINE_TEMP_CONTROLLER == 1)
        e_temp();
        states();
        #endif
    }
}
}

int main(void)
{
set_3();
/*this function will get called and it will display 3 options to the user and depending on the option
an action will be done*/
return 0;
}



