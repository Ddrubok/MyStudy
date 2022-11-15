using System;
using System.Collections.Generic;

namespace CSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            Dictionary<int, List<int>> a = new Dictionary<int, List<int>>();

            if (!a.ContainsKey(1))
                a[1] = new List<int>();
            a[1].Add(1);
        }
    }
}
