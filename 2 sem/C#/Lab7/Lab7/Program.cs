
// See https://aka.ms/new-console-template for more information
namespace Lab7
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
            PlentyOfSymbols symbols1 = new PlentyOfSymbols("symbols1");
            PlentyOfSymbols symbols2 = new PlentyOfSymbols("symbols2");

            symbols1.Print();
            symbols2.Print();
            PlentyOfSymbols plusResult = symbols1 + symbols2;
            plusResult.Print();
            PlentyOfSymbols symbols0 = new PlentyOfSymbols();
            PlentyOfSymbols plusResult0 = symbols0 + symbols0;
            plusResult0.Print();
            PlentyOfSymbols minusResult = symbols1 - symbols2;
            minusResult.Print();
            PlentyOfSymbols multiplicationResult = symbols1 * symbols2;
            multiplicationResult.Print();
            Console.WriteLine("symbols1 == symbols2: " + (symbols1 == symbols2));
            Console.WriteLine("symbols1 != symbols2: " + (symbols1 != symbols2));

        }
    }
}


