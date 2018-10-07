#include <Arduino.h>
#include <Ethernet.h>
#include <EthernetUdp.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>


ESP8266WebServer server(80);

void setPort(String portName, int value){
    if (portName == "D0"){
        digitalWrite(D0, value);
    }
    if (portName == "D1"){
        digitalWrite(D1, value);
    }
    if (portName == "D2"){
        digitalWrite(D2, value);
    }
    if (portName == "D3"){
        digitalWrite(D3, value);
    }
    if (portName == "D4"){
        digitalWrite(D4, value);
    }
    if (portName == "D5"){
        digitalWrite(D5, value);
    }
    if (portName == "D6"){
        digitalWrite(D6, value);
    }
    if (portName == "D7"){
        digitalWrite(D7, value);
    }
    if (portName == "D8"){
        digitalWrite(D8, value);
    }
}

void handleRootPath() {
    String response = "";
    for (int i = 0; i < server.args(); i++){
        int sig;
        String argName = server.argName(i);
        response += "Port " + argName + " set to " + server.arg(i) + "\n";
        if (server.arg(i) == "1"){
            sig = HIGH;
        }
        else {
            sig = LOW;
        }
        setPort(argName, sig);
    }
    server.send(200, "text/plain", response);
}

void setup() {
    Serial.begin(115200);
    WiFi.begin("^^^^^^^", "^^^^^^^");
    while (WiFi.status() != WL_CONNECTED) {   //Wait for connection
        delay(1000);
        Serial.println("Waiting to connect...");
    }
    Serial.println(WiFi.localIP());
    pinMode(D0, OUTPUT);
    pinMode(D1, OUTPUT);
    pinMode(D2, OUTPUT);
    pinMode(D3, OUTPUT);
    pinMode(D4, OUTPUT);
    pinMode(D5, OUTPUT);
    pinMode(D6, OUTPUT);
    pinMode(D7, OUTPUT);
    pinMode(D8, OUTPUT);
    server.on("/", handleRootPath);
    server.begin();
}

void loop() {
    server.handleClient();
}
