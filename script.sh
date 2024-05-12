
function clc(){
    if [ -d "build" ]; then
      rm -r build
    fi
}

clc
mkdir build
cd build
cmake ..
make
./BD2_Project
cd ..

