#include "rcwt.h"
#include "VirtualMachine.h"
#include "JITCompiler.h"

//#ifdef __GNUC__
//immediate sub(immediate a) {
//    immediate __lambda_expression__ (immediate b) {
//        return new immediate(a - b.i);
//    }
//    return new immediate(__lambda_expression__);
//}
//#endif

uint32_t ti;
#define write_int(i) ti = i;fout.write((char*) &ti, 4)
#define write_str(s) fout << s << '\0'

int main() {
    auto tmp = 0x02010012u;
    instruction test_ins[] = {
            *(instruction*)&tmp
    };
    char* test_str[] = {
            "main",
            "move"
    };
    (new JITCompiler(test_str))->compile("test", test_ins, 1);
//    auto vm = new VirtualMachine;
//    ofstream fout("test.wc", ios::in | ios::binary);
//    if (!fout) { cout << "!" << endl; }
//    write_int(0xdeadbeefu); // magic
//    write_int(0x00000000u); // constant_pool_count: 0
//    write_int(0x00000001u); // field_count: 1
//    write_int(0x00000002u); // method_count: 2
//    write_int(0x00000004u); // function_size: 4
//    write_int(0x11010000u); // ipush 1
//    write_int(0x40000000u); // new 0 0
//    write_int(0x49010000u); // calld 1
//    write_int(0x16000000u); // ret
//    write_int(0x00000004u); // function_size: 4
//    write_int(0x11020000u); // ipush 2
//    write_int(0x4c000000u); // self
//    write_int(0x46000000u); // setd  0
//    write_int(0x16000000u); // ret
//    write_int(0x00000001u); // constructor_count: 1
//    write_int(0x00000005u); // constructor_size: 5
//    write_int(0x4c000000u); // self
//    write_int(0x46000000u); // setd  0
//    write_int(0x49010000u); // calld 1
//    write_int(0x4c000000u); // self
//    write_int(0x16000000u); // ret
//    write_int(0x00000000u); // entry_point: 0
//    fout.flush();
//    auto tmp = vm->converter->WCtoMemory("test");
//    vm->execute(tmp);
}

#undef write_int
#undef write_str