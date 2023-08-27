#include <SoftwareSerial.h>
SoftwareSerial mySerial(3, 2);
int emgPin = A0;
int prev emg value=0;
int emgValue =0;
int diff=0;
int signal emg=0;
int old millis=0;
int action=0;
void setup()
{
mySerial.begin(9600);
Serial.begin(9600);
mySerial.print(”*A67*B90*C0*D0*E0*”);
pinMode(emgPin,INPUT);
}
void loop()
{
if (Serial.available()>0)
String c = Serial.readString();
delay(100);
c.trim();
mySerial.print(c);
}
emgValue = analogRead(emgPin);
diff=emgValueprev emg value;
if(diff>350)
{
//mySerial.print(”*A0*B0*C120*D120*E120*”);
signal emg=255;
}
Serial.print(”emgValue = ”);
Serial.print(emgValue);
Serial.print(” t signal emg = ”);
Serial.println(signal emg);
prev emg value=emgValue;
delay(100);
if(millis()- old millis>5000)
{
if(signal emg==255)
{
signal emg=0;
if(action==0)
{
mySerial.print(”*A0*B90*C0*D0*E0*”);
action=1;
}
else if(action==1)
{
mySerial.print(”*A0*B0*C0*D0*E0*”);
action=2;
}
else if(action==2)
{
mySerial.print(”*A0*B0*C120*D0*E0*”);
action=3;
}
else if(action==3)
{
mySerial.print(”*A0*B0*C120*D120*E0*”);
action=4;
}
else if(action==4)
{
mySerial.print(”*A0*B0*C120*D120*E120*”);
action=5;
}
else if(action==5)
{
mySerial.print(”*A0*B0*C120*D120*E0*”);
action=6;
}
else if(action==6)
{
mySerial.print(”*A0*B0*C120*D0*E0*”);
action=7;
}
else if(action==7)
{
mySerial.print(”*A0*B0*C0*D0*E0*”);
action=8;
}
else if(action==8)
{
mySerial.print(”*A0*B120*C0*D0*E0*”);
action=9;
}
else if(action==9)
{
mySerial.print(”*A67*B120*C0*D0*E0*”);
action=0;
}
}
old millis=millis();
signal emg=0;
}
