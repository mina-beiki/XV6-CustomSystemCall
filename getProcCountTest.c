#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(void)
{
    int result = getProcCount();
    printf(1, "number of processes = %d\n", result);
    exit();
}