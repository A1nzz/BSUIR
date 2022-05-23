using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab6
{
    abstract public class Toys
    {
        public Toys()
        {
            Name = "";
            Price = 0;
            Console.WriteLine("Abstract Class Constructor");
        }
        public abstract string Name { get; set; }

        public abstract double Price { get; set; }

        public abstract int Count { get; set; }


        public abstract void GetInfo();

        public virtual void GetageRestriction()
        {
            Console.WriteLine("Age restriction: 0+");
        }

        public void Buy()
        {
            Console.WriteLine("You bought a toy " + Name + " for " + Price + " dollars");
        }

        public virtual double getTotalSum()
        {
            return Price * Count;
        }
    }



    public sealed class Doll : Toys
    {
        private int count;
        
        public override int Count
        {
            get { return count; }
            set { count = value; }
        }

        private string name;

        public override string Name
        {
            get { return name; }
            set { name = value; }
        }

        private double price;
        
        public override double Price
        {
            get { return price; }
            set { price = value; }
        }

        public string gender;
        public string Gender
        {
            get { return gender; }
            set { gender = value; }
        }

        public Doll(string name, string gender, double price, int count)
        {
            this.name = name;
            this.gender = gender;
            this.price = price;
            this.count = count;
        }
        public override void GetInfo()
        {
            Console.WriteLine("Name: " + Name);
            Console.WriteLine("Gender: " + Gender);
            Console.WriteLine("Price: " + Price.ToString());    
        }

        public new void Buy()
        {
            Console.WriteLine("You bought a toy " + Name + "(" + gender + ") for " + Price + " dollars");
        }

        

    }

    public class Car : Toys
    {
        private int count;

        public override int Count
        {
            get { return count; }
            set { count = value; }
        }

        private  string name;

        public override string Name
        {
            get { return name; }
            set { name = value; }
        }

        private double price;

        public override double Price
        {
            get { return price; }
            set { price = value; }
        }

        public Car(string name,double price, int count)
        {
            this.name = name;
            this.price = price;
            this.count = count;
        }

        public override void GetInfo()
        {
            Console.WriteLine("Name: " + Name);
            Console.WriteLine("Price: " + Price.ToString());
        }
    }

    public class Lego : Toys
    {
        private int count;

        public override int Count
        {
            get { return count; }
            set { count = value; }
        }

        private string name;

        public override string Name
        {
            get { return name; }
            set { name = value; }
        }

        private double price;

        public override double Price
        {
            get { return price; }
            set { price = value; }
        }

        private int detailsNumber;

        public int DetailsNumber
        {
            get { return detailsNumber; }
            set { detailsNumber = value; }
        }

        public Lego(string name,int detailsNumber, double price, int count)
        {
            this.name = name;
            this.detailsNumber = detailsNumber;
            this.price = price;
            this.count = count;            
        }

        public override void GetInfo()
        {
            Console.WriteLine("Name: " + Name);
            Console.WriteLine("Details number: " + detailsNumber.ToString());
            Console.WriteLine("Price: " + Price.ToString());
        }

        public new void Buy()
        {
            Console.WriteLine("You bought a toy " + Name + " with "+ detailsNumber + " details for " + Price + " dollars");
        }

        public override void GetageRestriction()
        {
            Console.WriteLine("Age restriction: 12+");
        }
    }
    
}


