#include "debug.h"
#include "common.h"
#include "chunk.h"
#include "vm.h"
#include "perf.h"

int main(int argc, const char *argv[])
{
    VM vm;
    Chunk chunk;

    initVM();
    initChunk(&chunk);

    writeConstant(&chunk, 1.2, 1);
    writeConstant(&chunk, 3.4, 1);
    writeChunk(&chunk, OP_ADD, 1);

    writeConstant(&chunk, 5.6, 1);
    writeChunk(&chunk, OP_DIVIDE, 1);

    writeChunk(&chunk, OP_NEGATE, 1);

    writeChunk(&chunk, OP_RETURN, 1);

    disassembleChunk(&chunk, "test chunk");
    MEASURE_CPU_TIME_USED({ interpret(&chunk); }, "interpret test chunk");

    freeChunk(&chunk);
    freeVM();

    return 0;
}