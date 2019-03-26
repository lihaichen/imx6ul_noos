void led_init()
{
    // GPIO4_16
    volatile int *mux = (int *)0x020E01B8;
    volatile int *dir = (int *)0x020A8004;
    volatile int *dr = (int *)0x020A8000;
    *mux = (1 << 4) | 5;
    *dir = (*dir) | (1 << 16);
    *dr = (*dr) | (1 << 16);
    // GPIO4_14
    mux = (int *)0x020E01B0;
    *mux = (1 << 4) | 5;
    *dir = (*dir) | (1 << 14);
    *dr = (*dr) | (1 << 14);
}

int led_set_value(int index, int value)
{
    volatile int *dr = (int *)0x020A8000;
    switch (index)
    {
    case 0:
        index = 14;
        break;
    case 1:
        index = 16;
        break;
    default:
        return -1;
    }
    if (value)
    {
        *dr = (*dr) | ((1 << index));
    }
    else
    {
        *dr = (*dr) & (~(1 << index));
    }
    return 0;
}
