//project done by www.theorycircuit.com
//code by Crenn from http://thebestcasescenario.com  thank you!
//Varibles used for calculations
int NbTopsFan;
int calc;

//The pin location of the sensor
int hallsensor = 2; 

//Defines the structure for multiple fans and 
//their dividers 
typedef struct{
    char fantype;
    unsigned int fandiv; 
} fanspec;
 
//Definitions of the fans
//This is the varible used to select the fan and it's divider,
//set 1 for unipole hall effect sensor
//and 2 for bipole hall effect sensor
fanspec fanspace[3] = {{0,1},{1,2},{2,8}}; 
char fan = 1;
 
//This is the function that the interupt calls
void rpm ()
{
    NbTopsFan++;
}
 
//This is the setup function where the serial port is initialised,
//and the interrupt is attached
void setup()
{
    pinMode(hallsensor, INPUT_PULLUP);
    Serial.begin(9600);
    attachInterrupt(0, rpm, RISING);
}
 
void loop ()
{
    //Set NbTops to 0 ready for calculations
    NbTopsFan = 0;
    //Enables interrupts
    sei();
 
    //Wait 1 second
    delay (1000);
 
    //Disable interrupts
    cli();
 
    //Times NbTopsFan (which is apprioxiamately the fequency the fan 
    //is spinning at) by 60 seconds before dividing by the fan's divider
    calc = ((NbTopsFan * 60) / fanspace[fan].fandiv);

    if (Serial.available()) { 
        //Prints the number calculated above
        Serial.print("calc = ");
        Serial.print (calc, DEC);
        Serial.println (" rpm");
    }
} 
