using System;
namespace some_test{
    public class Student{
        public Student Info(){
            Console.Write("Hello ");
            return this; //return class for nesting
        }
        public Student Name(string name){
            Console.Write($"{name}");
            return this;
        }
    }
    public class Program{
        public static void Main(){
            Student student1 = new Student();
            student1.Info().Name("Bronstein");
        }
    }
}