namespace Lab8
{
    class Program
    {
        static void Main(string[] args)
        {
            Hotel h = new Hotel();
            h.AddAbsDiscount(101, 2, 25);
            h.AddAbsDiscount(102, 3, 30);
            h.AddAbsDiscount(103, 4, 35);
            h.AddNoDiscount(104, 4);
            Console.WriteLine(h.GetTotalPrice());
        }
    }
}
