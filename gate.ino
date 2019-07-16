int port = D0;

void setup() {
  pinSetFast(port);
  pinMode(port, OUTPUT);
  pinSetFast(port);
  Particle.function("gate", moment);
}


void loop() {

}


int moment(String in)
{
    digitalWrite(port, LOW);
    delay(700);
    digitalWrite(port, HIGH);
    return 1;
}
