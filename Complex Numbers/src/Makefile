# Makefile for ComplexNumber

runComplexNum: main.o ComplexNumber.o
	      g++ -g main.o ComplexNumber.o -o runComplexNum

ComplexNumber.o: ComplexNumber.cpp ComplexNumber.h
	      g++ -g -c ComplexNumber.cpp

main.o: main.cpp ComplexNumber.h
	      g++ -g -c main.cpp
