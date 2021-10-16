#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(void)
{
    int result = getReadCount();
    printf(1, "Number of reads: %d", result);
    exit();
}