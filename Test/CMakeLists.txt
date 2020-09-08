cmake_minimum_required(VERSION 3.0)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

set(CPPs
WebRtcAudioTest.cpp)

add_executable(TestAudioAEC ${CPPs})
target_link_libraries(TestAudioAEC AudioAEC)

if(NOT DEFINED WIN32)
    target_link_libraries(TestAudioAEC m)
    target_link_libraries(TestAudioAEC pthread)
endif()