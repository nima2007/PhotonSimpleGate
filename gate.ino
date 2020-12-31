STARTUP(WiFi.selectAntenna(ANT_AUTO));

int port = D5;
int port2 = D0;

Timer garage1timer(1000 * 60, moment1, true);
Timer garage2timer(1000 * 60, moment2, true);

void setup() {
  pinSetFast(port);
  pinMode(port, OUTPUT);
  pinSetFast(port);
  Particle.function("garage", garage1);
  Particle.function("garage1timer", garage1_timer);

  pinSetFast(port2);
  pinMode(port2, OUTPUT);
  pinSetFast(port2);
  Particle.function("garage2", garage2);
  Particle.function("garage2timer", garage2_timer);
}


void loop() {

}

int garage1(String in)
{
    moment1();
    return 1;
}

int garage2(String in)
{
    moment2();
    return 1;
}

int garage2_timer(String in)
{
    int secs = in.toInt() * 60;
    if(secs < 30 || secs > 1200)
    return -1;
    secs = secs + 10; //Est. garage open time
    garage2timer.changePeriod(1000 * secs);
    moment2();
    garage2timer.start();
    return 1;
}

int garage1_timer(String in)
{
    int secs = in.toInt() * 60;
    if(secs < 30 || secs > 1200)
    return -1;
    secs = secs + 10; //Est. garage open time
    garage1timer.changePeriod(1000 * secs);
    moment1();
    garage1timer.start();
    return 1;
}

void moment1()
{
    digitalWrite(port, LOW);
    delay(700);
    digitalWrite(port, HIGH);
}


void moment2()
{
    digitalWrite(port2, LOW);
    delay(700);
    digitalWrite(port2, HIGH);
}