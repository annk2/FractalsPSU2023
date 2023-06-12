struct state
{
    double x;
    double y;
    double angle;
};

void string_interpreter(char string[100000], double p[2], double distance, double start_angle, double delta)
{
    int len = strlen(string);
    char cur;
    double x, y, hold_x, hold_y, angle;
    struct state[10000];
    int top = 0;

    x = p[0];
    y = p[1];

    angle = start_angle;

    for (int i = 0; i<len; i++)
    {
        cur = string[i];

        if(cur >= 'A' && cur <= 'Z')
        {
            hold_x = x;
            hold_y = y;
            // use cos/sin to get x and y?
            G_line(hold_x, hold_y, x, y);
        }
        else if(cur == '+')
        {
            angle += delta;
        }
        else if(cur == '-')
        {
            angle -= delta;
        }
        else if(cur == '[')
        {

        }

    }
    // loop through string
    // line if letter
    // + increase angle
    // - decrease angle
    // [ save position
    // ] return to saved position
    // [] are in a stack
}