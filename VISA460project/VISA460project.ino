/*
  460 Project code for Nature to Nasty LED projections
  Written by: Toby Lindsay
  January 21, 2014 
*/

//Imports the Ultrasonic library which is used to get data from the Ultrasonic sensor
#include <Ultrasonic.h>

//Gives a name to each pin that describes what it's driving (to be used in later code)
#define PINETREE     A0
#define SUN          A1
#define BIRDS        2
#define POND         3
#define FACTORY      4
#define TOWER2B      5
#define TOWER2R      6
#define TREE         7
#define CAR          8
#define PLANE        9
#define DEER         10
#define BUILDING     11
#define TRIGGER_PIN  12
#define ECHO_PIN     13

//Sets up ultrasonic sensor by passing the pins used to a funtion in the library
Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);

//Creates a global variable called count and initializes it to = 0 with an integer data type
int count=0;

//Setup function is run once when the Arduino is power on or reset, used to set up the arduino
void setup()
{
    Serial.begin(9600); //Sets up serial port for debugging at 9600 baud 
    
    //Sets pins 2 to 12 as outputs using a for loop in format for(Variable; Condition; Increment)
    for(int x = 2; x!=12; x++)
    {
      pinMode(x, OUTPUT);
    }
   
    //Sets Analog pins A0 and A1 as digital outputs in the format pinMode(Pin#, Pin Type (OUTPUT/INPUT/INPUT_PULLUP))
    pinMode(A0, OUTPUT);
    pinMode(A1, OUTPUT);
    
    //Turns on all the elements of the nature scene once powered on in the format digitalWrite(pin#, (1=on or 0=off)
    digitalWrite(BIRDS,    1);
    digitalWrite(POND,     1);
    digitalWrite(TREE,     1);
    digitalWrite(DEER,     1);
    digitalWrite(PINETREE, 1);
    digitalWrite(SUN,      1);
 }

//loop function loops continuously while arduino is on 
void loop()
{ 
    /*Creates a variable named microsec with data type long (very large numbers)
      then makes it equal to the time found using the ultrasonic library's
      timing function */
    long microsec = ultrasonic.timing();  
    
    /*Creates a variable named Distance with data type float(decimal numbers)
      then makes it equal to the time converted into distance in cm using the 
      ultrasonic library's convert function */
    float Distance = ultrasonic.convert(microsec, Ultrasonic::CM);

    //Serial.println(Distance); //Prints the distance to the serial monitor (Used for debugging) commented out when not needed
   
    //Turns the nature scene on if distance is between 150-165 cm and on if > 165cm for 20 loop cycles (for stability)
    if((Distance>150 && Distance<165) || (count>20 && Distance>165))
    {
      digitalWrite(FACTORY,  0);
      digitalWrite(TOWER2B,  0);
      digitalWrite(TOWER2R,  0);
      digitalWrite(BUILDING, 0);
      digitalWrite(CAR,      0);
      digitalWrite(PLANE,    0);
      
      digitalWrite(TREE,     1);
      digitalWrite(POND,     1);
      digitalWrite(SUN,      1);
      digitalWrite(PINETREE, 1);
      digitalWrite(DEER,     1);
      digitalWrite(BIRDS,    1);
      count = 0;
    }
    
    //Runs if Distance falls between 125cm and 140cm and switches 1 element of the scene
    else if(Distance>125 && Distance<140)
    {
      digitalWrite(FACTORY,  1);
      digitalWrite(TOWER2B,  0);
      digitalWrite(TOWER2R,  0);
      digitalWrite(BUILDING, 0);
      digitalWrite(CAR,      0);
      digitalWrite(PLANE,    0);
      
      digitalWrite(TREE,     0);
      digitalWrite(POND,     1);
      digitalWrite(SUN,      1);
      digitalWrite(PINETREE, 1);
      digitalWrite(DEER,     1);
      digitalWrite(BIRDS,    1); 
      count = 0;
    }
    
    //Runs if Distance falls between 100cm and 115cm and switches 1 element of the scene
    else if(Distance>100 && Distance<115)
    {
      digitalWrite(FACTORY,  1);
      digitalWrite(TOWER2B,  1);
      digitalWrite(TOWER2R,  1);
      digitalWrite(BUILDING, 0);
      digitalWrite(CAR,      0);
      digitalWrite(PLANE,    0);
      
      digitalWrite(TREE,     0);
      digitalWrite(POND,     0);
      digitalWrite(SUN,      0);
      digitalWrite(PINETREE, 1);
      digitalWrite(DEER,     1);
      digitalWrite(BIRDS,    1);
      count = 0;
    }
    
    //Runs if Distance falls between 75cm and 90cm and switches 1 element of the scene
    else if(Distance>75 && Distance<90)
    {
      digitalWrite(FACTORY,  1);
      digitalWrite(TOWER2B,  1);
      digitalWrite(TOWER2R,  1);
      digitalWrite(BUILDING, 1);
      digitalWrite(CAR,      0);
      digitalWrite(PLANE,    0);
      
      digitalWrite(TREE,     0);
      digitalWrite(POND,     0);
      digitalWrite(SUN,      0);
      digitalWrite(PINETREE, 0);
      digitalWrite(DEER,     1);
      digitalWrite(BIRDS,    1); 
      count = 0;
    }
    
    //Runs if Distance falls between 50cm and 65cm and switches 1 element of the scene
    else if(Distance>50 && Distance<65)
    {
      digitalWrite(FACTORY,  1);
      digitalWrite(TOWER2B,  1);
      digitalWrite(TOWER2R,  1);
      digitalWrite(BUILDING, 1);
      digitalWrite(CAR,      1);
      digitalWrite(PLANE,    0);
      
      digitalWrite(TREE,     0);
      digitalWrite(POND,     0);
      digitalWrite(SUN,      0);
      digitalWrite(PINETREE, 0);
      digitalWrite(DEER,     0);
      digitalWrite(BIRDS,    1);
      count = 0;
    }
    
    //Runs if Distance falls between 25cm and 40cm and switches 1 element of the scene
    else if(Distance>25 && Distance<40)
    {
      digitalWrite(FACTORY,  1);
      digitalWrite(TOWER2B,  1);
      digitalWrite(TOWER2R,  1);
      digitalWrite(BUILDING, 1);
      digitalWrite(CAR,      1);
      digitalWrite(PLANE,    1);
      
      digitalWrite(TREE,     0);
      digitalWrite(POND,     0);
      digitalWrite(SUN,      0);
      digitalWrite(PINETREE, 0);
      digitalWrite(DEER,     0);
      digitalWrite(BIRDS,    0);
      count = 0;
    }
    
    //Runs if Distance falls between 0cm and 15cm and turns off all elements
    else if(Distance>0 && Distance<15)
    {
      digitalWrite(FACTORY,  0);
      digitalWrite(TOWER2B,  0);
      digitalWrite(TOWER2R,  0);
      digitalWrite(BUILDING, 0);
      digitalWrite(CAR,      0);
      digitalWrite(PLANE,    0);
      
      digitalWrite(TREE,     0);
      digitalWrite(POND,     0);
      digitalWrite(SUN,      0);
      digitalWrite(PINETREE, 0);
      digitalWrite(DEER,     0);
      digitalWrite(BIRDS,    0);
      count = 0;
    }
    
    //will increment count if it doesn't fall into any of the ranges
    else
    {
      count++;
    }
  }
