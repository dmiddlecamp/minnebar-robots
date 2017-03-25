// This #include statement was automatically added by the Particle IDE.
#include <PhoBot.h>


PhoBot bot;
double volts = 0.0;
double distance = 0.0;

void setup() {
    Particle.function("go", onGo);

}

void loop() {

}



int onGo(String cmd) {
 int steps = cmd.toInt();
 
 bot.control("F-100");
 delay(steps * 50);
 bot.control("S");   
}

