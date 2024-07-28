IN = ""
serial.set_baud_rate(BaudRate.BAUD_RATE115200)
DEVICE_ID = "Morse"

def on_forever():
    serial.write_line("morse" + " " + str(not (not (input.button_is_pressed(Button.A)))) + " 0")
    basic.pause(10)
basic.forever(on_forever)

def on_forever2():
    global IN
    IN = serial.read_line()
    if IN == "ping":
        serial.write_line("pong")
    if IN == "who":
        serial.write_line(DEVICE_ID)
basic.forever(on_forever2)
