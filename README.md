#01-morse-translator

A lightweight Arduino script that translates text input from the Serial Monitor into visual Morse code flashes using an LED. Supports letters (A-Z), numbers (0-9), and common punctuation (`.`, `?`, `,`, `!`, `=`).

How It Works

1. Open the **Serial Monitor** in the Arduino IDE (set to **9600 baud**).
2. Type a sentence when prompted and press Enter.
3. The board reads your text and blinks out the translation using its configured LED pin (`LED_BUILTIN`).

Customizing Speed & Timings

You can easily adjust how fast or slow the Morse code plays by modifying the `unit` variable and the delay multipliers at the top of the code
