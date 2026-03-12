public class Array {
    public static void main(String[] args) {
        int[] arr1 = new int[]{11, 22, 33, 44};
        int[] arr2 = {11, 22, 33, 44};
        
        int num = arr1[0];
        System.out.println(num);
        System.out.println(arr2[0]);
        System.out.println("\n");

        int length = arr1.length;
        System.out.println(length);
        System.out.println("\n");
        // 快捷方式：`数组名.fori`
        for (int i = 0; i < length; i++){
            System.out.println(arr1[i]);
        }
        
    }
}
