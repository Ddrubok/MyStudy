using Algorithm;
using System;
using System.Collections.Generic;

namespace CSharp
{
    class Program
    {
        
        static void Main(string[] args)
        {
            Player player = new Player();
           

            Board board = new Board();
            
            board.Initalize(25, player);
            player.Initialize(1, 1, board.Size-2, board.Size-2, board);

            Console.CursorVisible = false;
            const int WAIT_TICK = 1000 / 30;

            int lastTick = 0;

            while (true)
            {
                #region 프레임 관리
                int currentTick = System.Environment.TickCount;
                if (currentTick - lastTick < WAIT_TICK)
                    continue;
                int delaTick = currentTick - lastTick;
                lastTick = currentTick;
                #endregion

                player.Update(delaTick);
                Console.SetCursorPosition(0, 0);
                board.Render();
            }
        }
    }
}
