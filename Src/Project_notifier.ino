// IFTTT SMS Version of the Code
// All of the following includes are for WIFI
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <WiFiManager.h>        

// MQTT IOT Includes
#include <IFTTTWebhook.h>

const char* ifttt_key = "7hWCwDwmUGOrCCGdM_VGh";
const char* ifttt_event_name = "MailboxDelivered";

WiFiClientSecure client;

const char* host = "maker.ifttt.com";
// current fingerprint can be found on a *nix system with the following command
// echo | openssl s_client -connect maker.ifttt.com:443 |& openssl x509 -fingerprint -noout
const char fingerprint[] PROGMEM = "AA 75 CB 41 2E D5 F9 97 FF 5D A0 8B 7D AC 12 21 08 4B 00 8C";
const String url = String("/trigger/") + ifttt_event_name + "/with/key/" + ifttt_key;
const int httpsPort = 443;

// enable reading battery voltage
ADC_MODE(ADC_VCC);
// code for the the photo resistor to be activate the SMS trigger
int analogInput = A0; //read the value from analog input
int sensorValue = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); // Starts the serial communication

  // Connect to WiFi
  Serial.print("\n\nConnecting Wifi... ");
  WiFiManager wifiManager;
  // uncomment the next line to clear all saved settings
  //wifiManager.resetSettings();
  wifiManager.autoConnect("MailboxSensorSetup");

  // Connected
  Serial.print("My Wifi IP is: ");
  Serial.println(WiFi.localIP());

  // main code
  // trigger webhook
  Serial.println("connecting to IFTTT");
  Serial.print("connecting to ");
  Serial.println(host);
  client.setFingerprint(fingerprint);
  if (!client.connect(host, httpsPort)) {
    Serial.println("connection failed");
    return;
  }

  if (client.verify(fingerprint, host)) {
    Serial.println("certificate matches");
  } else {
    Serial.println("certificate doesn't match");
  }

  // for a trustfire 14500 I want to send myself a low battery warning @ just under 3.5 volts.
  Serial.print("Read VCC: ");
  Serial.println(ESP.getVcc());

  client.print(String("POST ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "User-Agent: ESP8266Mailbox\r\n" +
               "Connection: close\r\n\r\n");

  Serial.println("request sent");
  while (client.connected()) {
    String line = client.readStringUntil('\n');
    if (line == "\r") {
      Serial.println("headers received");
      break;
    }
  }
  String line = client.readStringUntil('\n');
  if (line.startsWith("{\"state\":\"success\"")) {
    Serial.println("esp8266/Arduino CI successfull!");
  } else {
    Serial.println("esp8266/Arduino CI has failed");
  }
  Serial.println("reply was:");
  Serial.println("==========");
  Serial.println(line);
  Serial.println("==========");
  Serial.println("closing connection");

  Serial.println("Triggered event, going to sleep");
  //deep sleep until reset
  ESP.deepSleep(0);

  //photo resistor
  pinMode (0,1, OUTPUT);
  pinMode (A0, INPUT);
}

void loop() {
  sensorValue = analogRead(analogInput);
  Serial.println(sensorValue);
  //condition for the SMS to be sent
  if (sensorValue > 700)
  {
    digitalWrite(0,1, HIGH);
    client.print(String("POST ") + url + " HTTP/1.1\r\n" +
                 "Host: " + host + "\r\n" +
                 "User-Agent: ESP8266Mailbox\r\n" +
                 "Connection: close\r\n\r\n");
  }
  //condition for the Device to go to sleep mode
  else
  {
    digitalWrite(0,1, LOW);
    ESP.deepSleep(0)
  }
}
