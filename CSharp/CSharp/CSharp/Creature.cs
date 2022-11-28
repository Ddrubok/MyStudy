using System;
using System.Collections.Generic;
using System.Text;

namespace CSharp
{
    public enum CreatureType
    {
        None,
        Player = 1,
        Monster = 2
    }
    class Creature
    {
        CreatureType type;
        protected Creature(CreatureType type)
        {
            this.type = type;
        }

        protected int hp = 0;
        protected int attack = 0;

        public void SetInfo(int hp, int attack)
        {
            this.hp = hp;
            this.attack = attack;
        }

        public bool IsDead
        {
            get
            {
                return hp <= 0;
            }
        }

        public void OnDamaged(int damage)
        {
            hp -= damage;
            if (hp < 0)
                hp = 0;
        }

        public int HP
        {
            get
            {
                return hp;
            }
            set
            {
                hp = value;
            }
        }
        public int Attack
        {
            get
            {
                return attack;
            }
            set
            {
                attack = value;
            }
        }
    }
}
