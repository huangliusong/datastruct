Queue q;  // 过江渡船载渡队列
Queue q1; //客车队列
Queue q2; //货车队列
void manager()
{
    //j表示渡船上的总的车辆数
    int i = 0, j = 0;
    //
    while (j < 10)
    {
        //课程队列不为空，并且不足4靓车
        if (!QueueEmpty(q1) && i < 4)
        {
            DeQueue(q1, x); //从客车队列出中出队列
            EnQueue(q, x);  //上船队列
            i++;            //客车+1
            j++;            //船上+1
        }
        else if (i == 4 && QueueEMpty(q2))
        {
            DeQueue(q2, x);
            EnQueue(q, x);
            j++;   //船上+1
            i = 0; //每次上一辆货车，i从新计算
        }
        else /* 客车队列为空或者货车队列为空 */
        {
            while (j < 10 && i < 4 && !QueueEmpty(q2)) //客车队列为空
            {
                DeQueue(q2, x);
                EnQueue(q, x);
                i++;
                j++;
            }
            i = 0;
        }
        if (QueueEmpty(q1) && QueueEmpty(q2))
        {
            j = 11;
        }
    }
}