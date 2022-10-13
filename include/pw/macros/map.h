/*
 * @file map.h
 *
 * Modified from map-macro by William Swanson (https://github.com/swansontec/map-macro)
 */

#ifndef PW_MACROS_MAP_H_
#define PW_MACROS_MAP_H_

#define PW_EVAL0(...) __VA_ARGS__
#define PW_EVAL1(...) PW_EVAL0(PW_EVAL0(PW_EVAL0(__VA_ARGS__)))
#define PW_EVAL2(...) PW_EVAL1(PW_EVAL1(PW_EVAL1(__VA_ARGS__)))
#define PW_EVAL3(...) PW_EVAL2(PW_EVAL2(PW_EVAL2(__VA_ARGS__)))
#define PW_EVAL4(...) PW_EVAL3(PW_EVAL3(PW_EVAL3(__VA_ARGS__)))
#define PW_EVAL(...)  PW_EVAL4(PW_EVAL4(PW_EVAL4(__VA_ARGS__)))

#define PW_MAP_END(...)
#define PW_MAP_OUT
#define PW_MAP_COMMA ,

#define PW_MAP_GET_END2() 0, PW_MAP_END
#define PW_MAP_GET_END1(...) PW_MAP_GET_END2
#define PW_MAP_GET_END(...) PW_MAP_GET_END1
#define PW_MAP_NEXT0(test, next, ...) next PW_MAP_OUT
#define PW_MAP_NEXT1(test, next) PW_MAP_NEXT0(test, next, 0)
#define PW_MAP_NEXT(test, next)  PW_MAP_NEXT1(PW_MAP_GET_END test, next)

#define PW_MAP0(f, x, peek, ...) f(x) PW_MAP_NEXT(peek, PW_MAP1)(f, peek, __VA_ARGS__)
#define PW_MAP1(f, x, peek, ...) f(x) PW_MAP_NEXT(peek, PW_MAP0)(f, peek, __VA_ARGS__)

#define PW_MAP_LIST_NEXT1(test, next) PW_MAP_NEXT0(test, PW_MAP_COMMA next, 0)
#define PW_MAP_LIST_NEXT(test, next)  PW_MAP_LIST_NEXT1(PW_MAP_GET_END test, next)

#define PW_MAP_LIST0(f, x, peek, ...) f(x) PW_MAP_LIST_NEXT(peek, PW_MAP_LIST1)(f, peek, __VA_ARGS__)
#define PW_MAP_LIST1(f, x, peek, ...) f(x) PW_MAP_LIST_NEXT(peek, PW_MAP_LIST0)(f, peek, __VA_ARGS__)

/**
 * Applies the function macro `f` to each of the remaining parameters.
 */
#define PW_MAP(f, ...) PW_EVAL(PW_MAP1(f, __VA_ARGS__, ()()(), ()()(), ()()(), 0))

/**
 * Applies the function macro `f` to each of the remaining parameters and
 * inserts commas between the results.
 */
#define PW_MAP_LIST(f, ...) PW_EVAL(PW_MAP_LIST1(f, __VA_ARGS__, ()()(), ()()(), ()()(), 0))

#endif //PW_MACROS_MAP_H_
