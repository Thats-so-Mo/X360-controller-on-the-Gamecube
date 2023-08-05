# Gaming with X360 controller on the Gamecube - Sort Of

This project allows you to use a XBOX 360 controller on the Nintendo GameCube. I know - blasphemy. As of this moment, it works on certain games such as Budokai 2 however for Budokai 1, it keeps pausing/unpausing the game - during a fight. It completely ignores the Xbox 360 controller for Luigi's Mansion and for a certain Naruto Game - it pauses/unpauses the game aswell. I am looking to move on from this project and decided to post this up as it might be useful for someone out there whose interested in and maybe who knows - could figure out why it acts so funky. 

One thing I did learn from this project is that, with the USB Host Shield, you can use other controllers to control the Gamecube, such as PS4,PS3 XBOX ONE S Controllers, etc. It doesn't even have to be a controller, use a toaster and it would work the same - without the Host shield of course haha. Another benefit is that it showed me that for people with certain disabilities that prevent them from using a GameCube Controller, a custom controller could be developed to help circumvent the disability. The Possibilites are Endless. 

I have uploaded multiple verisons of the code. They are pretty much are similar to each other with minor tweaks and such.

## Check out the video for a setup process and demonstration

[![IMAGE ALT TEXT HERE](https://i9.ytimg.com/vi/j49BG9yv4ws/maxresdefault.jpg?sqp=CIT0tqYG&rs=AOn4CLAGh7_J-BJ2nKDiSvqP9lzRamfmbQ)](https://youtu.be/V1tuf1zIyzc)


Items required for this fun little project:
```
1x Arduino Uno R3
1x Logic Level Converter
1x USB Host Shield and its Arduino Library
1x Nicohood's Nintendo Library
1x Xbox 360 USB Reciever
1x Xbox 360 Wireless Controller
1x GameCube Controller for parts - You need the cable that connects to the controller port on the GameCube - Wire to Male Port cable
```

The Wiring Diagram:
![Wiring Diagram](https://raw.githubusercontent.com/Thats-so-Mo/X360-controller-on-the-Gamecube/main/GameCube%20Diagram.png)

Special Thanks to Nicohood for developing the code/library that allows the Gamecube to accept input from an Arduino

Special Thanks to Felis for developing the USB Host Shield library

And Special Thanks to Froq/Simple Controllers for helping me out and showing me that what I wanted to do was possible.
