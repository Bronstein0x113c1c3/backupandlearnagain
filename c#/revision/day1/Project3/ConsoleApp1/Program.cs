using System;
//practice using operator and classes in c# (complex number)!
namespace ConsoleApp1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            ComplexNumber number1 = new ComplexNumber(3, 4);
            ComplexNumber number2 = new ComplexNumber(5, 6);
            ComplexNumber.WriteLine(number1 + number2); 
        }
    }
    class ComplexNumber
    {
        public ComplexNumber(int real, int img)
        {
            this.Realvalue = real;
            this.Imagvalue = img;
            
        }
        private int _realvalue;
        private int _imagvalue;
        public int Realvalue
        {
            get { return _realvalue; }
            set { _realvalue = value; }
        }
        public int Imagvalue
        {
            get { return _imagvalue; }
            set { _imagvalue = value; }
        }
        public static ComplexNumber operator +(ComplexNumber number1, ComplexNumber number2)
        {
            return new ComplexNumber(number1.Realvalue + number2.Realvalue, number1.Imagvalue + number2.Imagvalue);
        }
        public static void WriteLine(ComplexNumber number)
        {
            Console.WriteLine((number._realvalue, number._imagvalue).ToString());
        }
    }
}
