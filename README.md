# A simple Oriented Object - Input Output library (OO-IO)
## Goals :
- a powerfull abstraction of input/output.
- SOLID compliant.

## Classes already implemented
### Digital Input
A lot of designs exist, this one is using delegate and is build for :
- obtain a fast listener mechanism (delegate)
- the input user can simply use A LOT of it (to subscribe you don't need to inherit to a boring interface)

### Digital Input
A simple borring interface

### Single Ended ADC
An ADC could be used in different mode. Single Ended mode is here to measure one input compare to ground.

## Prerequisite:
It will help you to understand some concepts before using it (wikipedia is your friend):
- the listener pattern
- ADC component
- the delegate mechanism

## Example:
First you can take a look on "Example folder".
- build example -> $(workingdirectory)Examples/scons check
- run example to see outputs -> ./$(workingdirectory)Examples/example
For further details have a look on unitTest.

## Command :
 - build library -> $(workingdirectory)/scons
 - build and run tests -> $(workingdirectory)/scons check

## Environnment :
-> gcc
-> scons and cxxtest needed.
-> Eclipse project (Juno SR2, CDT 8) for .project and .cproject.
