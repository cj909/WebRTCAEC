cmake_minimum_required(VERSION 3.0)

project(AudioAEC)

set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

option(BUILD_TEST "Build Test" on)

if(NOT DEFINED CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE DEBUG)
endif()

if(NOT DEFINED WIN32)
add_compile_options(-fvisibility=hidden)
add_definitions(-DWEBRTC_POSIX)
endif()

set(CPPs
${CMAKE_CURRENT_SOURCE_DIR}/src/aecm_core.c
${CMAKE_CURRENT_SOURCE_DIR}/src/cpu_features_wrapper.h
${CMAKE_CURRENT_SOURCE_DIR}/src/division_operations.c
${CMAKE_CURRENT_SOURCE_DIR}/src/ring_buffer.c
${CMAKE_CURRENT_SOURCE_DIR}/src/aecm_core.h
${CMAKE_CURRENT_SOURCE_DIR}/src/cross_correlation.c
${CMAKE_CURRENT_SOURCE_DIR}/src/downsample_fast.c
${CMAKE_CURRENT_SOURCE_DIR}/src/ring_buffer.h
${CMAKE_CURRENT_SOURCE_DIR}/src/aecm_defines.h
${CMAKE_CURRENT_SOURCE_DIR}/src/delay_estimator.c
${CMAKE_CURRENT_SOURCE_DIR}/src/echo_control_mobile.c
${CMAKE_CURRENT_SOURCE_DIR}/src/signal_processing_library.h
${CMAKE_CURRENT_SOURCE_DIR}/src/compile_assert.h
${CMAKE_CURRENT_SOURCE_DIR}/src/delay_estimator.h
${CMAKE_CURRENT_SOURCE_DIR}/src/min_max_operations.c
${CMAKE_CURRENT_SOURCE_DIR}/src/spl_init.c
${CMAKE_CURRENT_SOURCE_DIR}/src/complex_bit_reverse.c
${CMAKE_CURRENT_SOURCE_DIR}/src/delay_estimator_internal.h
${CMAKE_CURRENT_SOURCE_DIR}/src/randomization_functions.c
${CMAKE_CURRENT_SOURCE_DIR}/src/spl_inl.h
${CMAKE_CURRENT_SOURCE_DIR}/src/complex_fft.c
${CMAKE_CURRENT_SOURCE_DIR}/src/delay_estimator_wrapper.c
${CMAKE_CURRENT_SOURCE_DIR}/src/real_fft.c
${CMAKE_CURRENT_SOURCE_DIR}/src/spl_sqrt_floor.c
${CMAKE_CURRENT_SOURCE_DIR}/src/complex_fft_tables.h
${CMAKE_CURRENT_SOURCE_DIR}/src/delay_estimator_wrapper.h
${CMAKE_CURRENT_SOURCE_DIR}/src/real_fft.h
${CMAKE_CURRENT_SOURCE_DIR}/src/vector_scaling_operations.c
)

add_library(AudioAEC SHARED ${CPPs})
target_link_libraries(AudioAEC)

if(BUILD_TEST)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Test)
endif()