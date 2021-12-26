cmake_minimum_required(VERSION 3.20)
project(HW_3 C)

set(CMAKE_C_STANDARD 99)

add_executable(HW_3 main.c Address.h Address.c Airline.c Airline.h Airport.c Airport.h AirportManager.c AirportManager.h Date.c Date.h Flight.c Flight.h General.h General.c Plane.h Plane.c AirlineBinary.c AirlineBinary.h FlightBinary.c FlightBinary.h PlaneBinary.c PlaneBinary.h DateBinary.c DateBinary.h AirportText.c AirportText.h AirportManagerText.c AirportManagerText.h Compare.c Compare.h list.h list.c )
