#!/bin/bash

gcc -fopenmp HelloWorld.C -o HelloWorld_c
gcc -fopenmp adveccion.c -o adveccion

./HelloWorld_c
./adveccion
