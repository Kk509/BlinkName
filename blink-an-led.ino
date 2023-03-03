// In this tutorial, we're using the blue D7 LED (next to D7 on the Photon
// and Electron, and next to the USB connector on the Argon and Boron).

// We define MY_LED to be the LED that we want to blink.
const pin_t MY_LED = D7;
// We define button_pin to be the button that we want to press to blink the led.
int button_pin = D2;

// The following line is optional, but recommended in most firmware. It
// allows your code to run before the cloud is connected. In this case,
// it will begin blinking almost immediately instead of waiting until
// breathing cyan,
SYSTEM_THREAD(ENABLED);

// Flash the D7 led n number of times.
// A dot in morse code lasts for 1 time unit. (In this code, 1 time unit = 0.5s)
// The space between each dot and dash of the same letter lasts for 0.5s.
void dot(int n)
{
    for (int i = 0; i < n; i++)
    {
        // Turn on LED
        digitalWrite(MY_LED, HIGH);
        
        // Leave it on for half a second
        delay(500ms);
        
        // Turn it off
        digitalWrite(MY_LED, LOW);
        
        // Wait half a second
        delay(500ms);    
    }
}

// Flash the D7 led n number of times.
// A dash in morse code lasts for 3 time units. (In this code, 3 time unit = 1.5s)
// The space between each dot and dash belonging to the same letter lasts for 0.5s.
void dash(int n)
{
    for (int i = 0; i < n; i++)
    {
        // Turn on LED
        digitalWrite(MY_LED, HIGH);
        
        // Leave it on one and a half seconds
        delay(1500ms);
        
        // Turn it off
        digitalWrite(MY_LED, LOW);
        
        // Wait half a second
        delay(500ms);
    }
}

// Using morse code to flash name
// Kim -.- .. --
void morse()
{
    dash(1);
    dot(1);
    dash(1);
    
    delay(1000ms);
    dot(2);
    
    delay(1000ms);
    dash(2);
}

// The setup() method is called once when the device boots.
void setup()
{
	// In order to set a pin, you must tell Device OS that the pin is
	// an OUTPUT pin. This is often done from setup() since you only need
	// to do it once.
	pinMode(MY_LED, OUTPUT);
	
	// button == HIGH (not pushed down)
	pinMode(button_pin, INPUT_PULLUP);
	
}

// The loop() method is called frequently.
void loop()
{
    // read whether the button in pressed or not
    int button = digitalRead(button_pin);
    
    // if button is pressed
    if(button == LOW)
    {
        morse();
    }
}
