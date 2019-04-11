#ifndef IR_INSTR_HPP
#define IR_INSTR_HPP
#include <cstdint>
#include <vector>

namespace IR
{

enum Opcode
{
#define INSTR(name) name,
#include "ir_instrlist.inc"
#undef INSTR
};

class Instruction
{
    private:
        uint32_t jump_dest, jump_fail_dest;
        uint32_t return_addr;

        int dest, base;
        uint64_t source, source2;
        uint8_t bc, field, field2;
        bool is_likely, is_link;
    public:
        Opcode op;

        Instruction(Opcode op = Null);

        uint32_t get_jump_dest() const;
        uint32_t get_jump_fail_dest() const;
        uint32_t get_return_addr() const;
        int get_dest() const;
        int get_base() const;
        uint64_t get_source() const;
        uint64_t get_source2() const;
        uint8_t get_bc() const;
        uint8_t get_field() const;
        uint8_t get_field2() const;
        bool get_is_likely() const;
        bool get_is_link() const;

        void set_jump_dest(uint32_t addr);
        void set_jump_fail_dest(uint32_t addr);
        void set_return_addr(uint32_t addr);
        void set_dest(int index);
        void set_base(int index);
        void set_source(uint64_t value);
        void set_source2(uint64_t value);
        void set_bc(uint8_t value);
        void set_field(uint8_t value);
        void set_field2(uint8_t value);
        void set_is_likely(bool value);
        void set_is_link(bool value);

        bool is_jump();
};

};

#endif // IR_INSTR_HPP
