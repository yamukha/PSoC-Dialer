
CY8CKIT-001 PSoC Dialer
==========

CY8CKIT-001 PSoC DevKIt and PCI modem for basic operation in PSTN 


This project is based on CY8CKIT-001 PSoC Development Kit (DevKIt) and modem (PCI board for personal computer) and provides basic operation in PSTN (Public switched telephone network).

Having transformer and relay PCI modem it provides interface between DevKit and PSTN.

DevKit can make dialing in pulse and DTMF (Dual Tone Multi Frequency) modes and check line status by busy/dial tones.
  
In this applidation DevKit hang off, check tone (400 Hz) and dials zero for making Intercity call.  
After detecting 425 Hz tone it starts to dial phone number in pulse mode (with Make/break ratio 40/60).
Then it is trying to check status of called number. If busy DevKit make several attempts to redial.  
If phone is not busy DevKiT sends to it several DTMFs.

Used resources of DevKit:
- Two 16 bit PWM  (pulse width modulation) blocks for generating of DTMF;
- 3 digital pins (one for relay on/off, others for DTMF) to interface to modem;
- 2 digital outputs for LEDs (relay on/off pin used to control other one LED for blinking during dialing);
- 1 analog input pin; 
- ADC (Analog to Digital Converter) used for recognizing audio tones;
- LCD.

Simplified circuit diagram shows electrical connections.
 
PDF files provides only main.c sections. 
Whole project uploaded to github.