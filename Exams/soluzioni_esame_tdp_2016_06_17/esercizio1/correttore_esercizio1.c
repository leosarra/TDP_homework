#include <math.h>

#include "correttore_esercizio1.h"

void ground_truth(Mat* dest, Mat* src) {
  for(int r = 0; r < src->rows; ++r) {
    for(int c = 0; c < src->cols; ++c) {
      float max_diff = 0.0f;
      for(int rr = r - 1; rr <= r + 1 && rr < src->rows; ++rr) {
	for(int cc = c - 1; cc <= c + 1 && cc < src->cols; ++cc) {
	  if(rr >= 0 && cc >= 0) {
	    float curr_diff = fabs(src->row_ptrs[r][c] - src->row_ptrs[rr][cc]);
	    if(curr_diff > max_diff) {
	      max_diff = curr_diff;
	    }
	  }
	}
      }
      dest->row_ptrs[r][c] = max_diff;
    }
  }
}
