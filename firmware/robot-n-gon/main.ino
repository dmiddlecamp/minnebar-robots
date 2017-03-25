// This #include statement was automatically added by the Particle IDE.
#include <PhoBot.h>

#define FULL_CIRCLE_TIME 1000
#define TURN_SPEED 100

PhoBot bot;
double volts = 0.0;
double distance = 0.0;

void setup() {
    Particle.function("go", onGo);
    Particle.function("control", control);

}

void loop() {

}


int onGo(String cmd) {
 //int steps = cmd.toInt();
 int steps = 5;
 int sides = cmd.toInt();
 
 float turn_delay_fraction = ((float)FULL_CIRCLE_TIME) / ((float)sides);
 
 for (int i=0;i<sides;i++) {
     bot.control("F-100");
     delay(steps * 50);
     
     bot.control("L-" + String(TURN_SPEED));
     delay(turn_delay_fraction);
 }
 
 bot.control("S");   
}

int control(String command) {
    return bot.control(command);
}


