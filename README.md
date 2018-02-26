# C++ Bytebeat Synth

This is a simple implementation of a [bytebeat](http://canonical.org/~kragen/bytebeat/) synth. It works by simply outputting unsigned characters in the 8-bit range [0, 255], corresponding to the sound level of the output. The sample rate is set to the CD standard 44100 Hz though this can be changed in the `sample_rate.hpp` header file. Example waveforms and digital filters can be found in `waves.cpp` and `filters.cpp` and a very basic implementation of [frequency modulated synthesis](http://www.ams.org/publicoutreach/feature-column/fcarc-synthesizer). There is also the possibility of outputting a waveform using the graphics library [SFML](https://www.sfml-dev.org/) although this is, again, basic and a little bit glitchy.

The code should be reasonably self explanatory. 

## Building
A look at the makefile should provide enough information to build

Building just sound:
`make`

Building with graphical output:
`make sfml`

## Running
On linux using ALSA, the output from the synth can be played by piping it into the command `aplay` like so

```
./synth | aplay -r 44100
```

The default settings for `aplay` are 8-bit audio sampled at 8000Hz, so the sample rate must be set to correspond to the output of the synth.
