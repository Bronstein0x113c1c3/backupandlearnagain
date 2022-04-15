using System;
//well, just a funny comparasion between students (old paradigm), please don't angry :>>
namespace ConsoleApp1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Students std1 = new Students("A1", "Bronstein", 3.2M);
            Students std2 = new Students("A1", "Jonathan", 3.4M);
            Console.WriteLine(Students.Comparable(std1, std2));
        }
    }
    class Students
    {
        private string id;
        private string name;
        private decimal gpa;
        public decimal Gpa
        {
            get { return gpa; }
            set
            {
                gpa = value;
            }
        }
        public string Name
        {
            get { return name; }
            set {
                name = value; 
            }
        }
        public string Id
        {
            get { return id;}
            set
            {
                id = value;
            }
        }
        public Students(string id, string name, decimal gpa) //constructor :>>>
        {
            this.Id = id;
            this.Name = name;
            this.Gpa = gpa;
        } 
        public static string Comparable(Students std1, Students std2)
        {
            if (std1.Gpa == std2.Gpa)
            {
                return "They have the same ability to learn";
            }
            else
            {
                if (std1.Gpa< std2.Gpa)
                {
                    return std2.Name + " has a better ability to learn than "+std1.Name;
                }
                else
                {
                    return std1.Name + " has a better ability to learn than " + std2.Name;
                }
            }
        }
        
      
    }
}
