This is a simple transmit/receive sequencer for use with EME systems, or at least my EME system!

It uses an Arduino Uno and an Arduino four relay hat. It has two inputs, one from a USB to serial adapter and the second a toggle switch on the front panel.

Like any standard sequencer, it switches the relays in sequence once the PTT has been asserted, and releases them in the reverse order once PTT has stopped
being asserted. In my case the relays control the co-ax relays, then the amplifier, and finally the PTT line to the driver radio. For simplicity of wiring
in my system, the two co-ax relays are switched by seperate relays so at that stage of switching two relays on the hat are energised.

| Relay | Use                      |
|:-----:|:-------------------------|
| 1     | Put radio into TX        |
| 2     | Switch amplifier to TX   |
| 3     | Switch co-ax relay to TX |
| 4     | Switch co-ax relay to TX |

The first of the two inputs is via the USB to serial adapter and is from WSJT-X which has the option to send its PTT output via a serial port using
a handshaking line and NOT directly to the radio, hence the PTT output of the sequencer back to the radio at the end of the sequence.

The circuit of the interface between the serial port, driven by an FTDI adapter, is found here:
[Enhanced USB-to-Serial PTT Interface](https://radio.g4hsk.co.uk/2020/03/01/enhanced-usb-to-serial-ptt-interface/)
Note the inversion of the RTS line, and to use RTS as the switching line within WSJT-X.

The second input, from the toggle switch (which is debounced), is to allow manual control of the whole system when not operating via WSJT-X, for
example with CW or SSB. The pins used for the inputs are:

| Pin  | Use                                 |
|:----:|:------------------------------------|
| A0   | PTT from the serial interface       |
| A1   | Ground for the serial interface PTT |
| A4   | Ground for the panel switch PTT     |
| A5   | PTT from the panel switch           |

All of the pin and relay definitions are easiy modifiable in the source code. The LED on the Arduino board mimics the PTT input.

This code was copied from a pre-existing Arduino sequencer sketch, but has been so heavily modified as to be almost unrecognisable.

It is licenced under the GPL 2.0.
