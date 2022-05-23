using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab7
{
    public class PlentyOfSymbols
    {

        private char[]? symbolsArr;
        public char[]? SymbolsArr
        {
            get { return symbolsArr; }
            set
            {
                symbolsIsCorrect(symbolsArr);
                symbolsArr = value;
            }
        }

        public PlentyOfSymbols()
        {
            symbolsArr = null;
        }

        public PlentyOfSymbols(char[] symbols)
        {
            SymbolsArr = symbols;
        }

        public PlentyOfSymbols(string symbols)
        {
            SymbolsArr = symbols.ToCharArray();
        }
        public void symbolsIsCorrect(char[]? value)
        {
            if (value == null) return;
            for (int i = 0; i < value.Length; i++)
            {
                for (int j = i + 1; j < value.Length; j++)
                {
                    if (value[i] == value[j])
                    {
                        Console.WriteLine("Ошибка! В множестве не должно быть повторяющихся элементов!");
                        throw new Exception("Ошибка! В множестве не должно быть повторяющихся элементов!");
                    }
                }
            }
        }
        public override string? ToString()
        {
            string str = "";

            if (symbolsArr == null)
            {
                Console.WriteLine("Множество пустое");
                return "";
            }
            else
            {
                for (int i = 0; i < symbolsArr.Length; i++)
                {
                    str += symbolsArr[i] + " ";
                }
                return str;
            }
        }

        public void Print()
        {
            if (symbolsArr == null)
            {
                Console.WriteLine("Множество пустое");
                return;
            }
            Console.WriteLine("Множество символов:");
            for (int i = 0; i < symbolsArr.Length; i++)
            {
                Console.Write(symbolsArr[i] + " ");
            }
            Console.WriteLine();
        }
        public static PlentyOfSymbols operator +(PlentyOfSymbols s1, PlentyOfSymbols s2)
        {
            if (s1.symbolsArr == null && s2.symbolsArr == null)
            {
                Console.WriteLine("Множества пустые");
                return new PlentyOfSymbols();
            }
            else if (s1.symbolsArr == null)
            {
                return s2;
            }
            else if (s2.symbolsArr == null)
            {
                return s1;
            }
            else
            {
                char[] tempArr = new char[s1.symbolsArr.Length + s2.symbolsArr.Length];
                for (int i = 0; i < s1.symbolsArr.Length; i++)
                {
                    tempArr[i] = s1.symbolsArr[i];
                }
                int count = 0;
                for (int i = 0; i < s2.symbolsArr.Length; i++)
                {
                    tempArr[i + s1.symbolsArr.Length] = s2.symbolsArr[i];
                    count++;
                }
                char[] newArr = new char[s1.symbolsArr.Length + count];

                for (int i = 0; i < s1.symbolsArr.Length + count; i++)
                {
                    newArr[i] = tempArr[i];
                }
                return new PlentyOfSymbols(newArr);
            }
        }

        public static PlentyOfSymbols operator -(PlentyOfSymbols s1, PlentyOfSymbols s2)
        {
            if (s1.symbolsArr == null && s2.symbolsArr == null)
            {
                Console.WriteLine("Множества пустые");
                return new PlentyOfSymbols();
            }
            else if (s1.symbolsArr == null)
            {
                return s1;
            }
            else if (s2.symbolsArr == null)
            {
                return s1;
            }
            else
            {
                char[] temp = new char[s1.symbolsArr.Length];
                int j = 0;
                for (int i = 0; i < s1.symbolsArr.Length; i++)
                {
                    bool isIn = false;
                    for (int k = 0; k < s2.symbolsArr.Length; k++)
                    {
                        if (s1.symbolsArr[i] == s2.symbolsArr[k])
                        {
                            isIn = true;
                            break;
                        }
                    }
                    if (!isIn)
                    {
                        temp[j] = s1.symbolsArr[i];
                        j++;
                    }
                }
                char[] newSet = new char[j];
                for (int i = 0; i < j; i++)
                {
                    newSet[i] = temp[i];
                }
                return new PlentyOfSymbols(newSet);
            }
        }

        public static PlentyOfSymbols operator *(PlentyOfSymbols s1, PlentyOfSymbols s2)
        {
            if (s1.symbolsArr == null && s2.symbolsArr == null)
            {
                Console.WriteLine("Множества пустые");
                return new PlentyOfSymbols();
            }
            else if (s1.symbolsArr == null)
            {
                return s1;
            }
            else if (s2.symbolsArr == null)
            {
                return s2;
            }
            else
            {
                char[] newArr = new char[s1.symbolsArr.Length];
                int j = 0;
                for (int i = 0; i < s1.symbolsArr.Length; i++)
                {
                    bool isIn = false;
                    for (int k = 0; k < s2.symbolsArr.Length; k++)
                    {
                        if (s1.symbolsArr[i] == s2.symbolsArr[k])
                        {
                            isIn = true;
                            break;
                        }
                    }
                    if (isIn)
                    {
                        newArr[j] = s1.symbolsArr[i];
                        j++;
                    }
                }
                char[] newSet = new char[j];
                for (int i = 0; i < j; i++)
                {
                    newSet[i] = newArr[i];
                }
                return new PlentyOfSymbols(newSet);
            }
        }

        public static bool operator ==(PlentyOfSymbols s1, PlentyOfSymbols s2)
        {
            if (s1.symbolsArr == null && s2.symbolsArr == null)
            {
                return true;
            }
            else if (s1.symbolsArr == null)
            {
                return false;
            }
            else if (s2.symbolsArr == null)
            {
                return false;
            }
            else
            {
                for (int i = 0; i < s1.symbolsArr.Length; i++)
                {
                    bool isIn = false;
                    for (int k = 0; k < s2.symbolsArr.Length; k++)
                    {
                        if (s1.symbolsArr[i] == s2.symbolsArr[k])
                        {
                            isIn = true;
                            break;
                        }
                    }
                    if (!isIn)
                    {
                        return false;
                    }
                }
                return true;
            }
        }

        public static bool operator !=(PlentyOfSymbols s1, PlentyOfSymbols s2)
        {
            if (s1.symbolsArr == null && s2.symbolsArr == null)
            {
                return true;
            }
            else if (s1.symbolsArr == null)
            {
                return false;
            }
            else if (s2.symbolsArr == null)
            {
                return false;
            }
            else
            {
                for (int i = 0; i < s1.symbolsArr.Length; i++)
                {

                    if (s1.symbolsArr[i] != s2.symbolsArr[i])
                    {
                        return true;
                    }

                }
                return false;
            }
        }

        public char this[int index]
        {
            get
            {
                if (symbolsArr == null || index < 0 || index >= symbolsArr.Length)
                {
                    throw new IndexOutOfRangeException();
                } else 
                {
                    return symbolsArr[index];
                }
            }
            set
            {

                if (symbolsArr == null || index < 0 || index >= symbolsArr.Length)
                {
                    throw new IndexOutOfRangeException();
                }
                else
                {
                    symbolsArr[index] = value;
                }
            }
        }

        public static implicit operator string(PlentyOfSymbols symbols)
        {
            string str = "";
            if (symbols.symbolsArr != null)
            {
                for (int i = 0; i < symbols.symbolsArr.Length; i++)
                {
                    str += symbols.symbolsArr[i];
                }
            }
            return str;
        }

        public static explicit operator PlentyOfSymbols(string str)
        {
            char[] symbolsArray= new char[str.Length];
            for (int i = 0; i < str.Length; i++)
            {
                symbolsArray[i] = str[i];
            }
            return new PlentyOfSymbols(symbolsArray);
        }

        public override bool Equals(object? obj)
        {
            return this == (PlentyOfSymbols)obj!;
        }

        public override int GetHashCode()
        {
            return base.GetHashCode();
        }
    }
}
