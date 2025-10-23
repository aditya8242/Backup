// using lambda

@FunctionalInterface
interface MyInterface
{
	int cube(int n);
}

class FuncInterface
{
	public static void main(String A[])
	{
		MyInterface p = n -> { return n*n*n; };
		int res = p.cube(3);
		System.out.println(res);
	}
}