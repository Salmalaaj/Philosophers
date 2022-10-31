#include "philosophers.h"

int main(int argc, char **argv)
{
    t_list  ph;

    if ((argc >= 5 && argc <= 6) && error_check(argv) == 0)
    {
        assign(&ph, argv);
    }
    else
        printf("Error in arguments :)!\n");
}
