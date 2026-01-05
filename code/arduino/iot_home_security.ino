#define BLYNK_TEMPLATE_ID "TMPL3poq1RItJ" 
#define BLYNK_TEMPLATE_NAME "IOT HOME SECURE" 
#define BLYNK_AUTH_TOKEN "zROVir4rj87WFu7DZSNubUmkaUJqez3V” 
#include <LiquidCrystal.h> 
#include <ESP8266_Lib.h> 
#include <SoftwareSerial.h> 
LiquidCrystal lcd( A0, A1, A2, A3, A4, A5);//rs, en, d4, d5, d6, d7 
SoftwareSerial esp12(2,3); // RX, TX 
#define LDR     8 
#define FLAME   9  
#define SMOKE   10 
#define IR      
11 
char ssid[] = "Magni5"; 
char pass[] = "JHK5@magni5"; 
String ir,smoke,fire,ldr; 
#define EspSerial Serial 
#define ESP8266_BAUD 115200 
BlynkTimer timer; 
ESP8266 wifi(&EspSerial); 
void setup() 
{ 
79 
pinMode(LDR, INPUT); 
pinMode(FLAME, INPUT); 
pinMode(SMOKE, INPUT); 
pinMode(IR, INPUT); 
// Debug console 
//Serial.begin(9600); 
lcd.begin(16, 2); 
lcd.setCursor(0, 0); 
lcd.print("IOT Based       
lcd.setCursor(0, 1); 
"); 
lcd.print("Home Security   "); 
delay(3000); 
lcd.clear(); 
lcd.setCursor(0, 0); 
lcd.print("Light:Yes ");//7 
lcd.setCursor(9, 0); 
lcd.print("Flame:X");//15 
lcd.setCursor(0, 1); 
lcd.print("Smoke:Yes ");//6 
lcd.setCursor(10, 1); 
lcd.print("IR:Yes");//13 
// Set ESP8266 baud rate 
80 
EspSerial.begin(ESP8266_BAUD); 
delay(10); 
Blynk.begin(BLYNK_AUTH_TOKEN, wifi, ssid, pass); 
} 
void myTimerEvent() 
{ 
} 
Blynk.virtualWrite(ldr); 
Blynk.virtualWrite(fire); 
Blynk.virtualWrite(smoke); 
Blynk.virtualWrite(ir); 
void loop() 
{ 
Sensors_GetData(); 
Blynk.run(); 
myTimerEvent(); 
delay(2000); 
} 
void Sensors_GetData() 
{    
if(!digitalRead(LDR)) 
{ 
//Serial.println("Light Detected"); 
ldr="Day";   
81 
lcd.setCursor(6, 0); 
lcd.print("Day");//7 
} 
if(digitalRead(LDR)) 
{ 
//Serial.println("No Light"); 
ldr="Night";   
lcd.setCursor(6, 0); 
lcd.print("Ngt");//7  
} 
if(!digitalRead(FLAME)) 
{ 
//Serial.println("Fire Detected");   
fire= "Detected"; 
lcd.setCursor(15, 0); 
lcd.print("X");//15 
} 
if(digitalRead(FLAME)) 
{ 
//Serial.println("No Fire");  
fire= "No";  
lcd.setCursor(15, 0); 
82 
lcd.print("O");//15 
} 
if(!digitalRead(SMOKE)) 
{ 
//Serial.println("Smoke Detected");  
smoke= "Detected"; 
lcd.setCursor(6, 1); 
lcd.print("Yes ");//6 
} 
if(digitalRead(SMOKE)) 
{//Serial.println("No Tilt Detected");   
smoke= "No"; 
lcd.setCursor(6, 1); 
lcd.print("No  ");//6} 
if(!digitalRead(IR)) 
{//Serial.println("Person Detected");  
ir= "Detected"; 
lcd.setCursor(13, 1); 
lcd.print("Yes");//13} 
if(digitalRead(IR)) 
{//Serial.println("No Person Detected");   
ir= "Clear"; 
lcd.setCursor(13, 1); 
83 
lcd.print("No ");//13} 
}
