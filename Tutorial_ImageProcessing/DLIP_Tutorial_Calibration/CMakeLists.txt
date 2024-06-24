set(SOURCE_tiny ShowUndistorted_tiny.cpp tinyxml2.cpp)
set(SOURCE ShowUndistorted.cpp)
set(HEADER tinyxml2.h cameraParam.h)

add_executable(T_calibration_tiny ${SOURCE_tiny} ${HEADER})
add_executable(T_calibration ${SOURCE} ${HEADER})