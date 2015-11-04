
#include <SoftwareSerial.h>
#include <espduino.h>
#include <rest.h>




char host[] = "requestb.in";
char url[] = "/rff4ghrf";
char ssid[] ="aslak";
char password[] = "aslakkalsa";



void setup() {
  Serial.begin(19200);
  
  connectWifi();
}

void loop() {

  doGet();
  delay(1000);
  
}

/*************** WIFI hjelpekode *******************/
SoftwareSerial espPort(11,10); // RX, TX

ESP esp(&espPort, 4);
REST rest(&esp);

boolean wifiConnected = false;

bool doGet(){
  char response[266];
  esp.process();
  if(wifiConnected) {
    rest.get(url);
    if(rest.getResponse(response, 266) == HTTP_STATUS_OK){
      Serial.println("RESPONSE: ");
      Serial.println(response);
      return true;
    }
  }

  return false; 
}

void connectWifi(){
  espPort.begin(19200);
  esp.enable();
  delay(500);
  esp.reset();
  delay(500);
  while(!esp.ready());

  if(!rest.begin(host)) {
    while(1);
  }

  /*setup wifi*/
  Serial.println("ARDUINO: setup wifi");
  esp.wifiCb.attach(&wifiCb);
  esp.wifiConnect(ssid,password);
  Serial.println("ARDUINO: system started");
}

void wifiCb(void* response)
{
  uint32_t status;
  RESPONSE res(response);
  Serial.println("CONNECTING WIFI");
  if(res.getArgc() == 1) {
    res.popArgs((uint8_t*)&status, 4);
    if(status == STATION_GOT_IP) {
      Serial.println("WIFI CONNECTED");
      wifiConnected = true;
    } else {
      wifiConnected = false;
      Serial.println("WIFI NOT CONNECTED");
    }
  }
}

/*************** WIFI hjelpe kode *******************/

