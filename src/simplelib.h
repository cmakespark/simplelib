#pragma once

#ifdef __linux__
#    define DECL_EXPORT     __attribute__((visibility("default")))
#    define DECL_IMPORT     __attribute__((visibility("default")))
#elif _WIN32
#    define DECL_EXPORT     __declspec(dllexport)
#    define DECL_IMPORT     __declspec(dllimport)
#else
#    define DECL_EXPORT     __attribute__((visibility("default")))
#    define DECL_IMPORT     __attribute__((visibility("default")))
#endif

#ifdef CCsimplelib_BUILD_SHARED_LIBS
#  if defined(SIMPLELIB_BUILD_LIBRARY)
#    define CCSIMPLELIB_EXPORT DECL_EXPORT
#    ifdef PRIVATE_TESTS_ENABLED
#      define CCSIMPLELIB_AUTOTEST_EXPORT DECL_EXPORT
#    else
#      define CCSIMPLELIB_AUTOTEST_EXPORT
#    endif
#  else
#    define CCSIMPLELIB_EXPORT DECL_IMPORT
#    ifdef PRIVATE_TESTS_ENABLED
#      define CCSIMPLELIB_AUTOTEST_EXPORT DECL_IMPORT
#    else
#      define CCSIMPLELIB_AUTOTEST_EXPORT
#    endif
#  endif
#else
#  define CCSIMPLELIB_EXPORT
#  define CCSIMPLELIB_AUTOTEST_EXPORT
#endif
