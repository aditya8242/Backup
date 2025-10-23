final class Base
{
    void display()
    {
        System.out.println("Inside base display");
    }
}

class Derived
{
    Base bobj = new Base();
}

class Composition
{
    public static void main(String a[])
    {
        Derived dobj = new Derived();
        dobj.bobj.display();
    }
}