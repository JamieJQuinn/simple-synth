#include "sample_rate.hpp"
#include "filters.hpp"

unsigned char lowPass(int wf, unsigned char prev) {
  float cutoff = 8000.0/SAMPLE_RATE;
  return prev + (wf - prev)*cutoff;
}

unsigned char highPass(int wf, unsigned char prev) {
  return wf - lowPass(wf, prev);
}
