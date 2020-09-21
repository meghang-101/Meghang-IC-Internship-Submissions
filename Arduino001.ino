#include <WiFiNINA.h>

//These characters are used to connect to the home wifi
char ssid[] = "myHomeWIFI";
char pass[] = "12345";

int status = WL_IDLE_STATUS;

//This character is our Server Address
char server[] = "www.meghangtheintern.com";

String postData; //This is the string that is going to be posted
String postVarialble = "post= ";
WiFiClient client;

int i = 0;

void setup() {
  Serial.begin(9600); //Setting up baud rate for serial communication
  
  //Connecting to WIFI
  while (status != WL_CONNECTED) { 
    Serial.print("Connecting to WIFI...") 
    status = WiFi.begin(ssid, pass);
    delay(10000);
  }

  Serial.println("Connected to WIFI: ")
  Serial.print(WiFi.ssid)

  //Getting Local and Gataway IP Address
  IPAddress localIP = WiFi.localIP();
  IPAddress gatewayIP = WiFi.gatewayIP();

}

void loop() {
  i++;
  postData = postVarialble + i;

  if (client.connect(server, 80)) {
    client.println("POST /test/post.php HTTP/1.1");
    client.println("Host: www.meghangtheintern.com");
    client.println("Content-Type: application/x-www-form-urlencoded");
    client.print("Content-Length: ");
    client.println(postData.length());
    client.println();
    client.print(postData);
  }

  if(client.connected()) {
    client.stop();
  }

  Serial.println(postData);
  delay(1000);
}
