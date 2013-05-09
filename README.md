# OO-IO
# A simple Oriented Object - Input Output library.
We want to obtain a powerfull abstraction of input/output.
A lot of designs exist, this one is using delegate and is build for :
- obtain a fast listener mechanism (delegate)
- the input user can simply use A LOT of it (to subscribe you don't need to inherit to a boring interface)
- offer an interface to be SOLID compliant

# Prerequisite:
It will help you to understand some concept before using it :
- the listener pattern
- the delegate mechanism

Wikipedia is your friend as a first step !

# Example:
First you can take a look on unitTest.

# Command :
 - build library -> $(workingdirectory)/scons
 - build and run tests -> $(workingdirectory)/UnitTest/scons

# Environnment :
-> scons and cxxtest needed.
-> Eclipse project (Juno SR2, CDT 8).
