//
//  main.cpp
//  register-based-vm
//
//  Created by Chidume Nnamdi on 20/01/2026.
//

#include <iostream>

#include "vm.hpp"

int main(int argc, const char * argv[]) {
    
    // Let's write our instructions to add 1 + 2
    VM vm;
    Chunk chunk;
    
    int register_index = 0;
    
    int first_constant_reg_index = register_index; // holds the register index where the constant 1 is stored.
    
    chunk
        .push_code({OpCode::LoadConstant, first_constant_reg_index, chunk.push_constant(90)});
    
    register_index++;
    int second_constant_reg_index = register_index; // this holds the register index where the constant 2 is stored
    
    chunk
        .push_code({OpCode::LoadConstant, second_constant_reg_index, chunk.push_constant(89)});
    
    register_index++;
    int add_reg_store_index = register_index;
    // this will hold the register index where the summation result is stored.
    
    chunk.push_code({OpCode::Add, add_reg_store_index, first_constant_reg_index, second_constant_reg_index});
    
    chunk.push_code({OpCode::Print, add_reg_store_index}); // this will print the value of add_reg_store_index
    // register
    
    chunk.push_code({OpCode::Halt}); // stops execution
    
    vm.load(chunk); // load the chunk variable in the vm
    vm.run(); // start the machine.
    

    return EXIT_SUCCESS;
}

