# Mailbox Notifier [version 1.0.0]

Weather in Canada is random, it changes within a moment. So, whenever i get a mail in my mailbox and if it is snowy or rainy outside my mail gets damaged. I decided to make a  project which will help me knowing when my mail is getting delivered.  

This specific project is an Arduino based mail notifier prototype. It was built for A CS 207 class. I was inspired by a youtuber called CuriouslyCory.  


![alt text][pic1]

[pic1]: https://github.com/raselsuborno/CS-207/blob/main/img/IMG_5154.jpg "Logo Title Text 2"


Repository Contents
============
Here's where you'll provide a map of all the top-level contents (where applicable):

* **/src** - Here's where the software for your device goes (.ino, .cpp).
* **/hardware** - All the PCB design files / 3D models (.ftz, .brd, .sch, .stl). 
* **/img** - This is where the image files for this readme are! Yay!
* **/LICENSE** - The license file.
* **/README.md** - The file you're reading now! :-D

Requirements and Materials
============

The hardware was used in this project:

Dependencies:
* esp8266-community https://arduino.esp8266.com/stable/package_esp8266com_index.json
* AT flasher firmware for Esp https://github.com/Edragon/esp_firmware/tree/master/Firmware/AT-espressif/IDF
* IFTTT https://ifttt.com

Bill of Materials:
* 1 x ESP-8266 Wi-Fi  Module
* 1 x push button
* 1 x 560ohm resistor
* 1 x Photo resistor
* 15 x Jumper Cable
* 1 x breadboard
* 1 x Arduino Uno

Build Instructions
==================

The build is quite easier. However, the ESP module is a bit trickier to connect with the arduino as the ESP board is not breadboard friendly. I have included the ESP inly build and Schematic and the whole project build. 

![alt text][pic3]

[pic3]: https://github.com/raselsuborno/CS-207/blob/main/Hardware/ESP%20module.jpg "Logo Title Text 2"


![alt text][pic2]

[pic2]: https://github.com/raselsuborno/CS-207/blob/main/Hardware/ESP%20module_schem.jpg "Logo Title Text 3"

![alt text][pic4]

[pic3]: https://github.com/raselsuborno/CS-207/blob/main/Hardware/Notifier.jpg "Logo Title Text 2"


![alt text][pic5]

[pic2]: https://github.com/raselsuborno/CS-207/blob/main/Hardware/Notifier_schem.jpg "Logo Title Text 3"

Note that The ESP module can only take 3.3V of power the 5V power can kill the chip. Use a voltage devider for the programming device which does not have specific 3.3 volt power. 

Firmware Installation
=====================
To install the latest firmware in the ESP8266 module go to the link below and install the program then choose the AT File to flash the ESP module. 
https://github.com/Edragon/esp_firmware

IFTTT
=====
I am using IFTTT webhooks tro trigger the system to get phone text notification for this project. For using the IFTTT i had to open an account to get the webhook URL. then used that URL in my program. 

Usage
===== 

* Press the button on the breadboard before uploading.
* Upload the code to the device using Arduino IDE. 
* Make sure the led on the ESP module is blinking. 
* Press the Button again after the uploading of the program and you can use your device now.
* Place the device inside the mailbox and test run few times to check.

Team
=====
The build team consists of: 
* Rasel Ahamed -- I did everything.
Solo participent and creator of the whole project.

Setbacks
========
I have had quite a few setbacks during the process to build this project. The ESP chip took a long time to get delivered. Then I had no idea how to program ESP module. The first time I programmed it I got compiling error. then I sat with my instructor in the course Dr. Trevor Tomesh. We sat together several times to program the chip and had the same issue again and again. we both could not solve it then he provided me with a Wifi shield which had the same exact issue. I have tried to flash the module and different Arduino board with different computer OS. BUt I could bnot make my project work. However, my codes are getting compiled which means the codes are okay for this project and as a prototype my project is working. I have researched and gave my time and thought into this project.

Credits
=======

* CuriouslyCory. https://youtu.be/tl_GXsRKXtQ
* Trevor Tomesh. Arduino Wifi Shield by wangtongze. 
