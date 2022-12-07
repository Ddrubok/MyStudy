using System;
using System.Collections.Generic;

namespace CSharp
{
    class Program
    {
      
        static void Main(string[] args)
        {
            Console.CursorVisible = false;
            const int WAIT_TICK = 1000 / 30;
            const char CIRCLE = '\u25cf';

            int lastTick = 0;

            while(true)
            {
                #region 프레임 관리
                int currentTick = System.Environment.TickCount;
                if (currentTick - lastTick < WAIT_TICK)
                    continue;
                lastTick = currentTick;
                #endregion

                Console.SetCursorPosition(0, 0);

                for(int i=0; i<25; i++)
                {
                    for(int j =0;j<25;j++)
                    {
                        Console.ForegroundColor = ConsoleColor.Green;
                        Console.Write(CIRCLE);
                    }
                    Console.WriteLine();
                }
            }
        }
    }
}
