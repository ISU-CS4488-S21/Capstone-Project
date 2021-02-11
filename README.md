# Capstone-Project

Generator Unit Commitment using the Lagrange Relaxation and Dynamic Programming Methods

Objective: develop the core engine for solving the unit commitment problem in networks with up to 15 generators.

Constraints:
Code is delivered in C++ 2011.
Minimize the use of classes. Build a dynamic programming class.

Specifications:
Run a time sequence of 24 hours ahead of the current generator operating state vector given the short-term load forecast. Load forecast data comes in 15 minute increments.
Generators have specified starting costs, operating cost (as a second-order polynomial, banking costs, minimum up time, minimum down time.
System has a specified spinning reserve requirement and a 24 hour load forecast.
The UC engine must present a solution every 15 minutes for the grid operators.

Assumptions
A load forecasting application provides an updated 24-hr ahead forecast every 15 minutes.
The cost of fuel is constant.
There is sufficient labor to operate each generation plant. No labor modeling is needed.
Power losses in the transmission network are negligible.

Resources
Review chapter 5 of Power Generation, Operation and Control
