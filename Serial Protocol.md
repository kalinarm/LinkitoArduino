# Linkito Serial Protocol

## Config

Enable the `Serial` module in Linkito by going to `Options` / `Modules`/ `Serial` and press `Add`.

Enter the path to the serial port and click `Activate`.

Tips:

* Using a by-id path will ensure that if the device is reconnected, it's consistently seen, e.g.:
  * `/dev/serial/by-id/usb-Arm_BBC_micro:DEVICE_ID-if01`
  * `/dev/serial/by-id/usb-ftdi_usb_serial_converter_ftFAAH9O-if00-port0`

## Raw Serial

### Linkito → Device

Any signal changes sent to the `Serial Port Send` block are prepended with the block's `prefix` value, then sent to the serial port with a trailing newline.

If both of the `prefix` value and the signal are non-null, they are separated by a space.

### Device → Linkito

Lines of text delimited by a newline are sent to the `Serial Port Receiver` block one at a time. The signal emitted by the block includes the newline.

## Serial Commands

The protocol is simple:

* All commands are delimited by newlines (`\n`, hex 0x0A)
* Parameters delimited by a single space
* Commands must be terminated by a newline at the end

```text
<control> <parameter1> <parameter2>
```

### Linkito → Device

Commands are defined by the device. No explicit command sending block is provided; use the `Serial Port Send` block.

### Device → Linkito

A command received by Linkito will be sent to any corresponding `Serial Order Receive` block with a matching `control` value.

`parameter2` is not used.

When the block is triggered by serial input, its output will be set according to the value of `parameter1` depending on the block parameter `type`:

* `BANG`: ?
* `BOOL`: output deactivated (null signal) if `parameter1` is any of `false`, `0`, `off`; activated (on) otherwise
* `INT`: output set to the value of `parameter1` if it is a valid 32-bit signed integer (between `-2^31` and `2^31-1`), `1` otherwise. Decimals with only zeroes after the decimal point are treated as integers.
  * logical activation: any value > 0
* `FLOAT`: output set to the value of `parameter1` if it is a valid 32-bit float, `1` otherwise
  * logical activation: any value > 0
* `STRING`: output set to the value of `parameter1`. Note that no spaces are possible in the parameter. Unicode is disallowed.
  * logical activation: any string other than `"0"` or `""` (an empty string)
* `TEXTURE`: ?
