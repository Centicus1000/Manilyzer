mkdir -p build_exe
cd build_exe
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build .
cd ..
./build_exe/Manilyzer
