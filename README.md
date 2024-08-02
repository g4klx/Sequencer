This is a simple transmit/receive sequencer for use with EME systems, or at least my EME system!

It uses an Arduino Uno and an Arduino four relay hat but only uses three of the relays. It has two inputs, one from a USB to serial adapater and the second a toggle switch on the front panel.

Like any standard sequencer, it switches the relays in sequece once PTT has been asserted, and releases them in the reverse order once PTT has stopped being asserted. In my case the relays control the co-ax relays, then the amplifier, and finally the PTT line to the driver radio.

The first of the two inputs is via the USB to serial adapater is from WSJT-X which has the option to send its PTT outout via a serial port using a handshaking line and NOT directly to the radio, hence the PTT output of the sequencer back to the radio at the end of the sequence.

The second input, from the toggle switch (which is debounced), is to allow manual control of the whole system when not operating via WSJT-X, for example with CW or even SSB.

This code was copied from a pre-existing Arduino sequencer sketch, but has been heavily modified as to be almost unrecognisable.
