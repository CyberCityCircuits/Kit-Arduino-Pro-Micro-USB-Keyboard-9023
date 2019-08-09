//****************************************************
//This is for the Keyboard Matrix for sale
//on Tindie.com from David Ray Electronics and More.
//This is built around the Arduino Pro Micro.
//Use this any way you see fit.
//www.DREAM-Enterprise.com
//****************************************************

#include <Keypad.h>
#include <Keyboard.h>

int CAPS_LED = 19;
int SYMB_LED = 18;

int CAPSLOCK = 0;
int SYMBLOCK = 0;

const byte ROWS = 4;
const byte COLS = 10;

byte rowPins[ROWS] = {10, 16, 14, 15}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0}; //connect to the column pinouts of the keypad

//KEY LAYOUT
//           COL1  COL2  COL3  COL4  COL5  COL6  COL7  COL8  COL9  COL10
//           PIN9  PIN8  PIN7  PIN6  PIN5  PIN4  PIN3  PIN2  PIN1  PIN0
//ROW1 PIN10 Q     W     E     R     T     Y     U     I     P     O
//ROW2 PIN16 A     S     D     F     G     H     J     K     bck   L
//ROW3 PIN14 shf   Z     X     C     V     B     N     M     ent   =
//ROW4 PIN15 ctrl  alt   caps  symb  del   spc   left  up    down  right

//SYMBOL LAYOUT
//           COL1  COL2  COL3  COL4  COL5  COL6  COL7  COL8  COL9  COL10
//           PIN9  PIN8  PIN7  PIN6  PIN5  PIN4  PIN3  PIN2  PIN1  PIN0
//ROW1 PIN10 #     1     2     3     (     )     _     -     @     +
//ROW2 PIN16 *     4     5     6     /     :     ;     '     bck   "
//ROW3 PIN14 0     7     8     9     ?     !     ,     .     ent   $
//ROW4 PIN15 ctrl  alt   caps  symb  del   spc   left  up    down  right

