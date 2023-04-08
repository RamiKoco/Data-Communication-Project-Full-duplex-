//SPI MASTER CODE
#include<SPI.h> //Library for SPI #include <LiquidCrystal.h>
#define LED 9 //Led pin
#define ipbutton 2 //Buttin pin int buttonvalue;
int x;
String ogrenciisimleri[60] = { "Rami ", "Ilknur ", "Kagan ","Ali ","Veli ","Mehmet ","Ahmet ","Murat ","Harun ","Yunus ","Meltem ",
"Selin
","Hulya
","Cihan
","Ruya
","Mert ","Berk
","Aziz ","Sevim
","Samet ","Halil
","Ezgi ",
","Hasan
","Efe
","Can
"Tarik ","Kamil
","Merve
","Cemal
","Zeynep
","Kemal
","Gamze
","Hayri
","Buse ","Bilal
","Berkay ",
","Recep
","Mete
","Burak
"Mesut ","Alper ","Erol ","Fikri ","Zeki ","Candar ","Hilal ","Hayati ","Gulay ","Esma ","Esra ","Aytekin ","Ramiz ","Rasim ",
"Derya ","Yasemin ","Mehtap ","Bayram ","Fatma ","Ahmet ","Sude "}; LiquidCrystal lcd(8, 7, 6, 5, 4, 3);
int sayi;
void setup (void)
{
Serial.begin(115200); //Starts Serial Communication at Baud Rate 115200 lcd.begin(16, 2);
pinMode(ipbutton,INPUT); //Sets pin 2 as input pinMode(LED,OUTPUT); //Sets pin 7 as Output
SPI.begin(); //Begins the SPI commnuication
SPI.setClockDivider(SPI_CLOCK_DIV8); //Sets clock for SPI communication at 8 that's mean 16/8 = 2Mhz for the frequency
digitalWrite(SS,HIGH); //Setting SlaveSelect "SS" as HIGH
//randomSeed(analogRead(A0));
}
void loop(void)
{
byte Mastersend,Mastereceive;
buttonvalue = digitalRead(ipbutton); //Reads the status of the pin 2
if(buttonvalue == HIGH) //Logic for Setting x value depending upon input from pin 2
{
x = 1;
}
else
{
x = 0;
}
digitalWrite(SS, LOW); //Starts communication with Slave connected to master
Mastersend = x;
Mastereceive=SPI.transfer(Mastersend); //Send the mastersend value to slave also receives value from slave
Serial.println(Mastereceive);
if(Mastereceive == 1) //Logic for setting the LED output depending upon value received from slave
{
digitalWrite(LED,HIGH); //Sets pin 7 HIGH Serial.println("Master LED ON");
lcd.setCursor(0, 0);
//lcd.print("Master LED ON ");
// randomSeed(analogRead(A0)); sayi = random(0,60); lcd.print(ogrenciisimleri[sayi]);
}
else
{
digitalWrite(LED,LOW); //Sets pin 7 LOW Serial.println("Master LED OFF"); lcd.setCursor(0, 0);
lcd.print("Master OFF ");
}
delay(1000);
}
