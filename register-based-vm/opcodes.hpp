//
//  opcodes.hpp
//  register-based-vm
//
//  Created by Chidume Nnamdi on 21/01/2026.
//

#ifndef opcodes_hpp
#define opcodes_hpp

#include <stdio.h>

enum OpCode: u_int8_t {
    LoadConstant, // the format will be LoadConstant a, b. It will load the constant in the b index from the
    // constants pool to the register a.
    Add, // The format will be Add a, b, c. This will add the values in registers b, c and store it in
    // register a.
    Print, // the format will be Print a. This will print the value in register a
    Halt // this will halt the vm operation.
};

#endif /* opcodes_hpp */
