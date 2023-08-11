set(TEST_MAIN "unit_tests")
set(TEST_SOURCES "test_main.cpp")
set(TEST_INCLUDES "./")

add_executable(${TEST_MAIN} ${MAIN_SOURCE_FILE})

target_link_libraries(${TEST_MAIN} PUBLIC
    Verification_Library
    Search_Library
    Append_Library
    Catch2::Catch2)
