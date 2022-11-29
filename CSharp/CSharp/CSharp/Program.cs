using System;
using System.Collections.Generic;

namespace CSharp
{
    class Program
    {
        static int GetHighestScore(int[] scores)
        {
            int max = -1;

            for(int i=0; i<scores.Length;i++)
            {
                if(max<scores[i])
                {
                    max = scores[i];
                }
            }
            return max;
        }

        static int GetAverageScore(int[] scores)
        {
            
            int Sumresult = 0;
            if(scores.Length==0)
            {
                return 0;
            }
            for (int i = 0; i < scores.Length; i++)
            {
                Sumresult += scores[i];
            }

            return Sumresult/scores.Length;
        }

        static int GetIndexOf(int[] scores, int value)
        {
            for (int i = 0; i < scores.Length; i++)
            {
                if(scores[i]==value)
                {
                    return i;
                }
            }
            return -1;
        }

        static void Sort(int[] scores)
        {
            while(true)
            {
                bool check = false;
                for(int i=0; i<scores.Length-1;i++)
                {
                    if (scores[i] > scores[i + 1])
                    {
                        int temp = scores[i];
                        scores[i] = scores[i + 1];
                        scores[i + 1] = temp;
                        check = true;
                    }
                }
                if(check==false)
                {
                    break;
                }
            }
        }

        static void Main(string[] args)
        {
            //Game game = new Game();

            //while (true)
            //{
            //    game.Process();
            //}

            int[] scores = new int[5] { 50, 30, 40, 20, 10 };


            Console.WriteLine(GetHighestScore(scores));
            Console.WriteLine(GetAverageScore(scores));
            Console.WriteLine(GetIndexOf(scores,15));

            Sort(scores);
            Console.WriteLine();
            for(int i=0; i<scores.Length;i++)
            {
                Console.WriteLine(scores[i]);
            }
        }
    }
}
