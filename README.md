 <h1 align="center">Terminal-01</h1> 
<div align="center">         
<p align="center">

 <img width="881" height="598" alt="5-Photoroom" src="https://github.com/user-attachments/assets/2d643ba3-173a-47c6-ab77-f8a0cca7c4d4" />

A compact clock and timer with a surprise of gaming abilities for when its needed, with a custom 3d printed case and a minimalistic theme. </p>


        
<h1 align="center">Overview</h1>

        
<p align="center">This project is a custom retro tabletop built around the esp32 c3 supermini. It includes a vibrant 1.8-inch TFT LCD display, Type-C charging module with inbuilt protection, a rotary encoder module with push button as well, a speaker, some jumper cables and a battery ofc. 


<h1 align="center">Why am I even building this?</h1>
<p align="center">
 
 I built this project as a part of an event called [Fallout](https://fallout.hackclub.com), organized by an non-profit organization called [Hack Club](https://hackclub.com), we build and ship hardware projetcs and for that we get some cool gifts and grants to build it irl. After building hardware projects for 60 hours, we get invited to Shenzen, China on a Hardware Hackathon, I am building this project to work toward those 60 hours.
 
 </p>

<h1 align="center">Why Terminal-01?</h1>

So I spend a lot of time on my desk and frequently use a dekstop [Pomodoro timer](https://en.wikipedia.org/wiki/Pomodoro_Technique) app to help me navigate my work/study sessions, I also use a physical clock for seeing time ofc and have nothing really to do in my breaks which wont distract me too much.
I created this project  (which is also my first hardware project) for solving all these problems and  help myself getting [supercalifragilisticexpialidocious](https://en.wikipedia.org/wiki/Supercalifragilisticexpialidocious) in building super cool hardware things. 

<h1 align="center">The Features</h1>
</div>

1. Real-Time Clock: Displays an automatically synchronizing NTP time feed maintained by background Wi-Fi checks, featuring a persistent on-screen icon.

2. System Alarm: Offers an adjustable interface for setting daily alarms, triggering full-screen flashing visuals and audio sirens when activated.

3. Productivity Timer: Includes a Pomodoro focus timer that alerts users with an aggressive flashing visual and buzzer when a work session completes.

4. Gaming Console: Features a playable "Space Attack" arcade game with programmatic retro sound effects and dynamic boundary collision.

5. Screensaver: Displays a bouncing DVD logo that allows for real-time kinetic speed adjustment using the rotary encoder wheel.
<div align="center">   
 
# Repository Contents

| Path | What it contains |
| --- | --- |
| [`3D Case Files/STEP Files`](https://github.com/Ragh7av/Terminal-01/tree/main/CAD) | Editable STEP files for the top and bottom case parts |
| [`Firmware`](https://github.com/Ragh7av/Terminal-01/tree/main/Firmware) | Editable C++ code for the project |
| [`Licence`](https://github.com/Ragh7av/Terminal-01/blob/main/LICENSE) | MIT Licence |
| [`BOM`](https://github.com/Ragh7av/Terminal-01/tree/main/BOM) | CSV and XLSX versions of the bill of materials |
| [`Zine.pdf`](https://github.com/Ragh7av/Terminal-01/blob/main/Zine/Zine.pdf)/ [`Zine.png`](https://github.com/Ragh7av/Terminal-01/blob/main/Zine/Zine.png)  | Project zine in PDF and image form |
| [`wiring diagram`](https://github.com/Ragh7av/Terminal-01/tree/main/Wiring%20diagram) | Color coded diagram for connecting the wires |

# The Zine page (A hackclub magazine)
<img width="486" height="749" alt="Zine" src="https://github.com/user-attachments/assets/550bf631-7f3a-4442-8d34-f5df3eb25656" />


# 3d render of the assembly


# Case

</div>

# The components used- 

1. ESP32-C3 Super Mini USB C-Type Development Board (Yes this will have wifi capabilities and will sink time automatically)
2. KY-040 Rotary Encoder Module
3. 3.7V 2500mAh 18650 Lithium Ion Rechargeable Battery
4. Tp4056 1A Lithium Battery Charging Protection Board Module Type C Usb Interface To 4.2V
5. 8 Ohm 0.5 Watt Speaker-40mm
6. 1.8-inch TFT LCD Module
7. Jumper cables

# Bill of materials-
| Product Name | Product Link | Quantity | Base Price | Tax (18%) | Shipping Share (flat shipping) | Total Cost |
| --- | --- | --- | --- | --- | --- | --- |
| ESP32 Type-C 38 Pin Dev Board – Dual Core WiFi+BT | [Link](https://robosap.in/product/esp32-type-c-38-pin-dev-board-dual-core-wifibt/) | 1 | ₹335.00 | ₹60.30 | ₹14.29 | ₹409.59 |
| KY-040 Rotary Encoder Module | [Link](https://robosap.in/product/rotary-encoder-module-for-arduino/) | 1 | ₹51.00 | ₹9.18 | ₹14.29 | ₹74.47 |
| 3.7V 2500mAh 18650 Lithium Ion Rechargeable Battery | [Link](https://robosap.in/product/3-7v-2500mah-18650-lithium-ion-rechargeable-battery/) | 1 | ₹68.00 | ₹12.24 | ₹14.29 | ₹94.53 |
| Tp4056 1A Lithium Battery Charging Protection Board Module Type C Usb Interface To 4.2V | [Link](https://robosap.in/product/tp4056-1a-lithium-battery-charging-protection-board-module-type-c-usb-interface-to-4-2v/) | 1 | ₹16.00 | ₹2.88 | ₹14.29 | ₹33.17 |
| 8 Ohm 0.5 Watt Speaker-40mm | [Link](https://robosap.in/product/8-ohm-0-5-watt-speaker-40mm/) | 1 | ₹45.00 | ₹8.10 | ₹14.29 | ₹67.39 |
| 1.8-inch TFT LCD Module | [Link](https://robosap.in/product/1-8-inch-tft-spi-lcd-display-module/) | 1 | ₹280.00 | ₹50.40 | ₹14.29 | ₹344.69 |
| Jumper cables | [Link](https://robosap.in/product/jumper-wire-set-of-male-to-male-male-to-female-and-female-to-female/) | 1 | ₹150.00 | ₹27.00 | ₹14.29 | ₹191.29 |
| **Total** |  |  | **₹945.00** | **₹170.10** | **₹100.00** | **₹1,215.10** |

# The wiring diagram-
<img width="1920" height="1080" alt="Untitled design" src="https://github.com/user-attachments/assets/e9aeb7bc-977b-47e6-9933-fbc74801f3eb" />


# Step-wise tutorial for building it yourself



</p>



 <h1>Inspirations</h1> 
 https://github.com/DjukicAleksej/Biblically-Accurate-USB-Hub/?tab=readme-ov-file For repository documentation.
 https://youtu.be/nUozTo_dhss?si=LCkojv6oHQSe04vr for the UI and Firmware
 
