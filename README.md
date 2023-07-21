# LinkitoArduino
Helpers to connect Arduino to game Linkito

Project linked to the Linkito video game: 
- [Steam page](https://store.steampowered.com/app/2312770/Linkito/)
- [Discord](https://discord.gg/WfsH2DvbUZ)

Feel free to ask on discord if any questions.

## Goal

Just some template to help creating Arduino sketch that connects to the game Linkito

## Config

This communication uses Serial Port at 115200 bauds.
Need to enable Serial in the game Linkito 
options/modules/serial then press Add

## Protocol

The protocol is really simple (even naive)

[id command] [parameter1] [parameter2] NL

- All are sent as string.
- Delimiter is a space
- Need a new line at the end

## Content

- **Linkito Template** : A base template to start your own Project
- **Linkito LCD** : to display some game information on a LCD screen
- **Linkito Robot Arm** : to control a robot arm with 4 servo motors. [I use this one](https://www.thingiverse.com/thing:1454048) 