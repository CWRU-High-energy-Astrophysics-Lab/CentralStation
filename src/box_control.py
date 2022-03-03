from gpiozero import DigitalOutputDevice, CPUTemperature
from ina219 import INA219
fan = DigitalOutputDevice(8)
temp=CPUTemperature
threshold= 40
while(True):
    if threshold<temp.temperature:
        fan.on()
    elif threshold-5<temp.temperature:
        fan.off()



