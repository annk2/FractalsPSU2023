struct state
{
    double x;
    double y;
    double angle;
};

void string_interpreter(char string[100000], struct GRAMMAR grammar[5], double p[2])
{
    int len = strlen(string);
    char cur;
    double x, y, hold_x, hold_y, angle;
    struct state stack[10000];
    int top = 0;

    x = p[0];
    y = p[1];

    double angle = grammar[0].start_angle;
    double delta = grammar[0].angle;
    double length = grammar[0].length;

    for (int i = 0; i<len; i++)
    {
        cur = string[i];

        if(cur >= 'A' && cur <= 'Z')
        {
            hold_x = x + length * cos(angle * M_PI / 180.0);
            hold_y = y + length * sin(angle * M_PI / 180.0);
            G_line(hold_x, hold_y, x, y);
            x = hold_x;
            y = hold_y;
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
            // push state
            stack[top].x = x;
            stack[top].y = y;
            stack[top].angle = angle;
            top++;
        }
        else if(cur == ']')
        {
            // pop state
            x = stack[top].x;
            y = stack[top].y;
            angle = stack[top].angle;
            top--;
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