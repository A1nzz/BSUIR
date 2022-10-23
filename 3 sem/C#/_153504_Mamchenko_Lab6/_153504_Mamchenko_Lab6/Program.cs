using System.Reflection;
using _153504_Mamchenko_Lab6.Entities;

namespace _153504_Mamchenko_Lab6
{
    class Program
    {
        static void Main(string[] args)
        {

            List<Employee> list = new List<Employee>();
            list.Add(new Employee("Kirill", 2000, true));
            list.Add(new Employee("Pavel", 2100, true));
            list.Add(new Employee("Alex", 3000, false));
            list.Add(new Employee("Serg", 2500, true));
            list.Add(new Employee("Igor", 1700, false));

            Assembly assembly = Assembly.LoadFrom("FileLib.dll");
            Type? type = assembly.GetType("FileLib.FileService`1")?.MakeGenericType(typeof(Employee));
            
            if(type != null)
            {
                object instance = Activator.CreateInstance(type);

                MethodInfo? read = type.GetMethod("ReadFile");
                MethodInfo? save = type.GetMethod("SaveData");

                save?.Invoke(instance, new object[] { list, "data.json" });
                read?.Invoke(instance, new object[] { "data.json" });

                foreach (var item in list)
                {
                    Console.WriteLine($"{item.Name} {item.Salary} {item.IsFree}");
                }
            } 
            else
            {
                Console.WriteLine("Невозможнополучить тип(null)");
            }
        }
    }
}