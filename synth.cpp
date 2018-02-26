#include <iostream>
#include <math.h>
#include "waves.hpp"
#include "sample_rate.hpp"
#include "filters.hpp"
#include "utility.hpp"

#ifdef SFML_ENABLED
#include <SFML/Graphics.hpp>
#endif

const int WIDTH=800;
const int HEIGHT=600;
float freq = 440;
const int DRAW_RATE = 10;
const int DRAW_SAMPLE_STEPS = SAMPLE_RATE/DRAW_RATE;
const int DRAW_SAMPLES = DRAW_SAMPLE_STEPS/6;

float fmWaveform(int t) {
  float tSec = float(t)/SAMPLE_RATE;
  float fmFreq = 5;
  //float fmFreq = tSec/10.*220;
  float cFreq = freq;
  //float I = tSec/10.*5.;
  float I = 1;
  return 0.5*sin(2*M_PI*cFreq*tSec + I*sin(2*M_PI*fmFreq*tSec)) + 0.5f;
}

float waveform(int t) {
  return saw(freq*t);
}

#ifdef SFML_ENABLED
void drawWaveform(unsigned char samples[], sf::RenderWindow& window) {
  window.clear();
  sf::VertexArray line(sf::LineStrip, DRAW_SAMPLES);
  for(int i=0; i<DRAW_SAMPLES; ++i) {
    float xPos = float(i)/DRAW_SAMPLES*WIDTH;
    line[i].position = sf::Vector2f(xPos, uint(samples[i]) + HEIGHT/2 - 128);
  }
  window.draw(line);
  window.display();
}
#endif

int main() {
#ifdef SFML_ENABLED
  sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "C++ Synth");
  unsigned char samples [DRAW_SAMPLES];
#endif
  unsigned char prev = charFromWF(waveform(0));
  for(int t=0;;++t) {
    // Low Pass
    //unsigned char wf = charFromWF(waveform(t));
    //wf = lowPass(wf, prev);
    //prev = wf;

    // Thru
    unsigned char wf = charFromWF(waveform(t));

    // Frequency Modulated
    //unsigned char wf = charFromWF(fmWaveform(t));

    std::cout << wf;

#ifdef SFML_ENABLED
    // Drawing Code
    if(t%DRAW_SAMPLE_STEPS == 0) {
      drawWaveform(samples, window);
    }
    samples[t%DRAW_SAMPLES] = wf;
#endif
  }
}
