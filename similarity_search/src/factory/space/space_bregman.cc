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

#include "searchoracle.h"
#include "space_bregman.h"
#include "spacefactory.h"

namespace similarity {

/*
 * Creating functions.
 */

template <typename dist_t>
Space<dist_t>* CreateKLDivFast() {
  return new KLDivFast<dist_t>();
}

template <typename dist_t>
Space<dist_t>* CreateKLDivFastRightQuery() {
  return new KLDivFastRightQuery<dist_t>();
}

template <typename dist_t>
Space<dist_t>* CreateKLDivGenFast() {
  return new KLDivGenFast<dist_t>();
}

template <typename dist_t>
Space<dist_t>* CreateKLDivGenFastRightQuery() {
  return new KLDivGenFastRightQuery<dist_t>();
}

template <typename dist_t>
Space<dist_t>* CreateKLDivGenSlow() {
  return new KLDivGenSlow<dist_t>();
}

template <typename dist_t>
Space<dist_t>* CreateItakuraSaitoFast() {
  return new ItakuraSaitoFast<dist_t>();
}


/*
 * End of creating functions.
 */

/*
 * Let's register creating functions in a method factory.
 *
 * IMPORTANT NOTE: don't include this source-file into a library.
 * Sometimes C++ carries out a lazy initialization of global objects
 * that are stored in a library. Then, the registration code doesn't work.
 */

REGISTER_SPACE_CREATOR(float,  SPACE_KLDIV_FAST, CreateKLDivFast)
REGISTER_SPACE_CREATOR(double, SPACE_KLDIV_FAST, CreateKLDivFast)
REGISTER_SPACE_CREATOR(float,  SPACE_KLDIV_FAST_RIGHT_QUERY, CreateKLDivFastRightQuery)
REGISTER_SPACE_CREATOR(double, SPACE_KLDIV_FAST_RIGHT_QUERY, CreateKLDivFastRightQuery)
REGISTER_SPACE_CREATOR(float,  SPACE_KLDIVGEN_FAST, CreateKLDivGenFast)
REGISTER_SPACE_CREATOR(double, SPACE_KLDIVGEN_FAST, CreateKLDivGenFast)
REGISTER_SPACE_CREATOR(float,  SPACE_KLDIVGEN_SLOW, CreateKLDivGenSlow)
REGISTER_SPACE_CREATOR(double, SPACE_KLDIVGEN_SLOW, CreateKLDivGenSlow)
REGISTER_SPACE_CREATOR(float,  SPACE_KLDIVGEN_FAST_RIGHT_QUERY, CreateKLDivGenFastRightQuery)
REGISTER_SPACE_CREATOR(double, SPACE_KLDIVGEN_FAST_RIGHT_QUERY, CreateKLDivGenFastRightQuery)
REGISTER_SPACE_CREATOR(float,  SPACE_ITAKURASAITO_FAST, CreateItakuraSaitoFast)
REGISTER_SPACE_CREATOR(double, SPACE_ITAKURASAITO_FAST, CreateItakuraSaitoFast)

}

