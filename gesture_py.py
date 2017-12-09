# for Serial communication
import serial
# Required to use delay functions
import time
#make sure pyautogui is install in your machine
import pyautogui

ArduinoSerial = serial.Serial('com8', 9600)  # Create Serial port object called arduinoSerialData
time.sleep(2)  # wait for 2 seconds for the communication to get established
while 1:
    incoming = str(ArduinoSerial.readline())  # read the serial data and print it as line
    print incoming

    if 'Tab change' in incoming:
        pyautogui.hotkey('ctrl', 'tab')
    if 'Zoom In' in incoming:
        pyautogui.hotkey('ctrl', '+')
    if 'Zoom Out' in incoming:
        pyautogui.hotkey('ctrl', '-')

    incoming = "";
