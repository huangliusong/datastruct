void Train_Arrange(char *train)
{
    //'HSHSHHSSHSHSHSHSHSH'
    char *p = train, *q = train, c;
    stack s;
    InitStack(s); //初始化栈结构
    while (*p)
    {
        if (*p == 'H')
        {
            Push(s, *p); //把H入栈
        }
        else
        {
            *(q++) = *p; //把S调到前部
        }
        p++;
    }
    while (!StackEmpty(s))
    {
        Pop(s, c);
        *(q++) = c; //把H接在后面
    }
}
