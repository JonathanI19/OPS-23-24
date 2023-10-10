
#define PotPin 14
#define LEDPin  7

int delay_on, delay_off;
int init_val = 1023;

void setup() {
  // put your setup code here, to run once:
  pinMode(LEDPin, OUTPUT);
  pinMode(PotPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay_on = analogRead(PotPin);
  delay_off = init_val - delay_on;

  digitalWrite(LEDPin, HIGH);
  delay(delay_on);
  digitalWrite(LEDPin, LOW);
  delay(delay_off);
  
}
