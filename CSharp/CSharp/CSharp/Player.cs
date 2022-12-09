using Algorithm;
using System;
using System.Collections.Generic;
using System.Text;

namespace CSharp
{
    class Pos
    {
        public Pos(int y, int x) { Y = y;X = x; }
        public int Y;
        public int X;
    }
    class Player
    {
        public int PosY { get; private set; }
        public int PosX { get; private set; }
        Random _random = new Random();

        Board _board;

        enum Dir
        {
            Up = 0,
            Left = 1,
            Down = 2,
            Right = 3,
        }

        int _dir = (int)Dir.Up;
        List<Pos> _points = new List<Pos>();
        public void Initialize(int posY, int posX, int destY, int destX, Board board)
        {
            PosY = posY;
            PosX = posX;
            _board = board;
            int[] frontY = new int[] { -1, 0, 1, 0 };
            int[] frontX = new int[] { 0, -1, 0, 1 };
            int[] RightY = new int[] { 0, -1, 0, 1 };
            int[] RightX = new int[] { 1, 0, -1, 0 };
            _points.Add(new Pos(posY,posX));
            
            while (PosY != board.DestY || PosX != board.DestX)
            {
                if (_board.Tile[PosY + RightY[_dir], PosX + RightX[_dir]] == Board.TileType.Empty)
                {
                    _dir = (_dir - 1 + 4) % 4;
                    PosY = PosY + frontY[_dir];
                    PosX = PosX + frontX[_dir];
                    _points.Add(new Pos(PosY, PosX));
                }
                else if (_board.Tile[PosY + frontY[_dir], PosX + frontX[_dir]] == Board.TileType.Empty)
                {
                    PosY = PosY + frontY[_dir];
                    PosX = PosX + frontX[_dir];
                    _points.Add(new Pos(PosY, PosX));
                }
                else
                {
                    _dir = (_dir + 1 + 4) % 4;
                }
            }
        }

        public void Move()
        {
            if (_board.Tile[PosY, PosX] != Board.TileType.Wall)
            {

            }
        }

        const int MOVE_TICK = 1;
        int _sumTick = 0;
        int lastIndex = 0;
        public void Update(int _deltaTick)
        {
            _sumTick += _deltaTick;
            if (_sumTick >= MOVE_TICK)
            {
                _sumTick = 0;
                
                PosY = _points[lastIndex].Y;
                PosX = _points[lastIndex].X;
                if (lastIndex + 1 == _points.Count)
                    return;
                    lastIndex++;
            }
        }

    }
}


//int randValue = _random.Next(0, 4);
//switch (randValue)
//{
//    case 0:
//        if (PosY - 1 >= 0 && _board.Tile[PosY - 1, PosX] == Board.TileType.Empty)
//            PosY = PosY - 1;
//        break;
//    case 1:
//        if (PosY + 1 < _board.Size && _board.Tile[PosY + 1, PosX] == Board.TileType.Empty)
//            PosY = PosY + 1;
//        break;
//    case 2:
//        if (PosX - 1 >= 0 && _board.Tile[PosY, PosX - 1] == Board.TileType.Empty)
//            PosX = PosX - 1;
//        break;
//    case 3:
//        if (PosX + 1 < _board.Size && _board.Tile[PosY, PosX + 1] == Board.TileType.Empty)
//            PosX = PosX + 1;
//        break;
//}