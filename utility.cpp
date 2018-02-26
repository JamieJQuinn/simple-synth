#include "utility.hpp"

unsigned char charFromWF(float wf) {
  wf = wf > 1.0f ? 1.0f : wf;
  wf = wf < 0.0f ? 0.0f : wf;
  return wf*255.0f;
}
