# Level Indicator
 Level indicator (Model based software design assignement)
 The aim of this project is implementing a level indicator composed by and ultrasonic ranging sensor and a ranging estimator exchanging a trig and an echo response signal and a level  output (provided by the ranging estimator).
The project is divided in several parts:
1) Simulink project containing two referenced subsystems properly interconnected:
- Plant: containing a model of the ultrasonic ranging sensor for simulation purposes only. 
- Controller: containing a model of the ranging estimator for code generation purposes.
2) C code for the controller obtained through code generation (using compact file placement and reusable function interface).
3) GoogleTest-based unit testing for the controller code providing 100% statement and 100% branch coverage.
4) Source code that integrates the generated code into the Trampoline RTOS. The ultrasonic sensor will be simulated in C code and the Level output will be printed on the console.
5) Simulink model that deploys the ranging estimator to Arduino Uno as hardware using the
HC-SR04 as ranging sensor and the Arduino Uno built-in LED as Level output.

# Technical information
- The project was developed under Matlab2020b and Simulink
- The following addons were used: Matlab code, Simulink coder, Matlab support package for arduino, simulink support package for arduino, DSP system toolbox, symbolic math toolbox, stateflow, embedded coder, simulink report generator, simulink coverage, simulink requirements, simulink test, matlab report generator, mixed signal
- All Trampoline RTOS related tests were performed under trampoline/examples/posix/periodic folder (inside the Trampoline folder)

# Unzip and open the project in Matlab
Due to github limits I uploaded two zip files containing all the related simulink and matlab files.
Do not open each file individually, open the entire project in matlab clicking on the harness file inside the project folder.
