// Copyright[2018]<Star>
#include "WordState.h"



WordState::WordState() {
    state = OUTERWORD;
}


processType WordState::stateTransfer(char c) {
    // Pass in a character, calculate the next state based on
    // this character and the current state
    // and return a process indicating how the state was migrated
    processType process = state << 4;

    // state transition code
    if ((c >= 'a') && (c <= 'z')) {
        state = INNERWORD;
    } else if (c == '-') {
            if (state == INNERWORD)
                state = CRITICAL;
            else
                state = OUTERWORD;
    } else {
        state = OUTERWORD;
    }

    process = process | state;
    return process;
}
