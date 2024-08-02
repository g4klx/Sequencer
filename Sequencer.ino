// Defines for the Arduino 4 relay shield
const uint8_t RELAY1_PIN = 4U;
const uint8_t RELAY2_PIN = 7U;
const uint8_t RELAY3_PIN = 8U;
const uint8_t RELAY4_PIN = 12U;

// Variables for the sequencer
const uint8_t SWITCH_PIN = 2U;    // Switch on the front panel
const uint8_t WSJT_PIN   = 3U;    // Input from WSJT

const uint8_t RELAYS_PIN = RELAY1_PIN;
const uint8_t PA_PIN     = RELAY2_PIN;
const uint8_t PTT_PIN    = RELAY3_PIN;

const unsigned long DELAY_MS = 50UL;

const unsigned long DEBOUNCE_MS = 50UL;
unsigned long _time = 0UL;
bool _debouncing = false;

bool _serialState = false;
bool _switchState = false;
  
void setup()
{
  Serial.begin(9600);

  // Setup sequencer
  pinMode(SWITCH_PIN, INPUT_PULLUP);
  pinMode(WSJT_PIN,   INPUT);

  pinMode(RELAYS_PIN, OUTPUT);
  pinMode(PA_PIN,     OUTPUT);
  pinMode(PTT_PIN,    OUTPUT);

  digitalWrite(RELAYS_PIN, LOW);
  digitalWrite(PA_PIN,     LOW);
  digitalWrite(PTT_PIN,    LOW);
}
  
void loop()
{
  // Code for sequencer
  bool serialState = (digitalRead(WSJT_PIN) == HIGH);
  bool switchState = _switchState;
 
  bool state = (digitalRead(SWITCH_PIN) == LOW);
  if ((state != _switchState) && !_debouncing) {
    _time = millis();
    _debouncing = true;
  }

  if (_debouncing) {
    if (millis() > (_time + DEBOUNCE_MS)) {
      switchState = (digitalRead(SWITCH_PIN) == LOW);
      _debouncing = false;
    }
  }

  if ((serialState != _serialState) || (switchState != _switchState)) {
    if (serialState || switchState) {
      digitalWrite(RELAYS_PIN, HIGH);
      delay(DELAY_MS);
      digitalWrite(PA_PIN, HIGH);
      delay(DELAY_MS);
      digitalWrite(PTT_PIN, HIGH);
    } else {
      digitalWrite(PTT_PIN, LOW);
      delay(DELAY_MS);
      digitalWrite(PA_PIN, LOW);
      delay(DELAY_MS);
      digitalWrite(RELAYS_PIN, LOW); 
    }

    _switchState = switchState;
    _serialState = serialState;
  }
}
