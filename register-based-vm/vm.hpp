//
//  vm.hpp
//  register-based-vm
//
//  Created by Chidume Nnamdi on 21/01/2026.
//

#ifndef vm_hpp
#define vm_hpp

#include <stdio.h>
#include <iostream>

#include "chunk.hpp"
#include "opcodes.hpp"

using namespace std;

class VM {
private:
    int registers[3]; // this hold our registers
    // here, we have only 3 registers for our vm. these are where arithmetic vm operations are carried out.
    
    int ip = 0; // this is the instruction pointer. it points to the current index
    // of instruction to be executed by the vm.
    
    Chunk* chunk = nullptr;
    
    Instruction read_instruction() {
        int current_ip = ip;
        ip++;
        return chunk->read_code(current_ip);
    }
    
public:
    
    void load(Chunk& c) {
        chunk = &c;
    }
    
    void run() {
        while (true) {
            
            Instruction instruct = read_instruction();
            
            switch (instruct.opcode) {
                case OpCode::LoadConstant: {
                    // we know that the index of the constant is in reg B.
                    int constant_index = instruct.regB;
                    // read the constant from the constants pool
                    int constant = chunk->read_constant(constant_index);
                    // store the constant to register A
                    registers[instruct.regA] = constant;
                    break;
                }
                    
                case OpCode::Add: {
                    // Add has the format a,b,c
                    
                    //  we get the values from the registers
                    int first_value = registers[instruct.regB];
                    int second_value = registers[instruct.regC];
                    
                    int sum = first_value + second_value;
                    
                    // save the 'sum' to register a
                    registers[instruct.regA] = sum;
                    break;
                }
                    
                case OpCode::Print: {
                    cout << registers[instruct.regA] << endl;
                    // we need to brea here, otherwise the execution will only spill over to the OpCode::Halt
                    break; // bug fixed
                }
                    
                case OpCode::Halt: {
                    return;
                }
                    
                default:
                    break;
            }
        }
    }
};

#endif /* vm_hpp */
