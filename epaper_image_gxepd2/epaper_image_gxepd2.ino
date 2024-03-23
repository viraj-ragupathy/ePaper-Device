#define ENABLE_GxEPD2_GFX 0 // we won't need the GFX base class
//#include <GxEPD2_BW.h>
#include <GxEPD2_3C.h>
// Online tool for converting images to byte arrays:
// https://javl.github.io/image2cpp/

#include "Bitmaps.h"
#include "image1.h"
#include "image2.h"
#include "image3.h"
#include "image4.h"
#include "image5.h"
#include "image6.h"
#include "image7.h"
#include "image8.h"
#include "image9.h"
// Instantiate the GxEPD2_BW class for our display type
GxEPD2_3C<GxEPD2_750c_Z08, GxEPD2_750c_Z08::HEIGHT>

#define GxEPD2_DRIVER_CLASS GxEPD2_750c_Z08
display(GxEPD2_750c_Z08(15, 27, 26, 25));
//13, 12, 14, 15
//display(GxEPD2_750c_Z08(13, 12, 14, 15));

SPIClass hspi(HSPI);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  hspi.begin(13, 12, 14, 15); // remap hspi for EPD (swap pins)
  display.epd2.selectSPI(hspi, SPISettings(4000000, MSBFIRST, SPI_MODE0));
  // wait for display to become available
  display.init(115200);
  // display ACROBOTIC logo on the display
  drawBitmaps(pic9);
  delay(60000);
}

void loop() {
  // put your main code here, to run repeatedly:
  drawBitmaps(pic2);
  delay(60000);
  drawBitmaps(pic3);
  delay(60000);
  drawBitmaps(pic4);
  delay(60000);
  drawBitmaps(pic5);
  delay(60000);
  drawBitmaps(pic6);
  delay(60000);
  drawBitmaps(pic7);
  delay(60000);
  drawBitmaps(pic8);
  delay(60000);
  drawBitmaps(pic9);
  delay(60000);  
  // drawBitmaps(ACROBOTIC_LOGO);
  // delay(60000);
  // drawBitmaps(ACROBOTIC_LOGO);
  // delay(60000);
  // drawBitmaps(ACROBOTIC_LOGO);
  // delay(60000);
}

void drawBitmaps(const unsigned char *bitmap) {
  // Configure the display according to our preferences
  display.setRotation(0);
  display.setFullWindow();
  // Display the bitmap image
  display.firstPage();
  do {
    display.fillScreen(GxEPD_WHITE);
    display.drawInvertedBitmap(0, 0, bitmap, display.epd2.WIDTH, display.epd2.HEIGHT, GxEPD_BLACK);
  } while (display.nextPage());
}
