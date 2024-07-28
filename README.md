# LinkitoArduino
Helpers to connect Arduino to game Linkito

Project linked to the Linkito video game: 
- [Steam page](https://store.steampowered.com/app/2312770/Linkito/)
- [Discord](https://discord.gg/WfsH2DvbUZ)

Feel free to ask on discord if any questions.

## Goal

Just some template to help creating Arduino sketch that connects to the game Linkito

## Config

This communication uses the serial port at 115200 baud.

Enable the `Serial` module in Linkito by going to `Options` / `Modules`/ `Serial` and press `Add`.

Enter the path to the serial port and click `Activate`.

## Protocol

The protocol is simple:

```text
<control> <parameter1> <parameter2>
```

* All commands are delimited by newlines (`\n`, hex 0x0A)
* Parameters delimited by a single space
* Commands must be terminated by a newline at the end

## Content

- **Linkito Template** : A base template to start your own Project
- **Linkito LCD** : to display some game information on a LCD screen
- **Linkito Robot Arm** : to control a robot arm with 4 servo motors. [I use this one](https://www.thingiverse.com/thing:1454048) 