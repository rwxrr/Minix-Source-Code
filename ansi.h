#ifndef _ANSI_H
#define _ANSI_H
#if __STDC__ == 1
#define _ANSI 31459 /* compiler claims full ANSI conformance */
#endif
#ifdef __GNUC__
#define _ANSI 31459 /* gcc conforms enough even in non-ANSI mode */
#endif
#ifdef _ANSI
/* Keep everything for ANSI prototypes. */
#define _PROTOTYPE(function, params) function params
#define _ARGS(params) params
#define _VOIDSTAR void *
#define _VOID void
#define _CONST const
#define _VOLATILE volatile
#define _SIZET size_t
#else
/* Throw away the parameters for K&R prototypes. */
#define _PROTOTYPE(function, params) function()
#define _ARGS(params) ()
#define _VOIDSTAR void *
#define _VOID void
#define _CONST
#define _VOLATILE
#define _SIZET int
#endif /* _ANSI */
/* This should be defined as restrict when a C99 compiler is used. */
#define _RESTRICT
/* Setting any of _MINIX, _POSIX_C_SOURCE or _POSIX2_SOURCE implies
* _POSIX_SOURCE. (Seems wrong to put this here in ANSI space.)
*/
#if defined(_MINIX) || _POSIX_C_SOURCE > 0 || defined(_POSIX2_SOURCE)
#undef _POSIX_SOURCE
#define _POSIX_SOURCE 1
#endif
#endif /* ANSI_H */