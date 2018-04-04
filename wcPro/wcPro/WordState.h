// Copyright[2018]<Star>
#pragma once
// Macro definition of different states
#define    INNERWORD    1    // State One: Word Internal
#define    CRITICAL     2    // State two: Critical (receives a hyphen)
#define    OUTERWORD    3    // State three: Word Outside
typedef int stateType;

#define    PROCESS_11    0x11    // Process: state one to state one
#define    PROCESS_12    0x12    // Process: state one to state two
#define    PROCESS_13    0x13    // Process: state one to state three
#define    PROCESS_21    0x21    // Process: state two to state one
#define    PROCESS_23    0x23    // Process: state two to state three
#define    PROCESS_31    0x31    // Process: state three to state one
#define    PROCESS_33    0x33    // Process: state three to state three
typedef int processType;

class WordState {
 private:
    stateType state;
 public:
    WordState();
    processType  stateTransfer(char c);
};
