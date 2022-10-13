#ifndef PW_MACROS_MAP_P_H_
#define PW_MACROS_MAP_P_H_

#include <pw/macros/map.h>

#define PW_MAP0_P(f, p, x, peek, ...) f(p, x) PW_MAP_NEXT(peek, PW_MAP1_P)(f, p, peek, __VA_ARGS__)
#define PW_MAP1_P(f, p, x, peek, ...) f(p, x) PW_MAP_NEXT(peek, PW_MAP0_P)(f, p, peek, __VA_ARGS__)

#define PW_MAP_LIST0_P(f, p, x, peek, ...) f(p, x) PW_MAP_LIST_NEXT(peek, PW_MAP_LIST1_P)(f, p, peek, __VA_ARGS__)
#define PW_MAP_LIST1_P(f, p, x, peek, ...) f(p, x) PW_MAP_LIST_NEXT(peek, PW_MAP_LIST0_P)(f, p, peek, __VA_ARGS__)

/**
 * Applies the function macro `f` to each of the remaining parameters with the
 * argument `p` applied before each parameter
 *
 * Example:
 *  PW_MAP_P(FOO, a, 1, 2, 3) -> FOO(a, 1) FOO(a, 2) FOO(a, 3)
 *
 */
#define PW_MAP_P(f, p, ...) PW_EVAL(PW_MAP1_P(f, p, __VA_ARGS__, ()()(), ()()(), ()()(), 0))

/**
 * Applies the function macro `f` to each of the remaining parameters and
 * inserts commas between the results.
 */
#define PW_MAP_LIST_P(f, p, ...) PW_EVAL(PW_MAP_LIST1_P(f, p, __VA_ARGS__, ()()(), ()()(), ()()(), 0))

#endif //PW_MACROS_MAP_P_H_