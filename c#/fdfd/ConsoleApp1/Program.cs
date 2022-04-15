using System;
using System.Reflection;
public class CheckStatus : Attribute
{
    private bool Val = false;
    public bool status
    {
        get { return Val; }
    }
    public CheckStatus(bool val)
    {
        Val = val;
    }
}
[CheckStatus(false)]
public class test
{
    private string EmpName;
    private string Country;
    public test(string name, string country)
    {
        this.EmpName = name;
        this.Country = country;
    }
    public string FullDetails()
    {
        string str = null;
        Type type = this.GetType();
        CheckStatus[] attrib =
           (CheckStatus[])type.GetCustomAttributes(typeof(CheckStatus), false);
        if (attrib[0].status == true)
        {
            str = EmpName + "-" + Country;
        }
        else
        {
            str = "Hi " + EmpName;
        }
        return str;
    }
}
class Program
{
    static void Main(string[] args)
    {
        test obj = new test("Vidya Vrat", "India");
        Console.WriteLine("Result:{0}", obj.FullDetails());
        Console.ReadKey();
    }
}