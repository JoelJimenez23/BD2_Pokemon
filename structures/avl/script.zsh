#!/usr/bin/zsh

function remove(){
    if [ -f write_file ]; then
            rm write_file;
    fi

    if [ -f main ]; then
        rm main;
    fi

    if [ -f personas.dat ]; then
        rm personas.dat;
    fi

    if [ -f personas_dni.avl ]; then
        rm personas_dni.avl;
    fi

    if [ -f personas_edad.avl ]; then
        rm personas_edad.avl;
    fi

}

remove;

g++ write_file.cpp -o write_file;
./write_file;

g++ -std=c++20 main.cpp persona.cpp -o main;
./main

remove;
