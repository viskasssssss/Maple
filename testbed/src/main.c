#include <core/logger.h>
#include <core/asserts.h>

int main(void) {
    MFATAL("test message:  %f", 3.14f);
    MERROR("test message:  %f", 3.14f);
    MWARN("test message:  %f", 3.14f);
    MINFO("test message:  %f", 3.14f);
    MDEBUG("test message:  %f", 3.14f);
    MTRACE("test message:  %f", 3.14f);

    MASSERT(1 == 0);

    return 0;
}