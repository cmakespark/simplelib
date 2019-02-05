set(SIMPLELIB_SOURCES
    dog/dog.cpp
)

set(SIMPLELIB_PUBLIC_HEADERS
    simplelib.h
    dog/dog.h
)

set(SIMPLELIB_PRIVATE_HEADERS
    dog/dog_p.h
)

createlib(NAME SimpleLib
    NAMESPACE CC
    VERSION 2.0.0
    SOURCES ${SIMPLELIB_SOURCES}
    PUBLIC_HEADERS ${SIMPLELIB_PUBLIC_HEADERS}
    PRIVATE_HEADERS ${SIMPLELIB_PRIVATE_HEADERS}
    GENERATE_PACKAGE)

add_definitions(-DSIMPLELIB_BUILD_LIBRARY)
# When set to OFF, the library will be built as a static library
if (${BUILD_SHARED_LIBS})
    add_definitions(-DCCsimplelib_BUILD_SHARED_LIBS)
endif()
