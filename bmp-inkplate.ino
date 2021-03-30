#include "HTTPClient.h"
#include "Inkplate.h"
#include "WiFi.h"
Inkplate display(INKPLATE_1BIT); // Create an object on Inkplate library and also set library into 1 Bit mode (BW)

// NOTE: You can specify those macro via 'aruduino-cli --build-property build.extra_flags='
//   e.g. --build-property "build.extra_flags=\"-DMY_SSID=\"$$SSID\"\" \"-DMY_SSID_PASS=\"$$SSID_PASS\"\""
const char *ssid = MY_SSID;     // Your WiFi SSID
const char *password = MY_SSID_PASS; // Your WiFi password

void setup() {
  display.begin();
  display.clearDisplay();
  display.display();

  display.print("Connecting to WiFi...");
  display.partialUpdate();

  // Connect to the WiFi network.
  WiFi.mode(WIFI_MODE_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    display.print(".");
    display.partialUpdate();
  }
  display.println("\nWiFi OK! Downloading...");
  display.partialUpdate();

  if (!display.drawImage("https://bmp-server.herokuapp.com/test.bmp", 0, 0, false, false)) {
    // If is something failed (wrong filename or wrong bitmap format), write error message on the screen.
    // REMEMBER! You can only use Windows Bitmap file with color depth of 1, 4, 8 or 24 bits with no compression!
    display.println("Image open error");
    display.display();
  }
  display.display();
}

void loop() {
  // Nothing...
}
