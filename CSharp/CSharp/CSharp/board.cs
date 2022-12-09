using CSharp;
using System;
using System.Collections.Generic;
using System.Text;

namespace Algorithm
{
    class MyList<T>
    {
        const int DEFAULT_SIZE = 1;
        T[] _data = new T[DEFAULT_SIZE];
        public int Count = 0;
        public int Capacity
        {
            get
            {
                return _data.Length;
            }
        }
        public void Add(T item)
        {
            if (Capacity <= Count)
            {
                T[] newArray = new T[Count * 2];
                for (int i = 0; i < Count; i++)
                {
                    newArray[i] = _data[i];
                }
                _data = newArray;
            }

            _data[Count] = item;
            Count++;
        }

        public T this[int index]
        {
            get { return _data[index]; }
            set { _data[index] = value; }
        }

        public void RemoveAt(int index)
        {
            for (int i = index; i < Count - 1; i++)
            {
                _data[i] = _data[i + 1];
            }
            _data[Count - 1] = default(T);

            Count--;
        }

    }


    class MyLinkedListNode<T>
    {
        public T Data;
        public MyLinkedListNode<T> Next = null;
        public MyLinkedListNode<T> Prev = null;
    }

    class MyLinkedList<T>
    {
        public MyLinkedListNode<T> Head;
        public MyLinkedListNode<T> Tail;
        public int Count = 0;

        public MyLinkedListNode<T> AddLast(T data)
        {
            MyLinkedListNode<T> newRoom = new MyLinkedListNode<T>();
            newRoom.Data = data;

            if (Head == null)
            {
                Head = newRoom;
            }

            if (Tail != null)
            {
                Tail.Next = newRoom;
                newRoom.Prev = Tail;
            }

            Tail = newRoom;
            Count++;
            return newRoom;
        }
        public void Remove(MyLinkedListNode<T> room)
        {
            if (Head == room)
            {
                Head = Head.Next;
            }
            if (Tail == room)
            {
                Tail = Tail.Prev;
            }
            if (room.Prev != null)
            {
                room.Prev.Next = room.Next;
            }

            if (room.Next != null)
            {
                room.Next.Prev = room.Prev;
            }
            Count--;
        }
    }

    class Board
    {
        public TileType[,] Tile { get; private set; }
        public int Size { get; private set; }

        const char CIRCLE = '\u25cf';
        Player player;

        public int DestX { get; private set; }
        public int DestY { get; private set; }

        public enum TileType
        {
            Empty,
            Wall,
            Player,
        }
        //BinaryTree
        public void GenerateByBinaryTree()
        {
            for (int y = 0; y < Size; y++)
            {
                for (int x = 0; x < Size; x++)
                {
                    if (x % 2 == 0 || y % 2 == 0)
                        Tile[y, x] = TileType.Wall;
                    else
                        Tile[y, x] = TileType.Empty;
                }
            }
            Random rand = new Random();
            for (int y = 0; y < Size; y++)
            {
                for (int x = 0; x < Size; x++)
                {
                    if (x % 2 == 0 || y % 2 == 0)
                        continue;
                    if (x == Size - 2 && y == Size - 2)
                        continue;

                    if (y == Size - 2)
                    {
                        Tile[y, x + 1] = TileType.Empty;
                        continue;
                    }
                    if (x == Size - 2)
                    {
                        Tile[y + 1, x] = TileType.Empty;
                        continue;
                    }

                    if (rand.Next(0, 2) == 0)
                    {
                        Tile[y, x + 1] = TileType.Empty;
                    }
                    else
                    {
                        Tile[y + 1, x] = TileType.Empty;
                    }


                }
            }
        }

        public void GenerateBySideWinder()
        {
            for (int y = 0; y < Size; y++)
            {
                for (int x = 0; x < Size; x++)
                {
                    if (x % 2 == 0 || y % 2 == 0)
                        Tile[y, x] = TileType.Wall;
                    else
                        Tile[y, x] = TileType.Empty;
                }
            }
            Random rand = new Random();
            for (int y = 0; y < Size; y++)
            {
                int count = 1;
                for (int x = 0; x < Size; x++)
                {
                    if (x % 2 == 0 || y % 2 == 0)
                        continue;
                    if (x == Size - 2 && y == Size - 2)
                        continue;

                    if (y == Size - 2)
                    {
                        Tile[y, x + 1] = TileType.Empty;
                        continue;
                    }
                    if (x == Size - 2)
                    {
                        Tile[y + 1, x] = TileType.Empty;
                        continue;
                    }

                    if (rand.Next(0, 2) == 0)
                    {
                        Tile[y, x + 1] = TileType.Empty;
                        count++;
                    }
                    else
                    {
                        int randomIndex = rand.Next(0, count);
                        Tile[y + 1, x - randomIndex * 2] = TileType.Empty;
                        count = 1;
                    }

                }
            }
        }
        public void Initalize(int size, Player _player)
        {
            if (size % 2 == 0)
                return;
            player = _player;
            Tile = new TileType[size, size];
            Size = size;

            DestY = Size - 2;
            DestX = Size - 2;
            // GenerateByBinaryTree();
            GenerateBySideWinder();
        }
        public void Render()
        {
            ConsoleColor prevColor = Console.ForegroundColor;
            for (int y = 0; y < Size; y++)
            {
                for (int x = 0; x < Size; x++)
                {
                    if (y == player.PosY && x == player.PosX)
                    {
                        Console.ForegroundColor = ConsoleColor.Blue;

                    }
                    else if(y == DestY && x == DestX)
                    {
                        Console.ForegroundColor = ConsoleColor.Yellow;
                    }
                    else
                    {
                        Console.ForegroundColor = GetTileColor(Tile[y, x]);

                    }


                    Console.Write(CIRCLE);
                }
                Console.WriteLine();
            }
            Console.ForegroundColor = prevColor;
        }
        ConsoleColor GetTileColor(TileType type)
        {
            switch (type)
            {
                case TileType.Empty:
                    return ConsoleColor.Green;
                case TileType.Wall:
                    return ConsoleColor.Red;
                case TileType.Player:
                    return ConsoleColor.White;
                default:
                    return ConsoleColor.Green;
            }
        }
    }
}
