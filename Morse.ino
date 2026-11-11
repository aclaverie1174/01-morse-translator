
String sentence = "";
String alphabet[] = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", ".", "?", ",", "!", "="};
String morse[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-",
                   ".--", "-..-", "-.--", "--..", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----", ".-.-.-",
                   "..--..", "--..--", "-.-.--", "-...-"};
const int unit=100;


void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  Serial.println(" ");
  Serial.println("Type a sentence that you want in morse code:");
  while (Serial.available() == 0) {}
  sentence = Serial.readStringUntil('\n');
  sentence.trim();
  Serial.println("You typed: " + sentence);
  sentence.toUpperCase();
  Serial.flush();
  Serial.end();
  delay(3000);
    for (int i = 0; i < sentence.length(); i++) {
      String c = sentence.substring(i, i + 1);
      if (c == " ") {
        delay(unit*8);
        continue;
      }
      int idx = -1;
      for (int j = 0; j < 41; j++) {
        if (c.equals(alphabet[j])) {
          idx = j;
          break;
        }
      }
      if (idx == -1)
        continue;
      String e = morse[idx];
      for (int k = 0; k < e.length(); k++) {
        String p = e.substring(k, k + 1);
        if (p.equals(".")) {
          digitalWrite(LED_BUILTIN, HIGH);
          delay(unit*2);
          digitalWrite(LED_BUILTIN, LOW);
        } else if (p.equals("-")) {
          digitalWrite(LED_BUILTIN, HIGH);
          delay(unit*6);
          digitalWrite(LED_BUILTIN, LOW);
        }
        delay(unit*2);
      }
      delay(unit*4);
    }
}


void loop() {
}
