This library is a fork of the excellent Adafriut TFTLCD-Library. It is for testing a very cheap Chinese 2.8 inch touch screen shield for an Arduino Uno from www.mcufriend.com - absolutely no connection with Adafruit whatsoever.

There is no documentation and the driver supplied by Mcufriend is for V0022 of the Arduino IDE plus it's for a different graphics chip set altogether so doesn't work at all.

The chip is actually a Himax HX8347A (note, the A is important - it is not compatible with the D and G variants of the same chip family).

Current state of play:
The display will boot and run through all of the library tests in the "graphicstest" example but the colours are incorrect. I've tried numerous approaches but it looks to me like the chip has been solder-configured to
have a 16 bit interface but the shield only provides access to 8 bits. So you can have lots of blue and some green or lots of red and some green depending upon your chip initialisation parameters.

Below is the original Adafruit README.txt file.

This is a library for the Adafruit 2.8" TFT display.
This library works with the Adafruit 2.8" TFT Breakout w/SD card
  ----> http://www.adafruit.com/products/335
as well as Adafruit TFT Touch Shield
  ----> http://www.adafruit.com/products/376
 
Check out the links above for our tutorials and wiring diagrams.
These displays use 8-bit parallel to communicate, 12 or 13 pins are required
to interface (RST is optional).
Adafruit invests time and resources providing this open source code,
please support Adafruit and open-source hardware by purchasing
products from Adafruit!

Written by Limor Fried/Ladyada for Adafruit Industries.
MIT license, all text above must be included in any redistribution

To download. click the DOWNLOADS button in the top right corner, rename the uncompressed folder Adafruit_TFTLCD. Check that the Adafruit_TFTLCD folder contains Adafruit_TFTLCD.cpp and Adafruit_TFTLCD.

Place the Adafruit_TFT library folder your <arduinosketchfolder>/libraries/ folder. You may need to create the libraries subfolder if its your first library. Restart the IDE

Also requires the Adafruit_GFX library for Arduino. https://github.com/adafruit/Adafruit-GFX-Library
