#define NOB_IMPLEMENTATION
#include "nob.h"

#define BUILD_FOLDER "build/"
#define SRC_FOLDER "src/"

int main(int argc, char **argv)
{
    NOB_GO_REBUILD_URSELF(argc, argv);

    Nob_Cmd cmd = {0};

    // Compilador
    nob_cmd_append(&cmd, "gcc");

    // CFLAGS
    nob_cmd_append(&cmd, "-O1", "-Wall", "-std=c99", "-Wno-missing-braces");
    nob_cmd_append(&cmd, "-Iinc");

    // Output Binary
    nob_cmd_append(&cmd, "-o", BUILD_FOLDER "main.exe");

    // Input Source Files
    nob_cmd_append(&cmd, SRC_FOLDER "main.c");

    // LDFLAGS
    nob_cmd_append(&cmd, "-Llib");
    nob_cmd_append(&cmd, "-lraylib", "-lopengl32", "-lgdi32", "-lwinmm");

    // Static Linking (optional)
    // nob_cmd_append(&cmd, "-static", "-static-libgcc", "-static-libstdc++");

    if (!nob_cmd_run(&cmd))
        return 1;

    return 0;
}