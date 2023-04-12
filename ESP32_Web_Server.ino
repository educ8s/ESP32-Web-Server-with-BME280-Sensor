    /////////////////////////////////////////////////////////////////
   //         ESP32 Web Server Project  v1.00                     //
  //       Get the latest version of the code here:              //
 //         http://educ8s.tv/esp32-web-server                   //
/////////////////////////////////////////////////////////////////


#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>  //https://github.com/bbx10/WebServer_tng
#include "Adafruit_BME280.h" //https://github.com/Takatsuki0204/BME280-I2C-ESP32

WebServer server ( 80 );

const char* ssid     = "yourSSID";
const char* password = "yourPassword";
#define ALTITUDE 216.0 // Altitude in Sparta, Greece

#define I2C_SDA 27
#define I2C_SCL 26
#define BME280_ADDRESS 0x76  //If the sensor does not work, try the 0x77 address as well
int LEDPIN = 32;

float temperature = 0;
float humidity = 0;
float pressure = 0;

String  ledState = "OFF";

Adafruit_BME280 bme(I2C_SDA, I2C_SCL);

void setup() 
{
  pinMode(LEDPIN, OUTPUT);
  
  Serial.begin(9600);

  initSensor();

  connectToWifi();

  beginServer();
}

void loop() {
 
 server.handleClient();
 
 getTemperature();
 getHumidity();
 getPressure();
 delay(1000);
 
}

void connectToWifi()
{
  WiFi.enableSTA(true);
  
  delay(2000);

  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void beginServer()
{
  server.on ( "/", handleRoot );
  server.begin();
  Serial.println ( "HTTP server started" );
}

void handleRoot(){ 
  if ( server.hasArg("LED") ) {
    handleSubmit();
  } else {
    server.send ( 200, "text/html", getPage() );
  }  
}

void initSensor()
{
  bool status = bme.begin(BME280_ADDRESS);
  if (!status) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }
}

float getTemperature()
{
  temperature = bme.readTemperature();
}

float getHumidity()
{
  humidity = bme.readHumidity();
}

float getPressure()
{
  pressure = bme.readPressure();
  pressure = bme.seaLevelForAltitude(ALTITUDE,pressure);
  pressure = pressure/100.0F;
}

void handleSubmit() {

  String LEDValue;
  LEDValue = server.arg("LED");
  Serial.println("Set GPIO "); 
  Serial.print(LEDValue);
  
  if ( LEDValue == "1" ) {
    digitalWrite(LEDPIN, HIGH);
    ledState = "On";
    server.send ( 200, "text/html", getPage() );
  }
  else if( LEDValue == "0" ) 
  {
    digitalWrite(LEDPIN, LOW);
    ledState = "Off";
    server.send ( 200, "text/html", getPage() );
  } else 
  {
    Serial.println("Error Led Value");
  }
}

String getPage(){
  String page = "<html lang=en-EN><head><meta http-equiv='refresh' content='60'/>";
  page += "<title>ESP32 WebServer - educ8s.tv</title>";
  page += "<style> body { background-color: #fffff; font-family: Arial, Helvetica, Sans-Serif; Color: #000000; }</style>";
  page += "</head><body><h1>ESP32 WebServer</h1>";
  page += "<h3>BME280 Sensor</h3>";
  page += "<ul><li>Temperature: ";
  page += temperature;
  page += "&deg;C</li>";
  page += "<li>Humidity: ";
  page += humidity;
  page += "%</li>";
  page += "<li>Barometric Pressure: ";
  page += pressure;
  page += " hPa</li></ul>";
  page += "<h3>GPIO</h3>";
  page += "<form action='/' method='POST'>";
  page += "<ul><li>LED";
  page += "";
  page += "<INPUT type='radio' name='LED' value='1'>ON";
  page += "<INPUT type='radio' name='LED' value='0'>OFF</li></ul>";
  page += "<INPUT type='submit' value='Submit'>";

  page += "</body></html>";
  return page;
}