byte keys[ROWS][COLS] = {
  { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
  {11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
  {21, 22, 23, 24, 25, 26, 27, 28, 29, 30},
  {31, 32, 33, 34, 35, 36, 37, 38, 39, 40}
};

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {

  Serial.begin(9600);
  pinMode(CAPS_LED, OUTPUT);
  pinMode(SYMB_LED, OUTPUT);

  digitalWrite (CAPS_LED, HIGH); digitalWrite (SYMB_LED, HIGH); delay(250);
  digitalWrite (CAPS_LED, LOW); digitalWrite (SYMB_LED, LOW); delay(250);

  digitalWrite (CAPS_LED, HIGH); digitalWrite (SYMB_LED, HIGH); delay(250);
  digitalWrite (CAPS_LED, LOW); digitalWrite (SYMB_LED, LOW); delay(250);

  digitalWrite (CAPS_LED, HIGH); digitalWrite (SYMB_LED, HIGH); delay(250);
  digitalWrite (CAPS_LED, LOW); digitalWrite (SYMB_LED, LOW); delay(250);

  Keyboard.begin();

}

void loop() {
  
  if (CAPSLOCK == 1){digitalWrite(CAPS_LED, HIGH);
  } else{digitalWrite(CAPS_LED,LOW);}

  if (SYMBLOCK == 1){digitalWrite(SYMB_LED, HIGH);
  } else{digitalWrite(SYMB_LED,LOW);}
 
  char key = keypad.getKey();

  if (key != NO_KEY) {

    if (key ==  1) {if (SYMBLOCK == 1){Keyboard.write('#');}else{Keyboard.write('q');}}
    if (key ==  2) {if (SYMBLOCK == 1){Keyboard.write('1');}else{Keyboard.write('w');}}
    if (key ==  3) {if (SYMBLOCK == 1){Keyboard.write('2');}else{Keyboard.write('e');}}
    if (key ==  4) {if (SYMBLOCK == 1){Keyboard.write('3');}else{Keyboard.write('r');}}
    if (key ==  5) {if (SYMBLOCK == 1){Keyboard.write('(');}else{Keyboard.write('t');}}
    if (key ==  6) {if (SYMBLOCK == 1){Keyboard.write(')');}else{Keyboard.write('y');}}
    if (key ==  7) {if (SYMBLOCK == 1){Keyboard.write('_');}else{Keyboard.write('u');}}
    if (key ==  8) {if (SYMBLOCK == 1){Keyboard.write('-');}else{Keyboard.write('i');}}
    if (key ==  9) {if (SYMBLOCK == 1){Keyboard.write('@');}else{Keyboard.write('p');}}
    if (key == 10) {if (SYMBLOCK == 1){Keyboard.write('+');}else{Keyboard.write('o');}}
    
    if (key == 11) {if (SYMBLOCK == 1){Keyboard.write('*');}else{Keyboard.write('a');}}
    if (key == 12) {if (SYMBLOCK == 1){Keyboard.write('4');}else{Keyboard.write('s');}}
    if (key == 13) {if (SYMBLOCK == 1){Keyboard.write('5');}else{Keyboard.write('d');}}
    if (key == 14) {if (SYMBLOCK == 1){Keyboard.write('6');}else{Keyboard.write('f');}}
    if (key == 15) {if (SYMBLOCK == 1){Keyboard.write('/');}else{Keyboard.write('g');}}
    if (key == 16) {if (SYMBLOCK == 1){Keyboard.write(':');}else{Keyboard.write('h');}}
    if (key == 17) {if (SYMBLOCK == 1){Keyboard.write(';');}else{Keyboard.write('j');}}
    if (key == 18) {if (SYMBLOCK == 1){Keyboard.write("'");}else{Keyboard.write('k');}}
    if (key == 19) {
      Keyboard.press(KEY_BACKSPACE); //backspace
      Keyboard.release(KEY_BACKSPACE); //backspace
    }
    if (key == 20) {if (SYMBLOCK == 1){Keyboard.write('"');}else{Keyboard.write('l');}}
    
    if (key == 21) {if (SYMBLOCK == 1){Keyboard.write('0');}else{
      Keyboard.press(KEY_LEFT_SHIFT); Keyboard.release(KEY_LEFT_SHIFT);}}
    if (key == 22) {if (SYMBLOCK == 1){Keyboard.write('7');}else{Keyboard.write('z');}}
    if (key == 23) {if (SYMBLOCK == 1){Keyboard.write('8');}else{Keyboard.write('x');}}
    if (key == 24) {if (SYMBLOCK == 1){Keyboard.write('9');}else{Keyboard.write('c');}}
    if (key == 25) {if (SYMBLOCK == 1){Keyboard.write('?');}else{Keyboard.write('v');}}
    if (key == 26) {if (SYMBLOCK == 1){Keyboard.write('!');}else{Keyboard.write('b');}}
    if (key == 27) {if (SYMBLOCK == 1){Keyboard.write(',');}else{Keyboard.write('n');}}
    if (key == 28) {if (SYMBLOCK == 1){Keyboard.write('.');}else{Keyboard.write('m');}}
    if (key == 29) {Keyboard.press(KEY_RETURN);Keyboard.release(KEY_RETURN);}
    if (key == 30) {if (SYMBLOCK == 1){Keyboard.write('$');}else{Keyboard.write('=');}}
    
    if (key == 31) {Keyboard.write(KEY_LEFT_CTRL); Keyboard.release(KEY_LEFT_CTRL);}
    if (key == 32) {Keyboard.write(KEY_LEFT_ALT);Keyboard.release(KEY_LEFT_ALT);}
    if (key == 33) {if (CAPSLOCK == 0){CAPSLOCK = 1;}else{CAPSLOCK = 0;}
                    Keyboard.press(KEY_CAPS_LOCK);Keyboard.release(KEY_CAPS_LOCK);}
    if (key == 34) {if (SYMBLOCK == 0){SYMBLOCK = 1;}else{SYMBLOCK = 0;}}
    if (key == 35) {Keyboard.press(KEY_DELETE); Keyboard.release(KEY_DELETE);}
    if (key == 36) {Keyboard.write(' ');}
    if (key == 37) {Keyboard.press(KEY_LEFT_ARROW); Keyboard.release(KEY_LEFT_ARROW);}
    if (key == 38) {Keyboard.press(KEY_UP_ARROW); Keyboard.release(KEY_UP_ARROW);}
    if (key == 39) {Keyboard.press(KEY_RIGHT_ARROW); Keyboard.release(KEY_RIGHT_ARROW);}
    if (key == 40) {Keyboard.press(KEY_DOWN_ARROW); Keyboard.release(KEY_DOWN_ARROW);}
  }
}
