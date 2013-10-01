/**
 * Non-metric Space Library
 *
 * Authors: Bilegsaikhan Naidan (https://github.com/bileg), Leonid Boytsov (http://boytsov.info).
 * With contributions from Lawrence Cayton (http://lcayton.com/).
 *
 * For the complete list of contributors and further details see:
 * https://github.com/searchivarius/NonMetricSpaceLib 
 * 
 * Copyright (c) 2010--2013
 *
 * This code is released under the
 * Apache License Version 2.0 http://www.apache.org/licenses/.
 *
 */
#ifndef _VPTREE_UTILS_H_
#define _VPTREE_UTILS_H_

#include <vector>
#include <cmath>
#include <cstdlib>

#include "object.h"
#include "utils.h"

namespace similarity {

inline size_t SelectVantagePoint(const ObjectVector& data, bool use_random_center) {
  CHECK(!data.empty());
  return use_random_center ? RandomInt() % data.size() : data.size() - 1;
}

/* 
 * Even if dist_t is double, or long double
 * storing the median as the single-precision number (i.e., float)
 * should be good enough.
 */
template <typename dist_t>
inline float GetMedian(const DistObjectPairVector<dist_t>& dp) {
  CHECK(!dp.empty());
  if ((dp.size() & 1) == 1) {   // odd
    return static_cast<float>(dp[dp.size() / 2].first);
  } else {                     //even
    CHECK(dp.size() >= 2);
    return (static_cast<float>(dp[(dp.size() / 2 ) - 1].first) 
          + static_cast<float>(dp[dp.size() / 2 ].first)) / 2.0f;
  }
}

/* 
 * This function find for approximate quantile boundaries.
 * It wasn't meant to get quantiles exactly. Furthermore,
 * the method may return fewer indices than the # of quantiles.
*/
template <typename dist_t, typename data_t>
inline std::vector<size_t> EstimateQuantileIndices(
    const typename std::vector<std::pair<dist_t, data_t> >& dp,
    const std::vector<float> quant) {
  CHECK(!dp.empty());
  std::vector<size_t> res;
  size_t N = dp.size();

  size_t prevIndx = 0;

  for(auto it = quant.begin(); it != quant.end(); ++it) {
      size_t indx = static_cast<size_t>(round(*it * N));
      if (indx < N && indx > prevIndx) {
        dist_t dist = dp[indx].first;
        prevIndx = indx;
        // If there is a series of entries with equal distances, go to the end of the list!
        while (indx < N && dp[indx].first == dist) {
          prevIndx = indx++;
        }
        res.push_back(prevIndx);
     }
  }

  return res;
}

}          // namespace similarity

#endif     // _VPTREE_UTILS_H_
