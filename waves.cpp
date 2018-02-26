#include <math.h>
#include "sample_rate.hpp"
#include "waves.hpp"

float bsin(int t) {
  return 0.5*sin(2*M_PI*(float)t/SAMPLE_RATE) + 0.5f;
}

float saw(int t) {
  return (float)(t % SAMPLE_RATE)/(float)SAMPLE_RATE;
}

float square(int t) {
  return pulse(t, 0.5);
}

float pulse(int t, float width) {
  return saw(t) < width ? 1 : 0;
}
