int x = 10;
int* p = &x;
#define BUZZER *p

class LED {
	int LredC;
	int LyelC;
	int LgreC;

public:
  LED (int LrC, int LyC, int LgrC) {

  LredC = LrC;
	LyelC = LyC;
	LgreC = LgrC;
    
  pinMode(LredC, OUTPUT);
  pinMode(LyelC, OUTPUT);
  pinMode(LgreC, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  }
  void apita () {
  digitalWrite(LredC, HIGH);
  delay(6000); 

  digitalWrite(LyelC, HIGH);
  digitalWrite(LredC, LOW);
  delay(2000); 

  digitalWrite(LyelC,LOW);
  digitalWrite(LgreC, HIGH);
  tone(BUZZER, 392);
  delay(4000);

  digitalWrite(LgreC, LOW);
  noTone(BUZZER);
  }
};

LED leds(13, 12, 11);

void setup()
{}

void loop()
{
	leds.apita();
}