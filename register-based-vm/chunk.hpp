//
//  chunk.hpp
//  register-based-vm
//
//  Created by Chidume Nnamdi on 21/01/2026.
//

#ifndef chunk_hpp
#define chunk_hpp

#include <stdio.h>
#include <vector>

using namespace std;

struct Instruction {
    u_int8_t opcode;
    int regA;
    int regB;
    int regC;
};

class Chunk {
  
private:
    vector<Instruction> codes;
    vector<int> constants;
    
public:
    void push_code(Instruction instruction_code) {
        codes.push_back(instruction_code);
    }
    
    int push_constant(int constant_value) {
        constants.push_back(constant_value);
        return (int)constants.size() - 1;
    }
    
    Instruction read_code(int index) {
        return codes[index];
    }
    
    int read_constant(int constant_index) {
        return constants[constant_index];
    }
    
};

#endif /* chunk_hpp */
