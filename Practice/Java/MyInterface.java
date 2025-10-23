@FunctionalInterface
interface CubeInterface {
    int cube(int n);
}

class Demo implements CubeInterface {
    public int cube(int n) {
        return n * n * n;
    }
}

public class MyInterface {
    public static void main(String[] args) {
        CubeInterface pobj = new Demo();
		CubeInterface pobj1 = n -> int cube(n);
        System.out.println(pobj.cube(3));  // Output: 27
    }
}
