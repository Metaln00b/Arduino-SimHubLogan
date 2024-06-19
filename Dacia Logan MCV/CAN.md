Dacia Logan MCV

CAN-Speed 500.000kbps (Terminated)



0x350 - Misc

length 8

byte 0 - Ignition and Light
    bit 0 - ?
    bit 1 - ?
    bit 2 - ?
    bit 3 - Ignition
    bit 4 - ?
    bit 5 - ?
    bit 6 - Power good
    bit 7 - Power good

byte 5 - Environment Lights
    bit 0 - 
    bit 1 -
    bit 2 -
    bit 3 - ABS
    bit 4 -
    bit 5 -
    bit 6 -
    bit 7 -


=============================================================================

0x5df Battery

=============================================================================

0x5de Beep Boop Xmas Tannenbaum

lenght 4

byte 0
    bit 0 - High Beam
    bit 1 - Low Beam
    bit 2 - Backlight
    bit 3 - Fog Lights Front
    bit 4 - Fog Light Back
    bit 5 - Turn Signal Left
    bit 6 - Turn Signal Right
    bit 7 - Important!

byte 1
    bit 0 - 
    bit 1 -
    bit 2 - Beep Sound
    bit 3 - 
    bit 4 - Beep Sound
    bit 5 -
    bit 6 -
    bit 7 - 4x4 Error & Doors

byte 2
    bit 0 - 
    bit 1 -
    bit 2 - 
    bit 3 - 
    bit 4 - 
    bit 5 - Beep Sound
    bit 6 -
    bit 7 - Beep Sound

byte 3
    bit 0 - 
    bit 1 -
    bit 2 - 
    bit 3 - 
    bit 4 - 
    bit 5 - Beep Sound
    bit 6 -
    bit 7 - Another Beep Sound

=============================================================================

0x217 - Speedometer (kmh)

byte 0 -

byte 1 - 

byte 2 -

byte 3 - Speedometer


DEC - KMH
20 - 20
39 - 50
50 - 67
52 - 70
60 - 84
64 - 90
70 - 100
88 - 130
100 - 150
119 - 180
120 - 182
125 - 190

DEC = 0.61 * KMH + 8.47

=============================================================================

0x186 - Tachometer (RPM)

byte 0 - Tachometer (RPM)

DEC - RPM*1000
50 - 2
80 - 3
110 - 4
140 - 5
170 - 6
200 - 7
230 - 8
255 - ?


=============================================================================

0x5d7 - Milage
