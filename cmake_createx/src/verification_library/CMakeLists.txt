set(VERIFICATION_LIBRARY_SOURCES
    "verify_files.cpp"
    "verify_arg.cpp"
    "verify_tex_file.cpp"
    )
set(VERIFICATION_LIBRARY_HEADERS
    "verify_files.h"
    "verify_arg.h"
    "verify_tex_file.h"
    )
set(LIBRARY_INCLUDES
    "./"
    "${CMAKE_BINARY_DIR}/configured_files/include")

add_library(Verification_Library STATIC
    ${VERIFICATION_LIBRARY_SOURCES}
    ${VERIFICATION_LIBRARY_HEADERS})

target_include_directories(Verification_Library PUBLIC ${LIBRARY_INCLUDES})
