const int echo = 2;
const int trig = 3;

const int MOTOR_A1 = 5;
const int MOTOR_A2 = 6;

const int MOTOR_B1 = 8;
const int MOTOR_B2 = 9;

const char forward[] = "forward";
const char back[] = "back";
const char left[] = "left";
const char right[] = "right";
const char stop[] = "stop";

int distance;

void setup()
{
  Serial.begin(9600);
  Serial.println("Start");

  // Distance
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);

  // Motors
  pinMode(MOTOR_A1, OUTPUT);
  pinMode(MOTOR_A2, OUTPUT);

  pinMode(MOTOR_B1, OUTPUT);
  pinMode(MOTOR_B2, OUTPUT);
  distance = getDistance();
}

void loop()
{
  distance = getDistance();
  if (distance < 30)
  {
    move(stop);
    delay(1000);
    
    move(back);
    delay(1000);
    
    move(stop);
    delay(1000);
    move(right);
    delay(2000);

    move(stop);
    delay(1000);
  }
  else
  {
    move(forward);
  }
  delay(100);
}

int getDistance()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  int duration = pulseIn(echo, HIGH);
  int cm = duration / 29 / 2;
  Serial.print(cm);
  Serial.println("cm");

  return cm;
}

void move(const String &direction)
{
  Serial.println(direction);
  if (direction == "forward")
  {
    digitalWrite(MOTOR_A1, HIGH);
    digitalWrite(MOTOR_A2, LOW);

    digitalWrite(MOTOR_B1, LOW);
    digitalWrite(MOTOR_B2, HIGH);
  }
  else if (direction == "back")
  {
    digitalWrite(MOTOR_A1, LOW);
    digitalWrite(MOTOR_A2, HIGH);

    digitalWrite(MOTOR_B1, HIGH);
    digitalWrite(MOTOR_B2, LOW);
  }
  else if (direction == "right")
  {
    digitalWrite(MOTOR_A1, LOW);
    digitalWrite(MOTOR_A2, HIGH);

    digitalWrite(MOTOR_B1, LOW);
    digitalWrite(MOTOR_B2, HIGH);
  }
  else if (direction == "left")
  {
    digitalWrite(MOTOR_A1, HIGH);
    digitalWrite(MOTOR_A2, LOW);

    digitalWrite(MOTOR_B1, HIGH);
    digitalWrite(MOTOR_B2, LOW);
  }
  else
  {
    digitalWrite(MOTOR_A1, LOW);
    digitalWrite(MOTOR_A2, LOW);

    digitalWrite(MOTOR_B1, LOW);
    digitalWrite(MOTOR_B2, LOW);
  }
}
