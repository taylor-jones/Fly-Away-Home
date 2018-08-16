# Makefile for CS 162 - Final Project

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

LDFLAGS = -lboost_date_time


OBJS = main.o util.o menu.o Element.o
OBJS += Space.o Game.o Island.o Alien.o
OBJS += Grass.o Water.o Road.o Sand.o OuterSpace.o HomeLand.o Slider.o
OBJS += Elevator.o Mailbox.o Bag.o Item.o
OBJS += Money.o Food.o ShipPiece.o Innertube.o SpeedSkates.o IcarusWings.o
OBJS += Binoculars.o Decoy.o Doorway.o Spaceship.o
OBJS += Earthling.o Wizard.o Cartographer.o Shark.o Bookie.o

SRCS = main.cpp util.cpp menu.cpp Element.cpp
SRCS += Space.cpp Game.cpp Island.cpp Alien.cpp
SRCS += Grass.cpp Water.cpp Road.cpp Sand.cpp OuterSpace.cpp HomeLand.cpp Slider.cpp
SRCS += Elevator.cpp Mailbox.cpp Bag.cpp Item.cpp
SRCS += Money.cpp Food.cpp ShipPiece.cpp Innertube.cpp SpeedSkates.cpp IcarusWings.cpp
SRCS += Binoculars.cpp Decoy.cpp Doorway.cpp Spaceship.cpp
SRCS += Earthling.cpp Wizard.cpp Cartographer.cpp Shark.cpp Bookie.cpp

HEADERS = util.hpp menu.hpp Structures.hpp Element.hpp
HEADERS += Space.hpp Game.hpp Island.hpp Alien.hpp
HEADERS += Grass.hpp Water.hpp Road.hpp Sand.hpp OuterSpace.hpp HomeLand.hpp Slider.hpp
HEADERS += Elevator.hpp Mailbox.hpp Bag.hpp Item.hpp
HEADERS += Money.hpp Food.hpp ShipPiece.hpp Innertube.hpp SpeedSkates.hpp IcarusWings.hpp
HEADERS += Binoculars.hpp Decoy.hpp Doorway.hpp Spaceship.hpp
HEADERS += Earthling.hpp Wizard.hpp Cartographer.hpp Shark.hpp Bookie.hpp


EXEC = play


build: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o ${EXEC}

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm -f *.o ${EXEC}