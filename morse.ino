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

String morsify(String input) {
  String morse_string = "";
  
  for(int i = 0; i < input.length(); i++) {
    if(input[i] == ' ') {
      continue;
    }
    
    int charIdx = input[i] % 97; // Mod char by 97 to get its index in array (ex => 'a' % 97 is 0 and 'b' % 97 is 2 etc.)

    morse_string.concat(morse[charIdx]);
    morse_string.concat(" ");
  }

  Serial.println(morse_string);
  return morse_string;
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
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(MORSE_PIN, OUTPUT);
  Serial.begin(9600);
  MORSE = morsify(MESSAGE);
}

// the loop function runs over and over again forever
void loop() {
// digitalWrite(MORSE_PIN, HIGH);   // turn the LED on (HIGH is the voltage level)
// delay(500);                       // wait for a second
// digitalWrite(MORSE_PIN, LOW);    // turn the LED off by making the voltage LOW
//  delay(500);    // wait for a second

  read_morse(MORSE);

  delay(1500);
}