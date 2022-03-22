int const MORSE_PIN = 13;
String const MESSAGE = "sos";
String MORSE;

char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
String morse[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
int const MORSE_PIN = 13;
String const MESSAGE = "your mother";
String MORSE;

char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
String morse[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

void dot() {
  digitalWrite(MORSE_PIN, HIGH);
  delay(100);
  digitalWrite(MORSE_PIN, LOW);
  delay(100);
}

void dash() {
  digitalWrite(MORSE_PIN, HIGH);
  delay(300);
  digitalWrite(MORSE_PIN, LOW);
  delay(250);
}

void read_morse(String morse_code) {
  
  for(int i = 0; i < morse_code.length(); i++) {
    if(morse_code[i] == ' ') {
      delay(470);
      continue;
    }
    
    if(morse_code[i] == '.') {
      dot();
    } else {
      dash();
    }
    
  }
  
}

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}