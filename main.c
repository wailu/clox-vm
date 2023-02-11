#include "debug.h"
#include "common.h"
#include "chunk.h"
#include "vm.h"

int main(int argc, const char *argv[])
{
    VM vm;
    Chunk chunk;

    initVM();
    initChunk(&chunk);

    writeConstant(&chunk, 1.2, 123);
    writeConstant(&chunk, 4.6, 456);
    writeChunk(&chunk, OP_RETURN, 456);
    // disassembleChunk(&chunk, "test chunk");
    interpret(&chunk);

    freeChunk(&chunk);
    freeVM();

    return 0;
}