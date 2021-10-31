<div align="center">
  <img alt="Alma Mater Studiorum Logo" src="assets/unibo-logo.png">
</div>

# kstar-decayment-analysis
This is my project for my Physics laboratory-2 course at University of Bologna.
The goal of this project is to simulate a real-world use case for ROOT software.
The project is divided in two parts. Firstly, we will generate data using the
Montecarlo method, then we will analyze that data using ROOT's powerful
instruments. The data we will be generating will mimic the real-world ALICE
experiment at CERN. We want to prove that the K* particle exists in an unstable
state that decays in a pion-kaon pair; to do that, we will be generating "mock"
particle data, (which simulates real-world data acquired from CERN).
If the K* particle exists, we will find some statistical discrepancies in the
resulting data during the second phase of the prohect.

## setting up jupyter
todo all this

also, todo this should prob be added as custom cmake/make command, not bothering
for now.

pipenv is required

pipenv install
pipenv run jupyter-lab

all set. If on wsl, follow the link in console.
Otherwise, it should open by itself.


if there is a permission error on wsl, chown the crap outta it

note that root --notebook is bugged asf

also note that c++ root kernel is slow at loading. Have patience.


## Dependencies
- [ROOT](https://root.cern/) (required, version 6.18^)
todo

## Running
This code was tested and running on _Mac OS X 10.14.6 Mojave_.
Please note that this is still WIP, I will update this section later.

--------------------------------------------------------------------------------

## Additional notes
TBD
