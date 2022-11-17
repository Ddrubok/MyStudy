using System;
using System.Collections.Generic;

namespace CSharp
{
    class Program
    {
        static int factorial(int n)
        {
            if (n == 0)
                return 1;
            return n* factorial((n-1));
        }
        static void Main(string[] args)
        {
            Console.WriteLine(factorial(5)); 
        }
    }
}
