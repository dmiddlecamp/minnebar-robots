// This #include statement was automatically added by the Particle IDE.
#include <PhoBot.h>

#define TURN_DELAY 250
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
 int steps = cmd.toInt();
 
 for (int i=0;i<4;i++) {
     bot.control("F-100");
     delay(steps * 50);
     
     bot.control("L-" + String(TURN_SPEED));
     delay(TURN_DELAY);
 }
 
 bot.control("S");   
}

int control(String command) {
    return bot.control(command);
}

