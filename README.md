This project shows how to work with NeoPixel + ESP8266 using PlatformIO + FastLED library and CLion IDE.

Project is supplementary material for my [ESP8266 + NEO Pixel](https://chukovskij.wordpress.com/2018/08/12/esp8266-neo-pixel) blog post.

# Perquisites
You may use any IDE and toolchain for IoT coding, e.g. Arduino IDE. My preferred way is to use [CLion](https://www.jetbrains.com/clion) by JetBrains 
as and IDE + [PlatformIO](https://platformio.org) as toolchain (compiler, SDK, ..).  

For this project please install:
* PlatformIO (https://platformio.org), python 2.7 is required
* CLion IDE (https://www.jetbrains.com/clion)

Used hardware:
* ESP8266 module (this project configured for 'WeMos D1 Mini' or 'LoLin NodeMCU 3')
* WS2811 Neo Pixel LEDs or WS2812B LEDs strip

# Setup
* After you cloned git repo run in terminal
```
$ cd $YOUR_CLONED_PROJECT_DIR$
$ pio init --ide clion
```
This will configure project files for CLion Code Insight features support

* Wire your micro controller and Neo Pixels as shown in by blog post or see files
`./doc/esp8266_ws2811_wiring.png` or `./doc/esp8266_ws2812B_stripe_wiring.png`

* Open CLion IDEA, chose "File | Open..." dialog to open this project

# Upload FW

In CLion chose `PLATFORMIO_UPLOAD` target (see `doc/clion_platformion_upload_fw_target.png` screenshot).
Press "Build" button near target name.
